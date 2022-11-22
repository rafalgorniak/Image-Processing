//
// Created by rafal on 13.10.2022.
//

#ifndef C___B_H
#define C___B_H
#include "../CImg.h"
using namespace cimg_library;

void brightness(CImg<unsigned char> image,int scale) {
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            for(int i=0;i<3;i++)
            {
                if( image(x, y,i) + scale <= 255 and image(x, y,i) + scale >= 0 )
                    image(x, y,i) += scale;
                else if( image(x, y,i) + scale > 255 )
                    image(x, y,i) = 255;
                else if( image(x, y,i) + scale < 0 )
                    image(x, y,i) = 0;
            }
        }
    }
    image.save_bmp("..\\images\\Brightness.bmp");
}

void contrast(CImg<unsigned char> image,float scale) {
    float factor = ( 259 * ( scale + 255 ) ) / ( 255 * ( 259 - scale ) );
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            for(int i=0;i<3;i++)
            {
                if( ( factor * (float)( image(x, y,i) - 128 ) + 128 ) >=0 and ( factor * ( image(x, y,i) - 128 ) + 128 ) <= 255 )
                    image(x, y,i) = factor * ( image(x, y,i) - 128 ) + 128;
                else if( image(x, y,i) + scale > 255 )
                    image(x, y,i) = 255;
                else if( image(x, y,i) + scale < 0 )
                    image(x, y,i) = 0;
            }
        }
    }
    image.save_bmp("..\\images\\Contrast.bmp");
}

void negative(CImg<unsigned char> image) {
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            for(int i=0;i<3;i++)
            {
                image(x, y,i) = 255 - image(x, y,i);
            }
        }
    }
    image.save_bmp("..\\images\\Negative.bmp");
}

#endif //C___B_H
