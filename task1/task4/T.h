#ifndef C___T_H
#define C___T_H

#include "../CImg.h"
#include <complex>
#include <cmath>
#include <vector>
using namespace cimg_library;

void visualisation(std::vector<std::vector<std::complex<double>>> param);

CImg<unsigned char> CVToImage(std::vector<std::vector<std::complex<double>>> param);

std::vector<std::vector<std::complex<double>>> ImageToCV(CImg<unsigned char> &image);

std::vector<std::vector<std::complex<double>>> DFT(CImg<unsigned char> &image);

std::vector<std::vector<std::complex<double>>> IDFT(std::vector<std::vector<std::complex<double>>> param );

void fft(std::vector<std::complex<double>> &arr, int n);

std::vector<std::vector<std::complex<double>>> FFT(CImg<unsigned char> &image);

std::vector<std::vector<std::complex<double>>> FFTF(CImg<unsigned char> &image);

void fftf(std::vector<std::complex<double>> &arr, int n);

void ifft(std::vector<std::complex<double>> &arr, int n);

std::vector<std::vector<std::complex<double>>> IFFT(CImg<unsigned char> &image);
std::vector<std::vector<std::complex<double>>> IFFT(std::vector<std::vector<std::complex<double>>> img );


#endif //C___T_H
