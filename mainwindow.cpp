#include "mainwindow.h"
#include "folderandfileoperationscollection.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) { setupUi(); }

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    this->resize(1024, 768);
    this->centralWidget();
    creatrFileActions();
}

void MainWindow::creatrFileActions() {
    menuBar = new QMenuBar(this);

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

// in direct to the read and write(2png) about Dicom
static FolderAndFileOperationsCollection dicom_pre, dicom_behind;

void MainWindow::onOpenDicomFolderSlot() {
    // 1.Get Folder path
    QString folder_path = QFileDialog::getExistingDirectory(
        this, tr("Open Dicom Folder"), "/home/jlu_wx",
        QFileDialog::ShowDirsOnly);
    //    qDebug()<<"Dicom Folder: "<<folder_path;

    // 2.Get file name and the number of dicom file
    //    FolderAndFileOperationsCollection dicom_pre;
    dicom_pre.ReadNumOfFilesNameInTheReadFolder(folder_path.toStdString(),
                                                ".dcm");
}

void MainWindow::onWriteDicom2PngSlot() {
    // 1.Get Folder path
    QString folder_path = QFileDialog::getExistingDirectory(
        this, tr("Open the PNG path to be written"), "/home/jlu_wx",
        QFileDialog::ShowDirsOnly);

    //    // 2.Png data preparation
    ////    FolderAndFileOperationsCollection dicom_behind;
    //    dicom_behind.ReadNumOfFilesNameInTheReadFolder(folder_path.toStdString(),
    //                                                   ".png");

    // 3.convert and write
    for (int i = 0; i < dicom_pre.count; i++) {
        std::string writeCompleteFilePath = folder_path.toStdString() + "/";
        writeCompleteFilePath += dicom_pre.SingleFileName_list[i];
        DcmFormatConversion::ConvertDcm2Png(dicom_pre.Completefile_list[i],
                                            writeCompleteFilePath);
    }
}