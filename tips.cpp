#include "tips.h"

Tips::Tips(QWidget *parent) : QMainWindow(parent) {}

void Tips::ejectTips(std::string str) {
    QMessageBox message(QMessageBox::NoIcon, "Tip",
                        "xinma tells: \n the count are " +
                            QString::fromStdString(str));
    message.setIconPixmap(QPixmap("xinma.jpg"));
    QFont font;
    font.setPixelSize(18);
    message.setFont(font);
    message.setMinimumSize(200, 200);
    message.exec();
}
