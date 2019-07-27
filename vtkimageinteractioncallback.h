#ifndef VTKIMAGEINTERACTIONCALLBACK_H
#define VTKIMAGEINTERACTIONCALLBACK_H

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

#include <vtkDICOMImageReader.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include "viewers.h"
#include <QPointer>
#include "vtkSmartPointer.h"

class vtkImageInteractionCallback : public vtkCommand {
public:
    static vtkImageInteractionCallback *New();

    vtkImageInteractionCallback();

    void SetImageReslice(vtkImageReslice *reslice);

    void SetImageMapToColors(vtkImageMapToColors *mapToColors);

    vtkImageReslice *GetImageReslice();

    void SetInteractor(vtkRenderWindowInteractor *interactor);

    vtkRenderWindowInteractor *GetInteractor();

    void SetImageViewer(Viewers *view);

    Viewers *GetImageViewer();

    virtual void Execute(vtkObject *, unsigned long event, void *);

    void keyPressEvent(char ch);

    void reSetViewParameter();

private:
    bool enlargedView_1, enlargedView_2, enlargedView_3, enlargedView_4;
    int mutex_id;
    int Slicing;
    vtkSmartPointer<vtkImageReslice> ImageReslice;
    vtkSmartPointer<vtkRenderWindowInteractor> Interactor;
    vtkSmartPointer<vtkImageMapToColors> mapToColors;
    // objetive:explansion or narrow
    QPointer<Viewers> view;//Overview
};


#endif // VTKIMAGEINTERACTIONCALLBACK_H
