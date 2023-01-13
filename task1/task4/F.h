#ifndef C___F_H
#define C___F_H

#include <vector>
#include <complex>
#include <iostream>
#include "T.h"
#include "../CImg.h"
using namespace cimg_library;

void LPF(CImg<unsigned char> &image, CImg<unsigned char> &mask);

void HPF(CImg<unsigned char> &image, CImg<unsigned char> &mask);

void BPF(CImg<unsigned char> &image, CImg<unsigned char> &mask);

void BCF(CImg<unsigned char> &image, CImg<unsigned char> &mask);

void HPDED(CImg<unsigned char> &image, CImg<unsigned char> &mask);

void PMF(CImg<unsigned char> &image);

#endif //C___F_H
