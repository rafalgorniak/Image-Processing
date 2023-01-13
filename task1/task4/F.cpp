#include "F.h"


void filter(CImg<unsigned char> &image, CImg<unsigned char> &mask){

    std::vector<std::vector<std::complex<double>>> img = FFT(image);
    std::vector<std::vector<std::complex<double>>> img1(512,std::vector<std::complex<double>>(512));
    std::vector<std::vector<std::complex<double>>> maska = ImageToCV(mask);

    for(int w = 0 ; w<256 ; w++) {
        for(int h = 0; h <256 ; h++) {
            img1[w][h] = img[256-w-1][256-h-1];
            img1[w+256][h] = img[512-w-1][256-h-1];
            img1[w][h+256] = img[256-w-1][512-h-1];
            img1[w+256][h+256] = img[512-w-1][512-h-1];
        }
    }


    const int ROWS = 512;

    std::complex<double> zero(0,0);
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {

            if(maska[k][l].real()!=255) {
                img1[k][l]=zero;
            }
            //std::cout<<img[k][l].real()<<" "<<img[k][l].imag()<<std::endl;
        }
    }

    //visualisation(img1);
    IFFT(img1);

}

void LPF(CImg<unsigned char> &image, CImg<unsigned char> &mask) {

    filter(image, mask);

}

void HPF(CImg<unsigned char> &image, CImg<unsigned char> &mask) {

    filter(image, mask);

}

void BPF(CImg<unsigned char> &image, CImg<unsigned char> &mask) {

    filter(image, mask);

}

void BCF(CImg<unsigned char> &image, CImg<unsigned char> &mask) {

    filter(image, mask);

}

void HPDED(CImg<unsigned char> &image, CImg<unsigned char> &mask) {

    filter(image, mask);

}

void PMF(CImg<unsigned char> &image) {



}