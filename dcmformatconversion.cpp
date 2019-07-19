#include "dcmformatconversion.h"
#include <iostream>

DcmFormatConversion::DcmFormatConversion() {}

void DcmFormatConversion::ConvertDcm2Png(std::string readPath,
                                         std::string writePath) {

    if (readPath.substr(readPath.find_last_of("/") + 1,
                        readPath.find_last_of(".") -
                            readPath.find_last_of("/") - 1) ==
        writePath.substr(writePath.find_last_of("/") + 1,
                         writePath.find_last_of(".") -
                             writePath.find_last_of("/") - 1)) {

        vtkSmartPointer<vtkDICOMImageReader> dcmReader =
            vtkSmartPointer<vtkDICOMImageReader>::New();
        dcmReader->SetFileName(readPath.c_str());
//        dcmReader->Update();

        int width = dcmReader->GetWidth();
        int height = dcmReader->GetHeight();
        int NumOfCom = dcmReader->GetNumberOfComponents();
//        dcmReader->GetImagePositionPatient()

        double *xyz = dcmReader->GetPixelSpacing();

        std::cout<<width<<std::endl;
        std::cout<<height<<std::endl;
        std::cout<<NumOfCom<<std::endl;
        std::cout<<xyz[0]<<"..."<<xyz[1]<<"..."<<xyz[2]<<std::endl;
        //        for (int i=0; i<width;i++) {

//            for (int j=0;j<height;j++) {
//                unsigned char * pixl =
//            }
//        }


//        vtkSmartPointer<vtkPNGWriter> pngWriter =
//            vtkSmartPointer<vtkPNGWriter>::New();
//        pngWriter->SetFileName(writePath.c_str());
//        pngWriter->SetInputConnection(dcmReader->GetOutputPort());
//        pngWriter->Write();

    } else {
        std::cout << readPath.substr(readPath.find_last_of("/") + 1,
                                     readPath.find_last_of(".") -
                                         readPath.find_last_of("/") - 1)
                  << std::endl;

        std::cout << writePath.substr(writePath.find_last_of("/") + 1,
                                      writePath.find_last_of(".") -
                                          writePath.find_last_of("/") - 1)
                  << std::endl;

        qDebug() << "read file path doesn't match write file path";
    }
}
