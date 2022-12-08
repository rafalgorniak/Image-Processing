#ifndef C___M_H
#define C___M_H
#include <vector>
#include "../CImg.h"
using namespace cimg_library;

void erosion(CImg<unsigned char> &image, std::vector<int> mask);

void dilation(CImg<unsigned char> &image, std::vector<int> mask);

void opening(CImg<unsigned char> &image, std::vector<int> mask);

void closing(CImg<unsigned char> &image, std::vector<int> mask);

void HMT(CImg<unsigned char> &image, std::vector<int> mask);

void M2(CImg<unsigned char> &image, std::vector<int> mask, int x, int y);

#endif //C___M_H
