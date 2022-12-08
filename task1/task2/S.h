#ifndef C___S_H
#define C___S_H
#include "../CImg.h"
#include <vector>
using namespace cimg_library;

void extraction_of_details(CImg<unsigned char> image, int size,std::vector<int> vec);

void optimized_extraction_of_details(CImg<unsigned char> image);

#endif //C___S_H