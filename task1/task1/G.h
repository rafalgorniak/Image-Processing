#ifndef C___G_H
#define C___G_H
#include "../CImg.h"
using namespace cimg_library;
void horizontal_flip(CImg<unsigned char> image);

void vertical_flip(CImg<unsigned char> image);

void diagonal_flip(CImg<unsigned char> image);

void shrinking(CImg<unsigned char> image, int scale);

void enlargement(CImg<unsigned char> image, int scale);
#endif //C___G_H