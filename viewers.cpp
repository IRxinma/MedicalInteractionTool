#include "viewers.h"
//--------------------------------------------------------------------------------------------
#include "vtkDistanceWidget.h"
#include "vtkImagePlaneWidget.h"
#include "vtkImageSliceMapper.h"
#include "vtkResliceImageViewer.h"
#include "vtkResliceImageViewerMeasurements.h"
#include "vtkSmartPointer.h"
#include <QMainWindow>

#include "algorithm"
#include "string"
#include "string.h"
#include "vtkPNGReader.h"
#include "vtkStdString.h"
#include "vtkStringArray.h"

#include "algorithm"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkImageSeriesReader.h"
#include "itkImageToVTKImageFilter.h"
#include "vtkBoundedPlanePointPlacer.h"
#include "vtkCellPicker.h"
#include "vtkCommand.h"
#include "vtkDICOMImageReader.h"
#include "vtkDistanceRepresentation.h"
#include "vtkDistanceRepresentation2D.h"
#include "vtkDistanceWidget.h"
#include "vtkHandleRepresentation.h"
#include "vtkImageData.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkImageSlabReslice.h"
#include "vtkInteractorStyleImage.h"
#include "vtkLookupTable.h"
#include "vtkPlane.h"
#include "vtkPlaneSource.h"
#include "vtkPointHandleRepresentation2D.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkProperty.h"
#include "vtkResliceCursor.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceImageViewer.h"
#include "vtkResliceImageViewerMeasurements.h"
#include "vtkimageinteractioncallback.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
Viewers::Viewers(QWidget *parent) : QWidget(parent) {
    gridLayout = new QGridLayout();
    gridLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(gridLayout);

    /*
     * Anti-clockwise
     */

    view2 = new QVTKOpenGLWidget();
    //    view2 = new QVTKWidget();
    gridLayout->addWidget(view2, 1, 0, 1, 1);

    //    view4 = new QVTKWidget();
    view4 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view4, 0, 1, 1, 1);

    //    view3 = new QVTKWidget();
    view3 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view3, 1, 1, 1, 1);

    //    view1 = new QVTKWidget();
    view1 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view1, 0, 0, 1, 1);
}

void Viewers::showAll(const char read_Path[]) {
    vtkSmartPointer<vtkDICOMImageReader> reader =
        vtkSmartPointer<vtkDICOMImageReader>::New();
    reader->SetDirectoryName(read_Path);
    reader->Update();

    int extent[6];
    double spacing[3];
    double origin[3];

    reader->GetOutput()->GetExtent(extent);
    reader->GetOutput()->GetSpacing(spacing);
    reader->GetOutput()->GetOrigin(origin);

    double center[3];
    center[0] = origin[0] + spacing[0] * 0.5 * (extent[0] + extent[1]);
    center[1] = origin[1] + spacing[1] * 0.5 * (extent[2] + extent[3]);
    center[2] = origin[2] + spacing[2] * 0.5 * (extent[4] + extent[5]);

    for (int i = 0; i < 3; i++) {
        vtkSmartPointer<vtkMatrix4x4> resliceAxes =
            vtkSmartPointer<vtkMatrix4x4>::New();
        if (i == 0) {
            resliceAxes->DeepCopy(axialElements);
        } else if (i == 1) {
            resliceAxes->DeepCopy(sagittalElements);
        } else {
            resliceAxes->DeepCopy(coronalElements);
        }

        resliceAxes->SetElement(0, 3, center[0]);
        resliceAxes->SetElement(1, 3, center[1]);
        resliceAxes->SetElement(2, 3, center[2]);

        vtkSmartPointer<vtkImageReslice> reslice =
            vtkSmartPointer<vtkImageReslice>::New();
        reslice->SetInputConnection(reader->GetOutputPort());
        reslice->SetOutputDimensionality(2);
        reslice->SetResliceAxes(resliceAxes);
        reslice->SetInterpolationModeToLinear();
        //    reslice->Update();

        vtkSmartPointer<vtkLookupTable> colorTable =
            vtkSmartPointer<vtkLookupTable>::New();
        colorTable->SetNumberOfColors(3);
        colorTable->SetRange(-100, 1600);
        colorTable->SetValueRange(0.0, 1.0);
        colorTable->SetSaturationRange(0.0, 1.0);
        colorTable->SetRampToSCurve();
        colorTable->Build();

        vtkSmartPointer<vtkImageMapToColors> colorMap =
            vtkSmartPointer<vtkImageMapToColors>::New();
        colorMap->SetLookupTable(colorTable);
        colorMap->SetInputConnection(reslice->GetOutputPort());
        colorMap->Update();

        vtkNew<vtkGenericOpenGLRenderWindow> renWin;
        vtkSmartPointer<vtkImageViewer2> viewer =
            vtkSmartPointer<vtkImageViewer2>::New();
        viewer->SetRenderWindow(renWin.Get());

        vtkSmartPointer<vtkInteractorStyleImage> imagestyle =
            vtkSmartPointer<vtkInteractorStyleImage>::New();

        QPointer<QVTKOpenGLWidget> Selection_View;
        if (i == 0)
            Selection_View = this->view1;
        else if (i == 1)
            Selection_View = this->view2;
        else if (i == 2)
            Selection_View = this->view3;

        dataRenderInteractive(Selection_View, viewer, colorMap, reslice,
                              imagestyle);
    }
}

void Viewers::dataRenderInteractive(
    QPointer<QVTKOpenGLWidget> Selection_View,
    vtkSmartPointer<vtkImageViewer2> viewer,
    vtkSmartPointer<vtkImageMapToColors> colorMap,
    vtkSmartPointer<vtkImageReslice> reslice,
    vtkSmartPointer<vtkInteractorStyleImage> imagestyle) {
    Selection_View->SetRenderWindow(viewer->GetRenderWindow());
    viewer->SetInputConnection(colorMap->GetOutputPort());
    //    viewer->SetInputData(colorMap->GetOutput());// this is one pic
    //实例化自定义类
    //    std::cout << __LINE__ << "," << __FUNCTION__ << std::endl;
    vtkSmartPointer<vtkImageInteractionCallback> pCall =
        vtkSmartPointer<vtkImageInteractionCallback>::New();
    pCall->SetImageReslice(reslice);
    //    std::cout << __LINE__ << "," << __FUNCTION__ << std::endl;
    //    pCall->SetInteractor(renderWindowInteractor);
    pCall->SetInteractor(viewer->GetRenderWindow()->GetInteractor());
    pCall->SetImageMapToColors(colorMap);
    pCall->SetImageViewer(this);

    imagestyle->AddObserver(vtkCommand::MouseMoveEvent, pCall);
    imagestyle->AddObserver(vtkCommand::LeftButtonPressEvent, pCall);
    imagestyle->AddObserver(vtkCommand::LeftButtonReleaseEvent, pCall);
    imagestyle->AddObserver(vtkCommand::KeyPressEvent, pCall);

    viewer->SetupInteractor(
        Selection_View->GetRenderWindow()->GetInteractor()); //设置交互方式
    Selection_View->GetInteractor()->SetInteractorStyle(imagestyle);

    viewer->GetRenderer()->ResetCamera();
    Selection_View->GetRenderWindow()->Render();
}
