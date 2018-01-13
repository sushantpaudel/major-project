#include "preprocessing.h"

#include <QPixmap>

PreProcessing::PreProcessing()
{

}

QImage PreProcessing::convertToGrayScale(QImage image)
{
    for (int ii = 0; ii < image.height(); ii++) {
        uchar* scan = image.scanLine(ii);
        int depth =4;
        for (int jj = 0; jj < image.width(); jj++) {
            QRgb* rgbpixel = reinterpret_cast<QRgb*>(scan + jj*depth);
            int gray = qGray(*rgbpixel);
            *rgbpixel = QColor(gray, gray, gray).rgba();
        }
    }
    return image;
}

QImage PreProcessing::noiseReduction(QImage image)
{
    return image;
}



