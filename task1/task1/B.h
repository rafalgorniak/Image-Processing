#ifndef C___B_H
#define C___B_H
#include "../CImg.h"
using namespace cimg_library;

void brightness(CImg<unsigned char> image, int scale) ;

void contrast(CImg<unsigned char> image,float scale) ;

void negative(CImg<unsigned char> image);
#endif //C___B_H