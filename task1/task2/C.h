#ifndef C___C_H
#define C___C_H
#include "../CImg.h"
using namespace cimg_library;

void fillHistogram(CImg<unsigned char> &image, int channel);

double mean(CImg<unsigned char> &image, int channel);

double variance(CImg<unsigned char> &image, int channel);

double deviation(CImg<unsigned char> &image, int channel);

double variationCoefficient(CImg<unsigned char> &image, int channel);

double asymmetryCoefficient(CImg<unsigned char> &image, int channel);

double flatteningCoefficient(CImg<unsigned char> &image, int channel);

double variationCoefficientII(CImg<unsigned char> &image, int channel);

double entropy(CImg<unsigned char> &image, int channel);
#endif //C___C_H