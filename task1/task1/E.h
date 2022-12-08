#ifndef C___E_H
#define C___E_H
#include "../CImg.h"
using namespace cimg_library;

double mean_square_error(CImg<unsigned char> image1, CImg<unsigned char> image2);

double peak_mean_square_error(CImg<unsigned char> image1, CImg<unsigned char> image2);

double signal_to_noise_radio(CImg<unsigned char> image1, CImg<unsigned char> image2);

double peak_signal_to_noise_radio(CImg<unsigned char> image1, CImg<unsigned char> image2);

int maximum_difference(CImg<unsigned char> image1, CImg<unsigned char> image2);
#endif //C___E_H