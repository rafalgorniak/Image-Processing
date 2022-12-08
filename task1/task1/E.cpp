#include "E.h"

double mean_square_error(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    double mean_square=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height() ; y++) {
            mean_square+=(pow(image1(x, y,0)-image2(x, y,0),2)
                    +pow(image1(x, y,1)-image2(x, y,1),2)
                    +pow(image1(x, y,2)-image2(x, y,2),2))/3;
        }
    }
    return mean_square/(image1.width()*image1.height());
}

double peak_mean_square_error(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    double mean_square=0;
    int max=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height() ; y++) {
            mean_square+=(pow(image1(x, y,0)-image2(x, y,0),2)
                          +pow(image1(x, y,1)-image2(x, y,1),2)
                          +pow(image1(x, y,2)-image2(x, y,2),2))/3;
            if(image1(x, y,0)+image1(x, y,1)+image1(x, y,2)>3*max)
                max=(image1(x, y,0)+image1(x, y,1)+image1(x, y,2))/3;
        }
    }
    return mean_square/(image1.width()*image1.height()*max);
}

double signal_to_noise_radio(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    double mean_square1=0;
    double mean_square2=0;
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

double peak_signal_to_noise_radio(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    double mean_square1=0;
    double max=0;
    for (unsigned int x = 0; x < image1.width(); x++) {
        for (unsigned int y = 0; y < image1.height(); y++) {
            if(image1(x,y,0) + image1(x,y,1) + image1(x,y,2) > 3 * mean_square1) {
                mean_square1 = (double)(image1(x,y,0) + image1(x,y,1) + image1(x,y,2)) / 3;
            }
            max += (pow((image1(x,y,0) - image2(x,y,0)), 2)
                      + pow((image1(x,y,1) - image2(x,y,1)), 2) + pow((image1(x,y,2) - image2(x,y,2)), 2)) / 3;
        }
    }
    return 10*log10((image1.width()*image1.height()*pow(mean_square1,2))/max);
}

int maximum_difference(CImg<unsigned char> image1, CImg<unsigned char> image2) {
    int max_r=0;
    int max_g=0;
    int max_b=0;
    for (unsigned int x = 0; x < image1.width(); x++) {
        for (unsigned int y = 0; y < image1.height(); y++) {
            if (std::abs(image1(x, y, 0) - image2(x, y, 0))>max_r)
                max_r = (std::abs(image1(x, y, 0) - image2(x, y, 0)));
            if (std::abs(image1(x, y, 0) - image2(x, y, 1))>max_g)
                max_g = (std::abs(image1(x, y, 0) - image2(x, y, 1)));
            if (std::abs(image1(x, y, 0) - image2(x, y, 2))>max_b)
                max_b = (std::abs(image1(x, y, 0) - image2(x, y, 2)));
            }
        }
    return (max_r+max_g+max_b)/3;
}