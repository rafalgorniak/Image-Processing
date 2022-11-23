//
// Created by rafal on 01.11.2022.
//

#ifndef MAIN_CPP_S_H
#define MAIN_CPP_S_H
#include "../CImg.h"
using namespace cimg_library;

void extraction_of_deteials(CImg<unsigned char> image, int size,int tab[][3]) {
    CImg<unsigned char> newImage = image;
    for (int x = size; x < image.width()-size; x++) {
        for (int y = size; y < image.height()-size; y++) {
            for(int o=0;o<=2;o++)
            {
                int sum = 0;
                int w1=0;
                for(int a = x-size;a<=x+size;a++)
                {
                    int w2=0;
                    for(int b = y-size;b<=y+size;b++)
                    {
                        sum += tab[w1][w2]*image(a,b,o);
                        w2++;
                    }
                    w1++;
                }
                newImage(x, y,o) = sum;
            }
        }
    }
    newImage.save_bmp("..\\images\\ExtractionOfDetails.bmp");
}

void optimized_extraction_of_deteials(CImg<unsigned char> image) {
    CImg<unsigned char> newImage = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int o=0;o<=2;o++)
            {
                int sum = image(x-1, y-1,o)+image(x-1, y,o)+image(x-1, y+1,o)+
                        image(x, y-1,o)-2*image(x, y,o)-image(x, y+1,o)+
                        image(x-1, y-1,o)-image(x-1, y,o)-image(x+1, y+1,o);

                newImage(x, y,o) = sum;
            }
        }
    }
    newImage.save_bmp("..\\images\\OptimizedExtractionOfDetails.bmp");
}

#endif //MAIN_CPP_S_H
