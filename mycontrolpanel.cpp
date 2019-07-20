#include "mycontrolpanel.h"

myControlPanel::myControlPanel(QDockWidget *parent) : QDockWidget(parent) {
    MyWidget *setDockSize = new MyWidget();
    this->setWidget(setDockSize);
}
