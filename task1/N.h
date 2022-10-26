//
// Created by rafal on 13.10.2022.
//

#ifndef C___N_H
#define C___N_H
#include "CImg.h"
using namespace cimg_library;

void alpha_trimmed_mean_filter(CImg<unsigned char> image, int scale) {
    if(scale>=0 and scale<9)
    {
        for (int x = 1; x < image.width()-1; x++) {
            for (int y = 1; y < image.height()-1; y++) {
                for(int o=0;o<=2;o++)
                {
                    int elem_num=9;
                    int elem_sum=0;
                    int box[elem_num];
                    int n=0;
                    int start_elem;
                    for(int a = x-1;a<=x+1;a++)
                    {
                        for(int b = y-1;b<=y+1;b++)
                        {
                            box[n]=image(a, b,o);
                            n++;
                        }
                    }
                    int j;
                    for (int i = 0; i < elem_num - 1; i++)
                        for (j = 0; j < elem_num - i - 1; j++)
                            if (box[j] > box[j + 1])
                            {
                                int a=box[j];
                                box[j]=box[j+1];
                                box[j+1]=a;
                            }
                    if(scale%2==1)
                        start_elem=scale;
                    else
                        start_elem=scale/2;
                    for(int t=start_elem;t<elem_num-scale/2;t++)
                    {
                        elem_sum+=box[t];
                    }
                    image(x, y,o)=elem_sum/(elem_num-scale);
                }
            }
        }
        image.save_bmp("..\\images\\out8.bmp");
    }
}

void geometric_mean_filter(CImg<unsigned char> image) {
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int o=0;o<=2;o++)
            {
                double geom_sum=1;
                for(int a = x-1;a<=x+1;a++)
                {
                    for(int b = y-1;b<=y+1;b++)
                    {
                        if(image(a, b,o)!=0)
                            geom_sum=geom_sum*pow(image(a, b,o),(float)1/9);
                    }
                }
                image(x, y,o)=int(geom_sum);
            }
        }
    }
    image.save_bmp("..\\images\\out9.bmp");
}

#endif //C___N_H
