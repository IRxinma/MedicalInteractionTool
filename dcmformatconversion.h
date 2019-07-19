#ifndef DCMFORMATCONVERSION_H
#define DCMFORMATCONVERSION_H

#include <QObject>
#include <QDebug>

#include <vtkDICOMImageReader.h>
#include <vtkPNGWriter.h>
#include <vtkSmartPointer.h>


class DcmFormatConversion:public QObject
{
    Q_OBJECT
public:
    DcmFormatConversion();
    // Responsible for reading DICOM paths, all converted to PNG images
    static void ConvertDcm2Png(std::string readPath, std::string writePath);
};

#endif // DCMFORMATCONVERSION_H
