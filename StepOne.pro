#-------------------------------------------------
#
# Project created by QtCreator 2019-07-17T21:31:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StepOne
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        dcmformatconversion.cpp \
        folderandfileoperationscollection.cpp \
        main.cpp \
        mainwindow.cpp \
        mycontrolpanel.cpp \
        tips.cpp \
        viewers.cpp \
        vtkimageinteractioncallback.cpp

HEADERS += \
        dcmformatconversion.h \
        folderandfileoperationscollection.h \
        mainwindow.h \
        mycontrolpanel.h \
        mywidget.h \
        tips.h \
        viewers.h \
        vtkimageinteractioncallback.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# /home/wx/projects/VTK-Release/include/vtk-8.90
INCLUDEPATH += /home/jlu_wx/projects/opencv-3.4/include
LIBS += -L/home/jlu_wx/projects/opencv-3.4/lib/ \
-lopencv_calib3d \
-lopencv_core \
-lopencv_dnn \
-lopencv_features2d \
-lopencv_flann \
#-lopencv_gapi \
-lopencv_highgui \
-lopencv_imgproc \
-lopencv_imgcodecs \
-lopencv_objdetect \
-lopencv_photo \
-lopencv_video \
-lopencv_videoio \
-lopencv_stitching

#----------------------------add VTK envirenment-----------------------------
INCLUDEPATH += /home/jlu_wx/projects/VTK-8.1.0-Release/include \
/home/jlu_wx/projects/VTK-8.1.0-Release/include/vtk-8.1
LIBS += -L/home/jlu_wx/projects/VTK-8.1.0-Release/lib \
-lvtkalglib-8.1 \
-lvtkChartsCore-8.1 \
-lvtkCommonColor-8.1 \
-lvtkCommonComputationalGeometry-8.1 \
-lvtkCommonCore-8.1 \
-lvtkCommonDataModel-8.1 \
-lvtkCommonExecutionModel-8.1 \
-lvtkCommonMath-8.1 \
-lvtkCommonMisc-8.1 \
-lvtkCommonSystem-8.1 \
-lvtkCommonTransforms-8.1 \
-lvtkDICOMParser-8.1 \
-lvtkDomainsChemistry-8.1 \
-lvtkDomainsChemistryOpenGL2-8.1 \
-lvtkexoIIc-8.1 \
-lvtkexpat-8.1 \
-lvtkFiltersAMR-8.1 \
-lvtkFiltersCore-8.1 \
-lvtkFiltersExtraction-8.1 \
-lvtkFiltersFlowPaths-8.1 \
-lvtkFiltersGeneral-8.1 \
-lvtkFiltersGeneric-8.1 \
-lvtkFiltersGeometry-8.1 \
-lvtkFiltersHybrid-8.1 \
-lvtkFiltersHyperTree-8.1 \
-lvtkFiltersImaging-8.1 \
-lvtkFiltersModeling-8.1 \
-lvtkFiltersParallel-8.1 \
-lvtkFiltersParallelImaging-8.1 \
-lvtkFiltersPoints-8.1 \
-lvtkFiltersProgrammable-8.1 \
-lvtkFiltersSelection-8.1 \
-lvtkFiltersSMP-8.1 \
-lvtkFiltersSources-8.1 \
-lvtkFiltersStatistics-8.1 \
-lvtkFiltersTexture-8.1 \
-lvtkFiltersTopology-8.1 \
-lvtkFiltersVerdict-8.1 \
-lvtkfreetype-8.1 \
-lvtkGeovisCore-8.1 \
-lvtkgl2ps-8.1 \
-lvtkglew-8.1 \
-lvtkGUISupportQt-8.1 \
-lvtkGUISupportQtOpenGL-8.1 \
-lvtkGUISupportQtSQL-8.1 \
-lvtkhdf5-8.1 \
-lvtkhdf5_hl-8.1 \
-lvtkImagingColor-8.1 \
-lvtkImagingCore-8.1 \
-lvtkImagingFourier-8.1 \
-lvtkImagingGeneral-8.1 \
-lvtkImagingHybrid-8.1 \
-lvtkImagingMath-8.1 \
-lvtkImagingMorphological-8.1 \
-lvtkImagingSources-8.1 \
-lvtkImagingStatistics-8.1 \
-lvtkImagingStencil-8.1 \
-lvtkInfovisCore-8.1 \
-lvtkInfovisLayout-8.1 \
-lvtkInteractionImage-8.1 \
-lvtkInteractionStyle-8.1 \
-lvtkInteractionWidgets-8.1 \
-lvtkIOAMR-8.1 \
-lvtkIOCore-8.1 \
-lvtkIOEnSight-8.1 \
-lvtkIOExodus-8.1 \
-lvtkIOExport-8.1 \
-lvtkIOExportOpenGL2-8.1 \
-lvtkIOGeometry-8.1 \
-lvtkIOImage-8.1 \
-lvtkIOImport-8.1 \
-lvtkIOInfovis-8.1 \
-lvtkIOLegacy-8.1 \
-lvtkIOLSDyna-8.1 \
-lvtkIOMINC-8.1 \
-lvtkIOMovie-8.1 \
-lvtkIONetCDF-8.1 \
-lvtkIOParallel-8.1 \
-lvtkIOParallelXML-8.1 \
-lvtkIOPLY-8.1 \
-lvtkIOSQL-8.1 \
-lvtkIOTecplotTable-8.1 \
-lvtkIOVideo-8.1 \
-lvtkIOXML-8.1 \
-lvtkIOXMLParser-8.1 \
-lvtkjpeg-8.1 \
-lvtkjsoncpp-8.1 \
-lvtklibharu-8.1 \
-lvtklibxml2-8.1 \
-lvtklz4-8.1 \
-lvtkmetaio-8.1 \
-lvtkNetCDF-8.1 \
-lvtknetcdfcpp-8.1 \
-lvtkoggtheora-8.1 \
-lvtkParallelCore-8.1 \
-lvtkpng-8.1 \
-lvtkproj4-8.1 \
-lvtkRenderingAnnotation-8.1 \
-lvtkRenderingContext2D-8.1 \
-lvtkRenderingContextOpenGL2-8.1 \
-lvtkRenderingCore-8.1 \
-lvtkRenderingFreeType-8.1 \
-lvtkRenderingGL2PSOpenGL2-8.1 \
-lvtkRenderingImage-8.1 \
-lvtkRenderingLabel-8.1 \
-lvtkRenderingLOD-8.1 \
-lvtkRenderingOpenGL2-8.1 \
-lvtkRenderingQt-8.1 \
-lvtkRenderingVolume-8.1 \
-lvtkRenderingVolumeOpenGL2-8.1 \
-lvtksqlite-8.1 \
-lvtksys-8.1 \
-lvtktiff-8.1 \
-lvtkverdict-8.1 \
-lvtkViewsContext2D-8.1 \
-lvtkViewsCore-8.1 \
-lvtkViewsInfovis-8.1 \
-lvtkViewsQt-8.1 \
-lvtkzlib-8.1
#----------------------------add VTK envirenment-----------------------------

# ----------------------------add ITK envirenment----------------------------
INCLUDEPATH += /home/jlu_wx/projects/ITK-Release/include/ITK-5.1
LIBS+= -L/home/jlu_wx/projects/ITK-Release/lib \
-lITKBiasCorrection-5.1 \
-lITKCommon-5.1 \
-lITKDICOMParser-5.1 \
-lITKEXPAT-5.1 \
-lITKgiftiio-5.1 \
-lITKIOBioRad-5.1 \
-lITKIOBMP-5.1 \
-lITKIOBruker-5.1 \
-lITKIOCSV-5.1 \
-lITKIOGDCM-5.1 \
-lITKIOGE-5.1 \
-lITKIOGIPL-5.1 \
-lITKIOHDF5-5.1 \
-lITKIOImageBase-5.1 \
-lITKIOIPL-5.1 \
-lITKIOJPEG2000-5.1 \
-lITKIOJPEG-5.1 \
-lITKIOLSM-5.1 \
-lITKIOMeshBase-5.1 \
-lITKIOMeshBYU-5.1 \
-lITKIOMeshFreeSurfer-5.1 \
-lITKIOMeshGifti-5.1 \
-lITKIOMeshOBJ-5.1 \
-lITKIOMeshOFF-5.1 \
-lITKIOMeshVTK-5.1 \
-lITKIOMeta-5.1 \
-lITKIOMINC-5.1 \
-lITKIOMRC-5.1 \
-lITKIONIFTI-5.1 \
-lITKIONRRD-5.1 \
-lITKIOPNG-5.1 \
-lITKIOSiemens-5.1 \
-lITKIOSpatialObjects-5.1 \
-lITKIOStimulate-5.1 \
-lITKIOTIFF-5.1 \
-lITKIOTransformBase-5.1 \
-lITKIOTransformHDF5-5.1 \
-lITKIOTransformInsightLegacy-5.1 \
-lITKIOTransformMatlab-5.1 \
-lITKIOVTK-5.1 \
-lITKIOXML-5.1 \
-lITKKLMRegionGrowing-5.1 \
-lITKLabelMap-5.1 \
-lITKMesh-5.1 \
-lITKMetaIO-5.1 \
-lITKniftiio-5.1 \
-lITKNrrdIO-5.1 \
-lITKOptimizers-5.1 \
-lITKOptimizersv4-5.1 \
-lITKPath-5.1 \
-lITKPolynomials-5.1 \
-lITKQuadEdgeMesh-5.1 \
-lITKSpatialObjects-5.1 \
-lITKStatistics-5.1 \
-lITKTestKernel-5.1 \
-lITKTransform-5.1 \
-lITKTransformFactory-5.1 \
-lITKVideoCore-5.1 \
-lITKVideoIO-5.1 \
-lITKVNLInstantiation-5.1 \
-lITKVTK-5.1 \
-lITKWatersheds-5.1 \
-lITKznz-5.1 \
-litksys-5.1 \
-litkvnl-5.1 \
-lITKIOImageBase-5.1 \
-lITKIOTransformMatlab-5.1 \
-lITKTransform-5.1

LIBS+= -L/home/jlu_wx/projects/ITK-Release/lib \
-litkdouble-conversion-5.1 \
-litkgdcmcharls-5.1 \
-litkgdcmCommon-5.1 \
-litkgdcmDICT-5.1 \
-litkgdcmDSED-5.1 \
-litkgdcmIOD-5.1 \
-litkgdcmjpeg12-5.1 \
-litkgdcmjpeg16-5.1 \
-litkgdcmjpeg8-5.1 \
-litkgdcmMEXD-5.1 \
-litkgdcmMSFF-5.1 \
-litkgdcmopenjp2-5.1 \
-litkgdcmsocketxx-5.1 \
-litkgdcmuuid-5.1 \
-litkhdf5_cpp \
-litkhdf5 \
-litkjpeg-5.1 \
-litklbfgs-5.1 \
-litkminc2-5.1 \
-litknetlib-5.1 \
-litkNetlibSlatec-5.1 \
-litkopenjpeg-5.1 \
-litkpng-5.1 \
-litksys-5.1 \
-litktestlib-5.1 \
-litktiff-5.1 \
-litkv3p_netlib-5.1 \
-litkvcl-5.1 \
-litkvnl-5.1 \
-litkvnl_algo-5.1 \
-litkzlib-5.1
# ----------------------------add ITK envirenment----------------------------

DISTFILES += \
    xinma.jpg
