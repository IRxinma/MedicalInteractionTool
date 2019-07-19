#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "QVTKWidget.h"
#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <QFrame>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QScrollBar>
#include <QSlider>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>
#include <QWidget>
#include <QtCore/QVariant>
#include "dcmformatconversion.h"
#include "folderandfileoperationscollection.h"
#include "tips.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QMenuBar *menuBar;


    // build File Menu(Each operation has its own submenu for subsequent
    // extensions)
    QMenu *menuFiles;

    QMenu *menuDicom;
    QAction *actionOpenDicomsPath;
    QAction *actionWritePngPath;

    QMenu *menuStl;
    QAction *actionOpenStlPath;
    QAction *actionSaveStlPath;
    //-------------------------------------------------------------------

protected:
    void setupUi();
    void creatrFileActions();

private slots:
    void onOpenDicomFolderSlot(); // in direct to 'actionOpenDicomsPath'
    void onWriteDicom2PngSlot(); // in direct to 'actionWritePngPath'
};

#endif // MAINWINDOW_H
