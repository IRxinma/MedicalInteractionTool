#ifndef MYCONTROLPANEL_H
#define MYCONTROLPANEL_H

#include "mywidget.h"
#include <QDockWidget>
class myControlPanel : public QDockWidget {
    Q_OBJECT
public:
    explicit myControlPanel(QDockWidget *parent = nullptr);

signals:

public slots:
};

#endif // MYCONTROLPANEL_H
