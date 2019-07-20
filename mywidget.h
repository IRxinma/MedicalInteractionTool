#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class MyWidget : public QWidget
{
public:
    QSize sizeHint() const
    {
        return QSize(200, 1024); /* 在这里定义dock的初始大小 */
    }
};
#endif // MYWIDGET_H
