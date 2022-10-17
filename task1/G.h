//
// Created by rafal on 13.10.2022.
//

#ifndef C___G_H
#define C___G_H
#include "CImg.h"
using namespace cimg_library;

void horizontal_flip(CImg<unsigned char> image) {
    CImg<unsigned char> image2 = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            for(int i=0;i<=2;i++)
            {
                image2(x, y,i) = image(image.height()-x-1, y,i);
            }
        }
    }
    image2.save_bmp("..\\images\\out4.bmp");
}

void vertical_flip(CImg<unsigned char> image) {
    CImg<unsigned char> image2 = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            for(int i=0;i<=2;i++)
            {
                image2(x, y,i) = image(x, image.height()-y-1,i);
            }
        }
    }
    image2.save_bmp("..\\images\\out5.bmp");
}

void diagonal_flip(CImg<unsigned char> image) {
    CImg<unsigned char> image2 = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            for(int i=0;i<=2;i++)
            {
                image2(x, y,i) = image(image.height()-x-1, image.height()-y-1,i);
            }
        }
    }
    image2.save_bmp("..\\images\\out6.bmp");
}

void shrinking_enlargement(CImg<unsigned char> image, float scale=2) {
    CImg<unsigned char> image2(image.width() * scale,image.height() * scale,1,3,0);
    for (int x = 0; x < image2.width(); x++) {
        for (int y = 0; y < image2.height() ; y++) {
            for(int i=0;i<=2;i++)
            {
                image2(x, y,i) = image(x/scale, y/scale,i);
            }
        }
    }
    image2.save_bmp("..\\images\\out7.bmp");
}


#endif //C___G_H
