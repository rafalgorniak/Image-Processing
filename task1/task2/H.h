#ifndef C___H_H
#define C___H_H
#include "../CImg.h"
using namespace cimg_library;

void save_histogram(CImg<unsigned char> image, int channel);

void exponential_final_probability_density(CImg<unsigned char> image, float min, float alpha);
#endif //C___H_H
