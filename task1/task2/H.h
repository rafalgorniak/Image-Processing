//
// Created by rafal on 01.11.2022.
//

#ifndef MAIN_CPP_H_H
#define MAIN_CPP_H_H
#include "../CImg.h"
using namespace cimg_library;

void save_histogram(CImg<unsigned char> image, int channel) {
    CImg<unsigned char> histogram(512, 400, 1,3,0);
    int PixelsNumber = image.width()*image.height();
    float PercentagePixelsTable[256];
    for(float & i : PercentagePixelsTable) {
        i=0;
    }
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            PercentagePixelsTable[(int)image(x, y,channel)] +=(float)1/PixelsNumber;
        }
    }
    for(int i=0;i<300;i++) {
        for(int j=400;0<j;j--) {
            if(PercentagePixelsTable[i]*10000>j)
            {
                histogram(2*i, 400-j,channel) = 255;
                histogram(2*i+1, 400-j,channel) = 255;
            }
        }
    }
    histogram.save_bmp("..\\images\\histogram.bmp");
}

void exponential_final_probability_density(CImg<unsigned char> image, int channel, int min, float alpha) {
    CImg<unsigned char> newImage = image;
    int PixelsNumber = image.width()*image.height();
    int PercentagePixelsTable[256];
    float NewValues[256];
    float Min;
    if (min == 0) {
        Min = 0.001;
    } else {
        Min = (float)min;
    }
    for(int & i : PercentagePixelsTable) {
        i=0;
    }
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            PercentagePixelsTable[(int)image(x, y,channel)]++;
        }
    }
    for (int x = 0; x < newImage.width(); x++)
    {
        for (int y = 0; y < newImage.height(); y++)
        {
            int sum=0;
            for(int i=0;i<image(x, y, channel);i++)
            {
                sum+=PercentagePixelsTable[i];
            }
            newImage(x, y, 0) = Min -(1/(float)alpha)*log(1-((float) sum / (float) PixelsNumber));
            newImage(x, y, 1) = Min -(1/(float)alpha)*log(1-((float) sum / (float) PixelsNumber));
            newImage(x, y, 2) = Min -(1/(float)alpha)*log(1-((float) sum / (float) PixelsNumber));
        }
    }
    newImage.save("..//images//exponential_function.bmp");
}
#endif //MAIN_CPP_H_H
