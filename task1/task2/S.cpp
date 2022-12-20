#include "S.h"

void extraction_of_details(CImg<unsigned char> image, int size,std::vector<int> vec) {
    CImg<unsigned char> newImage = image;
    for (int x = size; x < image.width()-size; x++) {
        for (int y = size; y < image.height()-size; y++) {
            for(int o=0;o<=2;o++)
            {
                int sum = 0;
                int w1=0;
                for(int a = x-size;a<=x+size;a++)
                {
                    int w2=0;
                    for(int b = y-size;b<=y+size;b++)
                    {
                        sum += vec[w1*(2*size+1)+w2]*image(a,b,o);
                        w2++;
                    }
                    w1++;
                }
                newImage(x, y,o) = sum;
            }
        }
    }
    newImage.save_bmp("..\\images\\ExtractionOfDetails1.bmp");
}

void optimized_extraction_of_details(CImg<unsigned char> image) {
    CImg<unsigned char> newImage = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int o=0;o<=2;o++)
            {
                newImage(x, y,o) = abs(image(x-1, y-1,o)+image(x-1, y,o)+image(x-1, y+1,o)+
                                       image(x, y-1,o)-2*image(x, y,o)-image(x, y+1,o)+
                                       image(x-1, y-1,o)-image(x-1, y,o)-image(x+1, y+1,o));
                if(newImage(x, y,o)>255)
                    newImage(x, y,o)=255;
            }
        }
    }
    newImage.save_bmp("..\\images\\OptimizedExtractionOfDetails.bmp");
}
