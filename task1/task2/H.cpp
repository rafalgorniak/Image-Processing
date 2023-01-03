#include "H.h"

void save_histogram(CImg<unsigned char> image, int channel) {
    CImg<unsigned char> histogram(512, 400, 1,3,0);
    int PixelsNumber = image.width()*image.height();
    float PercentagePixelsTable[256];
    for(float & i : PercentagePixelsTable) {
        i=0;
    }
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            PercentagePixelsTable[(int)image(x, y,channel)] +=(float)1/(float)PixelsNumber;
        }
    }
    for(int i=0;i<300;i++) {
        for(int j=400;0<j;j--) {
            if(PercentagePixelsTable[i]*20000>(float)j)
            {
                histogram(2*i, 400-j,0) = 100;
                histogram(2*i+1, 400-j,0) = 100;
                histogram(2*i, 400-j,1) = 100;
                histogram(2*i+1, 400-j,1) = 100;
                histogram(2*i, 400-j,2) = 100;
                histogram(2*i+1, 400-j,2) = 100;
            }
        }
    }
    histogram.save_bmp("..\\images\\histogram.bmp");
}

void exponential_final_probability_density(CImg<unsigned char> image, float min, float alpha) {
    CImg<unsigned char> newImage = image;
    int PixelsNumber = image.width()*image.height();
    int PercentagePixelsTable[256];
    for(int & i : PercentagePixelsTable) {
        i=0;
    }
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            PercentagePixelsTable[(int)image(x, y,0)]++;
        }
    }
    for (int x = 0; x < newImage.width(); x++)
    {
        for (int y = 0; y < newImage.height(); y++) {

        }
    }

    for (int x = 0; x < newImage.width(); x++)
    {
        for (int y = 0; y < newImage.height(); y++)
        {
            int sum=0;
            for(int i=0;i<image(x, y, 0);i++)
            {
                sum+=PercentagePixelsTable[i];
            }
            newImage(x, y, 0) = (unsigned char)(min -(1/(float)alpha)*log(1-((float) sum / (double) PixelsNumber)));
            newImage(x, y, 1) = (unsigned char)(min -(1/(float)alpha)*log(1-((float) sum / (double) PixelsNumber)));
            newImage(x, y, 2) = (unsigned char)(min -(1/(float)alpha)*log(1-((float) sum / (double) PixelsNumber)));
        }
    }
    newImage.save("..//images//exponential_function.bmp");
}
