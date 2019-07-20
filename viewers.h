#ifndef VIEWERS_H
#define VIEWERS_H

#include <QMainWindow>
#include <QObject>

#include <QGridLayout>
#include <QVTKOpenGLWidget.h>
#include <QRect>

class Viewers:public QWidget {
    Q_OBJECT
public:
    explicit Viewers(QWidget *parent = nullptr);

    QGridLayout *gridLayout;
    QVTKOpenGLWidget *view2;
    QVTKOpenGLWidget *view4;
    QVTKOpenGLWidget *view3;
    QVTKOpenGLWidget *view1;

signals:

public slots:
};

#endif // VIEWERS_H
