#ifndef C___T_H
#define C___T_H

#include "../CImg.h"
#include <complex>
#include <cmath>
#include <vector>
using namespace cimg_library;

void visualisation(std::vector<std::vector<std::complex<double>>> param);

void CVToImage(std::vector<std::vector<std::complex<double>>> param);

std::vector<std::vector<std::complex<double>>> ImageToCV(CImg<unsigned char> &image);

std::vector<std::vector<std::complex<double>>> DFT(CImg<unsigned char> &image);

std::vector<std::vector<std::complex<double>>> IDFT(std::vector<std::vector<std::complex<double>>> param );

void fft(std::vector<std::complex<double>> &arr, int n);

std::vector<std::vector<std::complex<double>>> FFT(CImg<unsigned char> &image);

void ifft(std::vector<std::complex<double>> &arr, int n);

std::vector<std::vector<std::complex<double>>> IFFT(CImg<unsigned char> &image);

#endif //C___T_H
