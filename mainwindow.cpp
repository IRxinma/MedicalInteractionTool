#include "mainwindow.h"

#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
VTK_MODULE_INIT(vtkRenderingFreeType);

#include "QMessageBox"
#include "dcmformatconversion.h"
#include "folderandfileoperationscollection.h"
#include "mycontrolpanel.h"
#include "tips.h"
#include "viewers.h"
#include "vtkDICOMImageReader.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkImageViewer2.h"
#include "vtkimageinteractioncallback.h"
#include <QDockWidget>
//------------------------------------------------------------------------------------
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

#include "stdio.h"
#include "string.h"
//----------------------------------------------------------------------------------------
// in direct to the read and write(2png) about Dicom
static FolderAndFileOperationsCollection dicom_pre, dicom_behind;

MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent) { setupUi(); }

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    this->resize(1024, 768);
    creatrFileActions();
    QPointer<Viewers> view = new Viewers();
    std::cout << "view1 = " << view << std::endl;
    this->setCentralWidget(view);
    //        view->showAll(dicom_pre.folder_path);
    QPointer<myControlPanel> myDock = new myControlPanel();
    this->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, myDock);
}

void MainWindow::creatrFileActions() {
    menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    menuFiles = new QMenu(menuBar);
    menuFiles->setTitle(QString::fromUtf8("Files"));

    menuDicom = new QMenu(menuFiles);
    menuDicom->setTitle(QString::fromUtf8("Dicom"));
    menuStl = new QMenu(menuFiles);
    menuStl->setTitle(QString::fromUtf8("Stl"));

    actionOpenDicomsPath = new QAction(this);
    actionOpenDicomsPath->setText(QString::fromUtf8("OpenDicomsFolder"));
    actionOpenDicomsPath->setStatusTip(
        QString::fromUtf8("Open one Dicoms' Folder"));
    connect(this->actionOpenDicomsPath, SIGNAL(triggered()), this,
            SLOT(onOpenDicomFolderSlot()));
    //#include "stdio.h"
    actionWritePngPath = new QAction(this);
    actionWritePngPath->setText(QString::fromUtf8("WritePngFolder"));
    actionWritePngPath->setStatusTip(
        QString::fromUtf8("Write one Pngs' Folder"));
    connect(this->actionWritePngPath, SIGNAL(triggered()), this,
            SLOT(onWriteDicom2PngSlot()));

    actionOpenStlPath = new QAction(this);
    actionOpenStlPath->setText(QString::fromUtf8("OpenStlFile"));

    actionSaveStlPath = new QAction(this);
    actionSaveStlPath->setText(QString::fromUtf8("SaveStlFile"));

    menuDicom->addAction(actionOpenDicomsPath);
    menuDicom->addAction(actionWritePngPath);

    menuStl->addAction(actionOpenStlPath);
    menuStl->addAction(actionSaveStlPath);

    menuFiles->addMenu(menuDicom);
    menuFiles->addMenu(menuStl);

    menuBar->addMenu(menuFiles);

    menuBar->setGeometry(QRect(0, 0, this->width(), 30));
}

void MainWindow::onOpenDicomFolderSlot() {
    // 1.Get Folder path
    QString folder_path = QFileDialog::getExistingDirectory(
        this, tr("Open Dicom Folder"), "/home/jlu_wx",
        QFileDialog::ShowDirsOnly);
    strcpy(dicom_pre.folder_path, folder_path.toStdString().c_str());
    //    qDebug() << "Dicom Folder: " << dicom_pre.folder_path;
    // 2.Get file name and the number of dicom file
    dicom_pre.ReadNumOfFilesNameInTheReadFolder(folder_path.toStdString(),
                                                ".dcm");
    QPointer<Viewers> view = (Viewers*)this->centralWidget();
    view->showAll(dicom_pre.folder_path);
}

void MainWindow::onWriteDicom2PngSlot() {
    // 1.Get Folder path
    QString folder_path = QFileDialog::getExistingDirectory(
        this, tr("Open the PNG path to be written"), "/home/jlu_wx",
        QFileDialog::ShowDirsOnly);

    // 2.Png data preparation
    //    FolderAndFileOperationsCollection dicom_behind;
    dicom_behind.ReadNumOfFilesNameInTheReadFolder(folder_path.toStdString(),
                                                   ".png");
    /*
    Here we need to make a judgment: is there a PNG file in the triggered
    folder?
    If yes, the representative wants to show the whole folder's picture (four
    views); no, we need to do dicm2png first, and then show it.
    */

    if (dicom_behind.count == 0) {
        // 3.convert and write
        for (int i = 0; i < dicom_pre.count; i++) {
            std::string writeCompleteFilePath = folder_path.toStdString() + "/";
            // Get the first half of the string, Excluding suffixes
            writeCompleteFilePath += [](std::string tmp) -> std::string {
                tmp = tmp.substr(tmp.find_last_of("/") + 1,
                                 tmp.find_last_of(".") - tmp.find_last_of("/") -
                                     1);
                return tmp;
            }(dicom_pre.SingleFileName_list[i]) + ".png";
            // deal with convertion
            DcmFormatConversion::ConvertDcm2Png(dicom_pre.Completefile_list[i],
                                                writeCompleteFilePath);
        }
    }

    // 4. Trigger Interface Display (Four Views)!!!
    // The next job is only dealing with png.
    dicom_behind.ReadNumOfFilesNameInTheReadFolder(folder_path.toStdString(),
                                                   ".png");
    Tips::ejectTips(std::to_string(dicom_behind.count));
}
