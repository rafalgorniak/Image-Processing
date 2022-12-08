#include "N.h"

void alpha_trimmed_mean_filter(CImg<unsigned char> &image, int scale) {
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
                    std::sort(box,box+9);
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
        image.save_bmp("..\\images\\AlphaTrimmedMeanFilter.bmp");
    }
}

void geometric_mean_filter(CImg<unsigned char> &image, int scale) {
    for (int x = scale; x < image.width()-scale; x++) {
        for (int y = scale; y < image.height()-scale; y++) {
            for(int o=0;o<=2;o++)
            {
                double geom_sum=1;
                for(int a = x-scale;a<=x+scale;a++)
                {
                    for(int b = y-scale;b<=y+scale;b++)
                    {
                        if(image(a, b,o)!=0)
                            geom_sum=geom_sum*pow(image(a, b,o),(float)(1/pow(2*scale+1,2)));
                    }
                }
                image(x, y,o)=int(geom_sum);
            }
        }
    }
    image.save_bmp("..\\images\\GeometricMeanFilter.bmp");
}

void maxFilter(CImg<unsigned char> image, int scale) {
    CImg<unsigned char> newImage = image;
    for (int x = scale; x < image.width()-scale; x++) {
        for (int y = scale; y < image.height()-scale; y++) {
            int max=0;
            for(int o=0;o<=2;o++)
            {
                for(int a = x-scale;a<=x+scale;a++)
                {
                    for(int b = y-scale;b<=y+scale;b++)
                    {
                        if(image(a, b,o)>max)
                            max=image(a, b,o);
                    }
                }
                newImage(x, y,o)=max;
            }
        }
    }
    newImage.save_bmp("..\\images\\MaxFilter.bmp");
}