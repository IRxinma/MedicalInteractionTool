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
        tips.cpp \
        viewers.cpp

HEADERS += \
        dcmformatconversion.h \
        folderandfileoperationscollection.h \
        mainwindow.h \
        tips.h \
        viewers.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# /home/wx/projects/VTK-Release/include/vtk-8.90
INCLUDEPATH += /home/jlu_wx/projects/VTK-Release/include/vtk-8.90 \
/home/jlu_wx/projects/opencv-3.4/include/
#               /usr/local/include/OpenMesh

LIBS += -L/home/jlu_wx/projects/VTK-Release/lib/ \
-lvtknetcdf-8.90 \
-lvtklibproj-8.90 \
-lvtkChartsCore-8.90 \
-lvtkCommonColor-8.90 \
-lvtkCommonComputationalGeometry-8.90 \
-lvtkChartsCore-8.90 \
-lvtkCommonColor-8.90 \
-lvtkCommonComputationalGeometry-8.90 \
-lvtkCommonCore-8.90 \
-lvtkCommonDataModel-8.90 \
-lvtkCommonExecutionModel-8.90 \
-lvtkCommonMath-8.90 \
-lvtkCommonMisc-8.90 \
-lvtkCommonSystem-8.90 \
-lvtkCommonTransforms-8.90 \
-lvtkDICOMParser-8.90 \
-lvtkDomainsChemistry-8.90 \
-lvtkdoubleconversion-8.90 \
-lvtkexodusII-8.90 \
-lvtkexpat-8.90 \
-lvtkFiltersAMR-8.90 \
-lvtkFiltersCore-8.90 \
-lvtkFiltersExtraction-8.90 \
-lvtkFiltersFlowPaths-8.90 \
-lvtkFiltersGeneral-8.90 \
-lvtkFiltersGeneric-8.90 \
-lvtkFiltersGeometry-8.90 \
-lvtkFiltersHybrid-8.90 \
-lvtkFiltersHyperTree-8.90 \
-lvtkFiltersImaging-8.90 \
-lvtkFiltersModeling-8.90 \
-lvtkFiltersParallel-8.90 \
-lvtkFiltersParallelImaging-8.90 \
-lvtkFiltersPoints-8.90 \
-lvtkFiltersProgrammable-8.90 \
-lvtkFiltersSelection-8.90 \
-lvtkFiltersSMP-8.90 \
-lvtkFiltersSources-8.90 \
-lvtkFiltersStatistics-8.90 \
-lvtkFiltersTexture-8.90 \
-lvtkFiltersTopology-8.90 \
-lvtkFiltersVerdict-8.90 \
-lvtkfreetype-8.90 \
-lvtkGeovisCore-8.90 \
-lvtkgl2ps-8.90 \
-lvtkglew-8.90 \
-lvtkhdf5-8.90 \
-lvtkhdf5_hl-8.90 \
-lvtkImagingColor-8.90 \
-lvtkImagingCore-8.90 \
-lvtkImagingFourier-8.90 \
-lvtkImagingGeneral-8.90 \
-lvtkImagingHybrid-8.90 \
-lvtkImagingMath-8.90 \
-lvtkImagingMorphological-8.90 \
-lvtkImagingSources-8.90 \
-lvtkImagingStatistics-8.90 \
-lvtkImagingStencil-8.90 \
-lvtkInfovisCore-8.90 \
-lvtkInfovisLayout-8.90 \
-lvtkInteractionImage-8.90 \
-lvtkInteractionStyle-8.90 \
-lvtkInteractionWidgets-8.90 \
-lvtkIOAMR-8.90 \
-lvtkIOAsynchronous-8.90 \
-lvtkIOCore-8.90 \
-lvtkIOEnSight-8.90 \
-lvtkIOExodus-8.90 \
-lvtkIOExport-8.90 \
-lvtkIOExportPDF-8.90 \
-lvtkIOGeometry-8.90 \
-lvtkIOImage-8.90 \
-lvtkIOImport-8.90 \
-lvtkIOInfovis-8.90 \
-lvtkIOLegacy-8.90 \
-lvtkIOLSDyna-8.90 \
-lvtkIOMINC-8.90 \
-lvtkIOMovie-8.90 \
-lvtkIONetCDF-8.90 \
-lvtkIOParallel-8.90 \
-lvtkIOParallelXML-8.90 \
-lvtkIOPLY-8.90 \
-lvtkIOSegY-8.90 \
-lvtkIOSQL-8.90 \
-lvtkIOTecplotTable-8.90 \
-lvtkIOVideo-8.90 \
-lvtkIOXML-8.90 \
-lvtkIOXMLParser-8.90 \
-lvtkjpeg-8.90 \
-lvtkjsoncpp-8.90 \
-lvtklibharu-8.90 \
-lvtklibxml2-8.90 \
-lvtklz4-8.90 \
-lvtkloguru-8.90 \
-lvtklzma-8.90 \
-lvtkmetaio-8.90 \
-lvtkogg-8.90 \
-lvtkParallelCore-8.90 \
-lvtkpng-8.90 \
-lvtkRenderingAnnotation-8.90 \
-lvtkRenderingContext2D-8.90 \
-lvtkRenderingCore-8.90 \
-lvtkRenderingFreeType-8.90 \
-lvtkRenderingGL2PSOpenGL2-8.90 \
-lvtkRenderingImage-8.90 \
-lvtkRenderingLabel-8.90 \
-lvtkRenderingLOD-8.90 \
-lvtkRenderingOpenGL2-8.90 \
-lvtkRenderingVolume-8.90 \
-lvtkRenderingVolumeOpenGL2-8.90 \
-lvtksqlite-8.90 \
-lvtksys-8.90 \
-lvtktheora-8.90 \
-lvtktiff-8.90 \
-lvtkverdict-8.90 \
-lvtkViewsCore-8.90 \
-lvtkViewsInfovis-8.90 \
-lvtkzlib-8.90 \
-L/home/jlu_wx/projects/opencv-3.4/lib/ \
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
-lopencv_stitching \
#-L/usr/local/lib/ \
#-lOpenMeshCore \
#-lOpenMeshTools

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
