#include "F.h"

void LPF(CImg<unsigned char> &image, CImg<unsigned char> &mask) {
    std::vector<std::vector<std::complex<double>>> img = FFT(image);
    std::vector<std::vector<std::complex<double>>> maska = ImageToCV(mask);
    const int ROWS = 512;

    std::complex<double> zero(0,0);
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {

            if(maska[k][l].real()!=255) {
                img[k][l]=zero;
            }
            //std::cout<<img[k][l].real()<<" "<<img[k][l].imag()<<std::endl;
        }
    }

    IFFT(img);
}

void HPF(CImg<unsigned char> &image, CImg<unsigned char> &mask) {
    std::vector<std::vector<std::complex<double>>> img = FFT(image);
    std::vector<std::vector<std::complex<double>>> maska = ImageToCV(mask);
    const int ROWS = 512;
    visualisation(img);
    CVToImage(img);
    /*
    std::complex<double> zero(0,0);
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {

            if(maska[k][l].real()!=255) {
                img[k][l]=zero;
            }
            //std::cout<<img[k][l].real()<<" "<<img[k][l].imag()<<std::endl;

        }
    }
    //visualisation(img);

    //IFFT(img);*/
}