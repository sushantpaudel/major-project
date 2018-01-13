#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <QPixmap>



class PreProcessing
{
public:
    PreProcessing();
    QImage convertToGrayScale(QImage image);
    QImage noiseReduction(QImage image);
};

#endif // PREPROCESSING_H
