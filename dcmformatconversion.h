#ifndef DCMFORMATCONVERSION_H
#define DCMFORMATCONVERSION_H

#include <QObject>
#include <QDebug>

#include "itkGDCMImageIO.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkPNGImageIO.h"

class DcmFormatConversion:public QObject
{
    Q_OBJECT
public:
    DcmFormatConversion();
    // Responsible for reading DICOM paths, all converted to PNG images
    static bool ConvertDcm2Png(std::string readPath, std::string writePath);

//private:
    // deal with the hreshold value
    static void ThresholdProcessing(double &val);
};

#endif // DCMFORMATCONVERSION_H
