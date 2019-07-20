#include "viewers.h"

Viewers::Viewers(QWidget *parent) : QWidget(parent) {
    gridLayout = new QGridLayout();
    gridLayout->setContentsMargins(0, 0, 0, 0);

    /*
     * Anti-clockwise
     */

    view2 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view2, 1, 0, 1, 1);

    view4 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view4, 0, 1, 1, 1);

    view3 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view3, 1, 1, 1, 1);

    view1 = new QVTKOpenGLWidget();
    gridLayout->addWidget(view1, 0, 0, 1, 1);

    this->setLayout(gridLayout);
}
