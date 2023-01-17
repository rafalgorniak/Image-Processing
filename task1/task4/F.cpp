#include "F.h"


void filter(CImg<unsigned char> &image, CImg<unsigned char> &mask){

    std::vector<std::vector<std::complex<double>>> img = FFT(image);
    const int ROWS = image.width();
    std::vector<std::vector<std::complex<double>>> img1(ROWS,std::vector<std::complex<double>>(ROWS));
    std::vector<std::vector<std::complex<double>>> maska = ImageToCV(mask);

    for(int w = 0 ; w<ROWS/2 ; w++) {
        for(int h = 0; h <ROWS/2 ; h++) {
            img1[w][h] = img[ROWS/2-w-1][ROWS/2-h-1];
            img1[w+ROWS/2][h] = img[ROWS-w-1][ROWS/2-h-1];
            img1[w][h+ROWS/2] = img[ROWS/2-w-1][ROWS-h-1];
            img1[w+ROWS/2][h+ROWS/2] = img[ROWS-w-1][ROWS-h-1];
        }
    }
    visualisation(img1);
    std::complex<double> zero(0,0);
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {

            if(maska[k][l].real()!=255) {
                img1[k][l]=zero;
            }
        }
    }

    IFFT(img1);

}

void LPF(CImg<unsigned char> &image, int param) {

    int ROWS = 512;
    CImg<unsigned char> mask(ROWS, ROWS);
    int d = param;
    if(d>=512 or d<0)
        d = 50;

    for (int w = 0; w < ROWS; w++) {
        for (int h = 0; h < ROWS; h++) {

            if( pow(w-256,2) + pow(h-256,2) <= pow(d,2))
                mask(w,h,0) = 255;
        }
    }
    filter(image, mask);
}

void HPF(CImg<unsigned char> &image, int param) {

    int ROWS = 512;
    CImg<unsigned char> mask(ROWS, ROWS);
    int d = param;
    if(d>=512 or d<0)
        d = 50;

    for (int w = 0; w < ROWS; w++) {
        for (int h = 0; h < ROWS; h++) {

            if( pow(w-256,2) + pow(h-256,2) >= pow(d,2))
                mask(w,h,0) = 255;
        }
    }
    filter(image, mask);
}

void BPF(CImg<unsigned char> &image, int param1, int param2) {

    int ROWS = 512;
    CImg<unsigned char> mask(ROWS, ROWS);
    int d1 = param1;
    int d2 = param2;

    for (int w = 0; w < ROWS; w++) {
        for (int h = 0; h < ROWS; h++) {

            if( pow(w-256,2) + pow(h-256,2) <= pow(d1,2) and pow(w-256,2) + pow(h-256,2) >= pow(d2,2))
                mask(w,h,0) = 255;

        }
    }
    filter(image, mask);
}

void BCF(CImg<unsigned char> &image, int param1, int param2) {

    int ROWS = 512;
    CImg<unsigned char> mask(ROWS, ROWS);
    int d1 = param1;
    int d2 = param2;

    for (int w = 0; w < ROWS; w++) {
        for (int h = 0; h < ROWS; h++) {

            if( pow(w-256,2) + pow(h-256,2) >= pow(d1,2) or pow(w-256,2) + pow(h-256,2) <= pow(d2,2))
                mask(w,h,0) = 255;

        }
    }
    filter(image, mask);

}

void HPDED(CImg<unsigned char> &image, CImg<unsigned char> &mask) {

    filter(image, mask);

}

void PMF(CImg<unsigned char> &image, int param1, int param2) {

    std::vector<std::vector<std::complex<double>>> img = FFT(image);
    const int ROWS = image.width();
    std::vector<std::vector<std::complex<double>>> img1(ROWS,std::vector<std::complex<double>>(ROWS));

    for(int w = 0 ; w<ROWS/2 ; w++) {
        for(int h = 0; h <ROWS/2 ; h++) {
            img1[w][h] = img[ROWS/2-w-1][ROWS/2-h-1];
            img1[w+ROWS/2][h] = img[ROWS-w-1][ROWS/2-h-1];
            img1[w][h+ROWS/2] = img[ROWS/2-w-1][ROWS-h-1];
            img1[w+ROWS/2][h+ROWS/2] = img[ROWS-w-1][ROWS-h-1];
        }
    }


    std::vector<std::vector<std::complex<double>>> mask(ROWS,std::vector<std::complex<double>>(ROWS));
    for(int w = 0; w <ROWS ; w++) {
        for(int h = 0; h <ROWS ; h++) {
            double theta = M_PI * (double(-2*w*param1)/ROWS -double(2*h*param2)/ROWS + param1 +param2);
            std::complex<double> point(cos(theta), sin(theta));
            img1[w][h] *= point;
        }
    }

    IFFT(img1);

}