#include "vtkimageinteractioncallback.h"

vtkImageInteractionCallback *vtkImageInteractionCallback::New() {
    return new vtkImageInteractionCallback;
}

vtkImageInteractionCallback::vtkImageInteractionCallback() {
    //    std::cout << __LINE__ << "," << __FUNCTION__ << std::endl;
    this->Slicing        = 0;
    this->ImageReslice   = 0;
    this->Interactor     = 0;
    this->view           = 0;
    this->enlargedView_1 = 0;
    this->enlargedView_2 = 0;
    this->enlargedView_3 = 0;
    this->enlargedView_4 = 0;
    this->mutex_id       = 0;
}

void vtkImageInteractionCallback::SetImageReslice(vtkImageReslice *reslice) {
    this->ImageReslice = reslice;
}

void vtkImageInteractionCallback::SetImageMapToColors(
    vtkImageMapToColors *mapToColors) {
    this->mapToColors = mapToColors;
}

vtkImageReslice *vtkImageInteractionCallback::GetImageReslice() {
    return this->ImageReslice;
}

void vtkImageInteractionCallback::SetInteractor(
    vtkRenderWindowInteractor *interactor) {
    this->Interactor = interactor;
}

vtkRenderWindowInteractor *vtkImageInteractionCallback::GetInteractor() {
    return this->Interactor;
}

void vtkImageInteractionCallback::SetImageViewer(Viewers *view) {
    this->view = view;
}

Viewers *vtkImageInteractionCallback::GetImageViewer() { return this->view; }

void vtkImageInteractionCallback::Execute(vtkObject *, unsigned long event,
                                          void *) {
    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        this->GetInteractor();
    int lastPos[2];
    interactor->GetLastEventPosition(lastPos);
    int currPos[2];
    interactor->GetEventPosition(currPos);
    //    std::cout << __LINE__ << "," << __FUNCTION__ << std::endl;
    // deal with four planes' enplansion
    if (event == vtkCommand::KeyPressEvent) {
        char ch = interactor->GetKeyCode();
        keyPressEvent(ch);
    } else if (event == vtkCommand::LeftButtonPressEvent) {
        this->Slicing = 1;
        //        std::cout<<"hah"<<std::endl;
    } else if (event == vtkCommand::LeftButtonReleaseEvent) {
        this->Slicing = 0;
    } else if (event == vtkCommand::MouseMoveEvent) {
        if (this->Slicing) {
            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            vtkImageReslice *reslice = this->ImageReslice;
            // Increment slice position by deltaY of mouse
            int deltaY = lastPos[1] - currPos[1];

            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl; std::cout << "reslice:" << reslice <<
            //            std::endl;
            reslice->Update();

            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            double sliceSpacing = reslice->GetOutput()->GetSpacing()[2];
            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            vtkMatrix4x4 *matrix = reslice->GetResliceAxes();
            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            // move the center point that we are slicing through
            double point[4];
            double center[4];
            point[0] = 0.0;
            point[1] = 0.0;
            point[2] = sliceSpacing * deltaY;
            point[3] = 1.0;
            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            matrix->MultiplyPoint(point, center);
            matrix->SetElement(0, 3, center[0]);
            matrix->SetElement(1, 3, center[1]);
            matrix->SetElement(2, 3, center[2]);
            mapToColors->Update();
            interactor->Render();
            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
        } else {
            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            vtkSmartPointer<vtkInteractorStyle> style =
                vtkInteractorStyle::SafeDownCast(
                    interactor->GetInteractorStyle());

            //            std::cout << __LINE__ << "," << __FUNCTION__ <<
            //            std::endl;
            if (style) {
                style->OnMouseMove();
            }
        }
    }
}

void vtkImageInteractionCallback::keyPressEvent(char ch) {
    // Maintaining continuity
    if (ch != '1' && ch != '2' && ch != '3' && ch != '4') {
        reSetViewParameter();
    } else {
        // Ready to expand
        if (mutex_id == 0) {
            std::cout << __LINE__ << ": " << __FUNCTION__ << std::endl;
            if (ch == '1' && enlargedView_1 == false) {
                enlargedView_1 = true;
            } else if (ch == '1' && enlargedView_1) {
                mutex_id       = 1;
                enlargedView_1 = false;
            }
            if (ch == '2' && enlargedView_2 == false) {
                enlargedView_2 = true;
            } else if (ch == '2' && enlargedView_2) {
                mutex_id       = 2;
                enlargedView_2 = false;
            }
            if (ch == '3' && enlargedView_3 == false) {
                enlargedView_3 = true;
            } else if (ch == '3' && enlargedView_3) {
                mutex_id       = 3;
                enlargedView_3 = false;
            }
            if (ch == '4' && enlargedView_4 == false) {
                enlargedView_4 = true;
            } else if (ch == '4' && enlargedView_4) {
                mutex_id       = 4;
                enlargedView_4 = false;
            }
            std::cout << "ch " << ch << std::endl;
            std::cout << "mutex_id " << mutex_id << std::endl;
        }
        // Starting to shrink
        else if (mutex_id == 1) {
            if (ch == '1' && enlargedView_1 == false) {
                enlargedView_1 = true;
            } else if (ch == '1' && enlargedView_1) {
                mutex_id       = 0;
                enlargedView_1 = false;
            }
            std::cout << "ch " << ch << std::endl;
            std::cout << "mutex_id " << mutex_id << std::endl;
        } else if (mutex_id == 2) {
            if (ch == '2' && enlargedView_2 == false) {
                enlargedView_2 = true;
            } else if (ch == '2' && enlargedView_2) {
                mutex_id       = 0;
                enlargedView_2 = false;
            }
            std::cout << "ch " << ch << std::endl;
            std::cout << "mutex_id " << mutex_id << std::endl;
        } else if (mutex_id == 3) {
            if (ch == '3' && enlargedView_3 == false) {
                enlargedView_3 = true;
            } else if (ch == '3' && enlargedView_3) {
                mutex_id       = 0;
                enlargedView_3 = false;
            }
            std::cout << "ch " << ch << std::endl;
            std::cout << "mutex_id " << mutex_id << std::endl;
        } else if (mutex_id == 4) {
            if (ch == '4' && enlargedView_4 == false) {
                enlargedView_4 = true;
            } else if (ch == '4' && enlargedView_4) {
                mutex_id       = 0;
                enlargedView_4 = false;
            }
            std::cout << "ch " << ch << std::endl;
            std::cout << "mutex_id " << mutex_id << std::endl;
        }
    }
    if (this->mutex_id == 0) {
        this->view->view1->resize(412,384);
        this->view->view2->resize(412,384);
        this->view->view3->resize(412,384);
        this->view->view4->resize(412,384);
        this->view->view1->setVisible(true);
        this->view->view2->setVisible(true);
        this->view->view3->setVisible(true);
        this->view->view4->setVisible(true);
    }
    else if (this->mutex_id == 1) {
        this->view->view1->resize(824, 768);
        this->view->view2->setVisible(false);
        this->view->view3->setVisible(false);
        this->view->view4->setVisible(false);
    }
    else if (this->mutex_id == 2) {
        this->view->view2->resize(824, 768);
        this->view->view1->setVisible(false);
        this->view->view3->setVisible(false);
        this->view->view4->setVisible(false);
    }
    else if (this->mutex_id == 3) {
        this->view->view3->resize(824, 768);
        this->view->view1->setVisible(false);
        this->view->view2->setVisible(false);
        this->view->view4->setVisible(false);
    }
    else if (this->mutex_id == 4) {
        this->view->view4->resize(824, 768);
        this->view->view1->setVisible(false);
        this->view->view2->setVisible(false);
        this->view->view3->setVisible(false);
    }
}

void vtkImageInteractionCallback::reSetViewParameter() {
    this->enlargedView_1 = 0;
    this->enlargedView_2 = 0;
    this->enlargedView_3 = 0;
    this->enlargedView_4 = 0;
}
