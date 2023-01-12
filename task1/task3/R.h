#ifndef C___R_H
#define C___R_H

#include <vector>
#include <map>
#include "../CImg.h"
using namespace cimg_library;

void region_growing_merging(CImg<unsigned char> &image, const std::vector<int>& mask);

void RegionMergin(CImg<unsigned char> &image);
#endif //C___R_H
