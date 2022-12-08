#ifndef C___N_H
#define C___N_H
#include "../CImg.h"
using namespace cimg_library;

void alpha_trimmed_mean_filter(CImg<unsigned char> &image, int scale);

void geometric_mean_filter(CImg<unsigned char> &image, int scale);

void maxFilter(CImg<unsigned char> image, int scale);
#endif //C___N_H