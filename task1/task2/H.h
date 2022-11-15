//
// Created by rafal on 01.11.2022.
//

#ifndef MAIN_CPP_H_H
#define MAIN_CPP_H_H

void save_histogram(CImg<unsigned char> image, int a) {
    CImg<unsigned char> histogram(700, 500, 1,3,0);
    int PixelsNumber = image.width()*image.height();
    float PercentagePixelsTable[256];
    for(float & i : PercentagePixelsTable) {
        i=0;
    }
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {
            PercentagePixelsTable[(int)image(x, y,a)] +=(float)1/PixelsNumber;
        }
    }
    for (int x = 0; x < histogram.width(); x++) {
        for (int y = 0; y < histogram.height() ; y++) {
            if((x==50 or x==650) and (y>50 and y<450))
                histogram(x, y,a) = 255;
            if((y==50 or y==450) and (x>50 and x<650))
                histogram(x, y,a) = 255;
        }
    }
    for(int i=0;i<300;i++) {
        for(int j=400;0<j;j--) {
            if(PercentagePixelsTable[i]*20000>j)
            {
                histogram(50+2*i, 450-j,a) = 255;
                histogram(50+2*i+1, 450-j,a) = 255;
            }
        }
    }
    histogram.save_bmp("..\\images\\histogram.bmp");
}

void aleigh_final_probability_density() {

}

#endif //MAIN_CPP_H_H
