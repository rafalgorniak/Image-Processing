#include <iostream>
#include "T.h"

void visualisation(std::vector<std::vector<std::complex<double>>> param) {

    const int ROWS = 512;
    CImg<unsigned char> newImage1(ROWS, ROWS);
    std::vector<std::vector<double>> params(512,std::vector<double>(512));
    double max = 0;
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {


            params[k][l] = log(sqrt(pow(param[k][l].real(),2)+pow(param[k][l].imag(),2)));
            if(params[k][l] > max)
                max = params[k][l];

        }
    }
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {


            newImage1(k,l,0) = (params[k][l]/max)*255;
            /*
            if(k<100 and l<100)
                std::cout << (params[k][l]/max)*255 << std::endl;
            */

        }
    }
    newImage1.save_bmp("..\\images\\Visualization1.bmp");
}

void CVToImage(std::vector<std::vector<std::complex<double>>> param) {

    const int ROWS = 512;
    CImg<unsigned char> newImage1(ROWS, ROWS);
    std::vector<std::vector<double>> params(512,std::vector<double>(512));
    double max = 0;
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {

            params[k][l] = sqrt(pow(param[k][l].real(),2)+pow(param[k][l].imag(),2));
            if(params[k][l] > max)
                max = params[k][l];

        }
    }
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < ROWS; l++) {


            newImage1(k,l,0) = (params[k][l]/max)*255;
            /*
            if(k<100 and l<100)
                std::cout << (params[k][l]/max)*255 << std::endl;
            */

        }
    }
    newImage1.save_bmp("..\\images\\CVToImage.bmp");
}

std::vector<std::vector<std::complex<double>>> ImageToCV(CImg<unsigned char> &image) {

    std::vector<std::vector<std::complex<double>>> img(512,std::vector<std::complex<double>>(512));

    for (int j = 0; j < 512; j++) {
        for (int i = 0; i < 512; i++) {

            std::complex<double> c1(image(j,i,0), 0);
            img[j][i] = c1;

        }
    }
    return img;
}

std::vector<std::vector<std::complex<double>>> DFT(CImg<unsigned char> &image) {

    const int ROWS = 512;
    const int COLS = 512;

// The input image (a grayscale image stored as a 2D array of integers)
    std::vector<std::vector<std::complex<double>>> img = ImageToCV(image);
// The output image (a 2D array of complex numbers representing the DFT)

    // Compute the DFT of the image
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < COLS; l++) {
            std::complex<double> sum(0.0, 0.0);
            std::complex<double> helper(ROWS, 0.0);
            for (int m = 0; m < ROWS; m++) {
                for (int n = 0; n < COLS; n++) {
                    double theta1 = 2.0 * M_PI * (float)k * (float)m / ROWS;
                    double theta2 = 2.0 * M_PI * (float)l * (float)n / COLS;
                    std::complex<double> c1(cos(theta1), -sin(theta1));
                    std::complex<double> c2(cos(theta2), -sin(theta2));
                    sum += img[m][n] * c1 * c2;
                }
            }
            img[k][l] = sum/ helper;
        }
    }
    return img;
}

std::vector<std::vector<std::complex<double>>> IDFT(std::vector<std::vector<std::complex<double>>> param ) {

    const int ROWS = 512;
    const int COLS = 512;

// The input image (a grayscale image stored as a 2D array of integers)
    std::vector<std::vector<std::complex<double>>> img(ROWS,std::vector<std::complex<double>>(COLS));
// The output image (a 2D array of complex numbers representing the DFT)

    // Compute the DFT of the image
    for (int k = 0; k < ROWS; k++) {
        for (int l = 0; l < COLS; l++) {
            std::complex<double> sum(0.0, 0.0);
            std::complex<double> helper(ROWS, 0.0);
            for (int m = 0; m < ROWS; m++) {
                for (int n = 0; n < COLS; n++) {
                    double theta1 = 2.0 * M_PI * (float)k * (float)m / ROWS;
                    double theta2 = 2.0 * M_PI * (float)l * (float)n / COLS;
                    std::complex<double> c1(cos(theta1), sin(theta1));
                    std::complex<double> c2(cos(theta2), sin(theta2));
                    sum += param[m][n] * c1 * c2;
                }
            }
            img[k][l] = sum/ helper;
        }
    }

    return img;
}

void fft(std::vector<std::complex<double>> &arr, int n) {
    if (n == 1) return;

    std::vector<std::complex<double>> even(n/2);
    std::vector<std::complex<double>> odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = arr[2*i];
        odd[i] = arr[2*i + 1];
    }
    fft(even, n/2);
    fft(odd, n/2);

    // Combine the results using the Cooley-Tukey algorithm
    double theta = -2.0 * M_PI /(double)n;
    std::complex<double> v(1);
    std::complex<double> wn(cos(theta), sin(theta));
    for (int k = 0; k < n/2; k++) {
        arr[k] = even[k] + v * odd[k];
        arr[k + n/2] = even[k] - v * odd[k];
        v *= wn;
    }
}

std::vector<std::vector<std::complex<double>>> FFT(CImg<unsigned char> &image) {

    const int ROWS = 512;
    const int COLS = 512;

    std::vector<std::vector<std::complex<double>>> img = ImageToCV(image);
    /*
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout<<img[j][i].real()<<"  "<<img[j][i].real()<<std::endl;
        }
        }
    */
// The input image (a grayscale image stored as a 2D array of integers)

    for (int i = 0; i < ROWS; i++) {
        fft(img[i], COLS);
    }

    // Perform the 1D FFT on the columns
    std::vector<std::complex<double>> temp(ROWS);
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            temp[i] = img[i][j];
        }
            fft(temp, ROWS);
            for (int i = 0; i < ROWS; i++) {
                img[i][j] = temp[i];
            }

    }

    /*
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout<<img[j][i].real()<<"  "<<img[j][i].imag()<<std::endl;
        }
    }
    */

    visualisation(img);
    return img;
}

void ifft(std::vector<std::complex<double>> &arr, int n) {
    if (n == 1) return;

    std::vector<std::complex<double>> even(n/2);
    std::vector<std::complex<double>> odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = arr[2*i];
        odd[i] = arr[2*i + 1];
    }
    fft(even, n/2);
    fft(odd, n/2);

    // Combine the results using the Cooley-Tukey algorithm
    double theta = 2.0 * M_PI /(double)n;
    std::complex<double> v(1);
    std::complex<double> wn(cos(theta), -sin(theta));
    for (int k = 0; k < n/2; k++) {
        arr[k] = even[k] + v * odd[k];
        arr[k + n/2] = even[k] - v * odd[k];
        v *= wn;
    }
}

std::vector<std::vector<std::complex<double>>> IFFT(CImg<unsigned char> &image) {

    const int ROWS = 512;
    const int COLS = 512;

    CImg<unsigned char> origin("../images/lena.bmp");
    std::vector<std::vector<std::complex<double>>> img1 = ImageToCV(image);
    std::vector<std::vector<std::complex<double>>> img = FFT(origin);
    /*
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout<<img[j][i].real()<<"  "<<img[j][i].real()<<std::endl;
        }
        }
    */
// The input image (a grayscale image stored as a 2D array of integers)

    for (int i = 0; i < ROWS; i++) {
        ifft(img[i], COLS);
    }

    // Perform the 1D FFT on the columns
    std::vector<std::complex<double>> temp(ROWS);
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            temp[i] = img[i][j];
        }
        ifft(temp, ROWS);
        for (int i = 0; i < ROWS; i++) {
            img[i][j] = temp[i];
        }
    }

    /*
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            std::cout<<img[j][i].real()<<"  "<<img[j][i].imag()<<std::endl;
        }
    }
    */

    CVToImage(img);
    return img;
}