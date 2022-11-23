//
// Created by rafal on 16.10.2022.
//

#ifndef C___E_H
#define C___E_H
#include "../CImg.h"
using namespace cimg_library;

float mean_square_error(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    float mean_square=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height() ; y++) {
            mean_square+=pow(image1(x, y)-image2(x, y),2);
        }
    }
    return mean_square/(image1.width()*image1.height());
}

float peak_mean_square_error(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    float mean_square=0;
    int max=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height() ; y++) {
            mean_square+=pow(image1(x, y)-image2(x, y),2);
            if(image1(x, y)>max)
                max=image1(x,y);
        }
    }
    return mean_square/(image1.width()*image1.height()*pow(max,2));
}

float signal_to_noise_radio(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    float mean_square1=0;
    float mean_square2=0;
    for (unsigned int x = 0; x < image1.width(); x++) {
        for (unsigned int y = 0; y < image1.height(); y++) {
            mean_square1 += (pow((image1(x,y,0)), 2)
                       + pow((image1(x,y,1)), 2) + pow((image1(x,y,2)), 2)) / 3;
            mean_square2 += (pow((image1(x,y,0) - image2(x,y,0)), 2)
                      + pow((image1(x,y,0) - image2(x,y,0)), 2) + pow((image1(x,y,0) - image2(x,y,0)), 2)) / 3;
        }
    }
    return 10*log10(mean_square1/mean_square2);
}

float peak_signal_to_noise_radio(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    float mean_square1=0;
    int max=0;
    for (unsigned int x = 0; x < image1.width(); x++) {
        for (unsigned int y = 0; y < image1.height(); y++) {
            if(image1(x,y,0) + image1(x,y,1) + image1(x,y,2) > 3 * mean_square1) {
                mean_square1 = (image1(x,y,0) + image1(x,y,1) + image1(x,y,2)) / 3;
            }
            max += (pow((image1(x,y,0) - image2(x,y,0)), 2)
                      + pow((image1(x,y,1) - image2(x,y,1)), 2) + pow((image1(x,y,2) - image2(x,y,2)), 2)) / 3;
        }
    }
    return 10*log10((image1.width()*image1.height()*pow(mean_square1,2))/max);
}

int maximum_difference(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    int max=0;
    for (unsigned int x = 0; x < image1.width(); x++) {
        for (unsigned int y = 0; y < image1.height(); y++) {
            if (std::abs(image1(x, y, 0) - image2(x, y, 0))
                + std::abs(image1(x, y, 1) - image2(x, y, 1))
                + std::abs(image1(x, y, 2) - image2(x, y, 2)) >  3 * max) {
                max = (std::abs(image1(x, y, 0) - image2(x, y, 0))
                     + std::abs(image1(x, y, 1) - image2(x, y, 1))
                     + std::abs(image1(x, y, 2) - image2(x, y, 2))) / 3;
            }
        }
    }
    return max;
}

#endif //C___E_H
