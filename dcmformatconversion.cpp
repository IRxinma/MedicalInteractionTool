#include "dcmformatconversion.h"
#include <iostream>

#include "itkGDCMImageIO.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkPNGImageIO.h"

DcmFormatConversion::DcmFormatConversion() {}

bool DcmFormatConversion::ConvertDcm2Png(std::string readPath,
                                         std::string writePath) {

    // check The path is or not correction
    if (readPath.substr(readPath.find_last_of("/") + 1,
                        readPath.find_last_of(".") -
                            readPath.find_last_of("/") - 1) ==
        writePath.substr(writePath.find_last_of("/") + 1,
                         writePath.find_last_of(".") -
                             writePath.find_last_of("/") - 1)) {

        typedef unsigned char PixelType;
        typedef double dbPixelType;
        const unsigned int Dimension = 2;
        typedef itk::Image<PixelType, Dimension> ImageType;
        typedef itk::Image<dbPixelType, Dimension> dbImageType;

        typedef itk::ImageFileReader<ImageType> ReaderType;
        typedef itk::ImageFileReader<dbImageType> dbReaderType;
        dbReaderType::Pointer reader = dbReaderType::New();
        reader->SetFileName(readPath);

        typedef itk::GDCMImageIO ImageIOTypeInput;
        ImageIOTypeInput::Pointer gdcmImageIO = ImageIOTypeInput::New();
        reader->SetImageIO(gdcmImageIO);

        try {
            reader->Update();
        } catch (itk::ExceptionObject &err) {
            std::cerr << "ExceptionObject caught !" << std::endl;
            std::cerr << err << std::endl;
            return EXIT_FAILURE;
        }

        // https://blog.csdn.net/rabbitbride/article/details/71746309#commentBox
        ImageType::Pointer mask_data        = ImageType::New();
        dbImageType::Pointer image_data     = reader->GetOutput();
        ImageType::PointType origin_temp    = image_data->GetOrigin();
        ImageType::SpacingType spacing_temp = image_data->GetSpacing();
        ImageType::RegionType inputRegion =
            image_data->GetLargestPossibleRegion();
        ImageType::SizeType size   = inputRegion.GetSize();
        ImageType::IndexType start = inputRegion.GetIndex();
        mask_data->SetOrigin(origin_temp);
        mask_data->SetSpacing(spacing_temp);
        mask_data->SetRegions(inputRegion);
        mask_data->Allocate();
        mask_data->FillBuffer(itk::NumericTraits<PixelType>::Zero);
        //    mask_data->Graft(image_data);
        //    mask_data = image_data;

        for (int j = 0; j < size[1]; j++) {
            for (int i = 0; i < size[0]; i++) {
                ImageType::IndexType point_temp;
                point_temp[0]                = i;
                point_temp[1]                = j;
                dbImageType::PixelType value = image_data->GetPixel(point_temp);
                //            std::cout << "Pre = " << value << std::endl;
                if (value < 200)
                    value = 200;
                if (value > 1600)
                    value = 1600;
                ThresholdProcessing(value);
                //            std::cout << "behind = " << value << std::endl;
                //            return 0;
                mask_data->SetPixel(point_temp, (unsigned char)value);
            }
        }
        //--------------------------------operations-----------------------------------------
        typedef itk::ImageFileWriter<ImageType> WriterType;
        WriterType::Pointer writer = WriterType::New();
        writer->SetFileName(writePath);
        writer->SetInput(mask_data);

        typedef itk::PNGImageIO ImageIOTypeOutput;
        ImageIOTypeOutput::Pointer pngImageIO = ImageIOTypeOutput::New();
        writer->SetImageIO(pngImageIO);

        try {
            writer->Update();
        } catch (itk::ExceptionObject &err) {
            std::cerr << "ExceptionObject caught !" << endl;
            std::cerr << err << std::endl;
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;

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

void DcmFormatConversion::ThresholdProcessing(double &val)
{
    double lowVal  = 200;
    double highVal = 1600;
    val            = (val - lowVal) / (highVal - lowVal);
    val *= 255.0;
}
