#ifndef TIPS_H
#define TIPS_H

#include <QMainWindow>
#include <QObject>
#include <QMessageBox>
#include <QString>
#include <string.h>
#include <QPixmap>
#include <QFont>


class Tips : public QMainWindow
{
    Q_OBJECT
public:

    explicit Tips(QWidget *parent = nullptr);

    /*
     * Enter a character and pop up a warning string, debug facility
     */
    static void ejectTips(std::string str);

signals:

public slots:
};

#endif // TIPS_H
