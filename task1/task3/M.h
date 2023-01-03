#ifndef C___M_H
#define C___M_H
#include <vector>
#include "../CImg.h"
using namespace cimg_library;

CImg<unsigned char> erosion(CImg<unsigned char> &image, std::vector<int> mask);

CImg<unsigned char> dilation(CImg<unsigned char> &image, std::vector<int> mask);

void opening(CImg<unsigned char> &image, std::vector<int> mask);

void closing(CImg<unsigned char> &image, std::vector<int> mask);

void HMT(CImg<unsigned char> &image, std::vector<int> mask);

void M2(CImg<unsigned char> &image, std::vector<int> mask, int x, int y);

void M1_1(CImg<unsigned char> &image, std::vector<int> mask);

void M1_2(CImg<unsigned char> &image, std::vector<int> mask);

void M1_3(CImg<unsigned char> &image, std::vector<int> mask);
#endif //C___M_H