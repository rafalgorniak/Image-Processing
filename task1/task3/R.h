#ifndef C___R_H
#define C___R_H

#include <vector>
#include "../CImg.h"
using namespace cimg_library;

void region_growing_merging(CImg<unsigned char> &image, std::vector<int> mask);
#endif //C___R_H
