#ifndef VIEWERS_H
#define VIEWERS_H

#include <QMainWindow>
#include <QObject>

#include <QGridLayout>
#include <QPointer>
#include <QRect>
#include <QVTKOpenGLWidget.h>
#include <vtkCommand.h>
#include <vtkImageActor.h>
#include <vtkImageCast.h>
#include <vtkImageData.h>
#include <vtkImageMapToColors.h>
#include <vtkImageReader2.h>
#include <vtkImageReslice.h>
#include <vtkInteractorStyleImage.h>
#include <vtkLookupTable.h>
#include <vtkMatrix4x4.h>
#include <vtkMetaImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>

#include <vtkDICOMImageReader.h>
class Viewers : public QWidget {
    Q_OBJECT
public:
    explicit Viewers(QWidget *parent = nullptr);

    QPointer<QGridLayout> gridLayout;
    QPointer<QVTKOpenGLWidget> view2;
    QPointer<QVTKOpenGLWidget> view4;
    QPointer<QVTKOpenGLWidget> view3;
    QPointer<QVTKOpenGLWidget> view1;

    void showAll(const char read_Path[]);
    void dataRenderInteractive(
        QPointer<QVTKOpenGLWidget> Selection_View,
        vtkSmartPointer<vtkImageViewer2> viewer,
        vtkSmartPointer<vtkImageMapToColors> colorMap,
        vtkSmartPointer<vtkImageReslice> reslice,
        vtkSmartPointer<vtkInteractorStyleImage> imagestyle);

protected:
    double axialElements[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    double sagittalElements[16] = {0, 0,  -1, 0, 1, 0, 0, 0,
                                   0, -1, 0,  0, 0, 0, 0, 1};
    double coronalElements[16]  = {1, 0,  0, 0, 0, 0, 1, 0,
                                  0, -1, 0, 0, 0, 0, 0, 1};

signals:

public slots:
};

#endif // VIEWERS_H
