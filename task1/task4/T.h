#ifndef C___T_H
#define C___T_H

#include <vector>
#include "../CImg.h"
using namespace cimg_library;
//T1
void DFT(CImg<unsigned char> &image, std::vector<int> mask);

void FFT(CImg<unsigned char> &image, std::vector<int> mask);

#endif //C___T_H
