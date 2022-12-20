#include <iostream>
#include "R.h"

bool signPixels(CImg<unsigned char> image, int x, int y, std::vector<int> mask)
{
    for (int xi = -1; xi < 2; xi++)
    {
        for (int yi = -1; yi < 2; yi++)
        {
                if(mask[3*(xi+1)+yi] && (xi != 0 || yi != 0) && image(x+xi, y+yi, 0) - image(x, y, 0)==0)
            {
                return true;
            }
        }
    }
    return false;
}

bool signArea(CImg<unsigned char> Area, int x, int y)
{
    for (int xi = -1; xi < 2; xi++)
    {
        for (int yi = -1; yi < 2; yi++)
        {
                if(Area(x+xi, y+yi, 0) == 255)
                {
                    return true;
                }
        }
    }
    return false;
}

void region_growing_merging(CImg<unsigned char> &image, const std::vector<int>& mask) {
    CImg<unsigned char> newImage1(image.width(), image.height(), 1, 3, 0);
    int X=100,Y=100;
    std::cout<<"X coordinate:"<<std::endl;
    std::cin>>X;
    std::cout<<"Y coordinate:"<<std::endl;
    std::cin>>Y;
    newImage1(X,Y,0)=255;
    for (int x = 1; x < image.width()-1; x++)
    {
        for (int y = 1; y < image.height()-1; y++)
        {
            if(newImage1(x,y,0) == 0 && signArea(newImage1, x, y) && signPixels(image, x, y,mask))
            {
                newImage1(x,y,0)=255;
            }
            if(newImage1(x,image.height()-1-y,0) == 0 && signArea(newImage1, x, image.height()-1-y)
            && signPixels(image, x, image.height()-1-y,mask))
            {
                newImage1(x,image.height()-1-y,0) = 255;
            }
            if(newImage1(image.width()-1-x,y,0) == 0 && signArea(newImage1, image.width()-1-x, y)
            && signPixels(image, image.width()-1-x, y,mask))
            {
                newImage1(image.width()-1-x,y,0) = 255;
            }
            if(newImage1(image.width()-1-x,image.height()-1-y,0) == 0 &&
                    signArea(newImage1, image.width()-1-x, image.height()-1-y) &&
                    signPixels(image, image.width()-1-x, image.height()-1-y,mask))
            {
                newImage1(image.width()-1-x,image.height()-1-y,0) = 255;
            }
        }
    }
    newImage1.save_bmp("..\\images\\RGM.bmp");
}