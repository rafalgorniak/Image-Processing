#include "C.h"

unsigned int histogramValues[256];
unsigned int imageResolution;

void fillHistogram(CImg<unsigned char> &image, int channel)
{
    imageResolution = image.width() * image.height();
    for (unsigned int &value : histogramValues) {
        value = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++) {
        for (unsigned int y = 0; y < image.height(); y++) {
            histogramValues[image(x, y, channel)]++;
        }
    }
}

double mean(CImg<unsigned char> &image, int channel)
{
    fillHistogram(image, channel);
    double mean = 0;
    for(int i = 0; i < 256; i++)
    {
        mean += histogramValues[i]*i;
    }
    mean /= imageResolution;
    return mean;
}

double variance(CImg<unsigned char> &image, int channel)
{
    double mean_val = mean(image, channel);
    double variance = 0;
    for(int i = 0; i < 256; i++)
    {
        variance += pow(i - mean_val, 2)*histogramValues[i];
    }
    variance /= imageResolution;
    return variance;
}

double deviation(CImg<unsigned char> &image, int channel)
{
    double variance_val = variance(image, channel);
    return pow(variance_val, 0.5);
}

double variationCoefficient(CImg<unsigned char> &image, int channel)
{
    double mean_val = mean(image, channel);
    double deviation_val = deviation(image, channel);
    double coefficient = deviation_val / mean_val;
    return coefficient;
}

double asymmetryCoefficient(CImg<unsigned char> &image, int channel)
{
    double mean_val = mean(image, channel);
    double deviation_val = deviation(image, channel);
    double coefficient = 0;
    for(int i = 0; i < 256; i++)
    {
        coefficient += pow(i - mean_val, 3)*histogramValues[i];
    }
    coefficient /= imageResolution;
    coefficient /= pow(deviation_val, 3);
    return coefficient;
}

double flatteningCoefficient(CImg<unsigned char> &image, int channel)
{
    double mean_val = mean(image, channel);
    double deviation_val = deviation(image, channel);
    double coefficient = 0;
    for(int i = 0; i < 256; i++)
    {
        coefficient += pow(i - mean_val, 4)*histogramValues[i];
    }
    coefficient /= imageResolution;
    coefficient /= pow(deviation_val, 4);
    return coefficient - 3;
}

double variationCoefficientII(CImg<unsigned char> &image, int channel)
{
    fillHistogram(image, channel);
    double coefficient = 0;
    for(unsigned int histogramValue : histogramValues)
    {
        coefficient += pow(histogramValue, 2);
    }
    coefficient /= pow(imageResolution, 2);
    return coefficient;
}

double entropy(CImg<unsigned char> &image, int channel)
{
    fillHistogram(image, channel);
    double image_size = image.width() * image.height() * 1.0;
    double entropy_val = 0;
    for(unsigned int histogramValue : histogramValues)
    {
        if(histogramValue != 0)
            entropy_val += histogramValue * log2(histogramValue/image_size);
    }
    entropy_val /= image_size;
    return -entropy_val;
}
