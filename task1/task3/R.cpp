#include <iostream>
#include "R.h"

bool signPixels(CImg<unsigned char> image, int x, int y, std::vector<int> mask)
{
    for (int xi = -1; xi < 2; xi++)
    {
        for (int yi = -1; yi < 2; yi++)
        {
                if(mask[3*(xi+1)+yi] && (xi != 0 || yi != 0) && ((int)image(x+xi, y+yi, 0) - (int)image(x, y, 0))==0)
            {
                std::cout<<(int)image(x+xi, y+yi, 0)<<" "<<(int)image(x, y, 0)<<std::endl;
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
            /*
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
             */
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

struct Point {
    Point(int i, int i1) {
        x = i;
        y = i1;
    }
    int x;
    int y;
};

void RegionMergin(CImg<unsigned char> &image) {

    CImg<unsigned char> newImage1(image.width(), image.height(), 1, 1, 0);
    std::vector<Point> CheckPixels;

    int x,y;
    std::cout<<"X coordinate:";
    std::cin>>x;
    std::cout<<"Y coordinate:";
    std::cin>>y;
    int c=0;
    newImage1(x,y,0) = 255;
    CheckPixels.emplace_back(x,y);
    while(!CheckPixels.empty()) {

        int MapSize = (int)CheckPixels.size();
        int counter = 0;
        for (auto itr = CheckPixels.begin(); itr != CheckPixels.end(); itr++) {
            if (counter == MapSize)
                break;

            for(int xx = -1; xx<=1; xx++) {
                for(int yy = -1; yy<=1; yy++) {
                    if(itr->x+xx >= 0 and itr->y+yy >= 0) {

                        if( newImage1(itr->x+xx,itr->y+yy,0)==0  && (xx!=0 || yy!=0) && abs( image(itr->x,itr->y,0) - image(itr->x+xx,itr->y+yy,0) ) ==0 ) {
                            //std::cout<<"adad"<<std::endl;
                            newImage1(itr->x+xx,itr->y+yy,0) = 255;
                            CheckPixels.emplace_back(itr->x+xx, itr->y+yy);
                            //std::cout<<itr->x+xx<<" "<<itr->y+yy<<std::endl;
                        }
                    }
                }
            }

            //std::cout<<"koniec jednegi fora"<<std::endl;
            counter++;
            //for (auto & toCheckPixel : CheckPixels) {
            //    std::cout<<toCheckPixel.x<<" "<<toCheckPixel.y<<std::endl;
            //}
            //cimg::sleep(2000);
            auto itrr = CheckPixels.begin();
            CheckPixels.erase(itrr);
            //for (auto & toCheckPixel : CheckPixels) {
            //    std::cout<<toCheckPixel.x<<" "<<toCheckPixel.y<<std::endl;
            //}
            //std::cout<<"To wszystkie elementy list teraz spanko"<<std::endl;
            //cimg::sleep(5000);
        }
        std::cout<<"Koniec glownej"<<std::endl;
        c++;

    }

    newImage1.save_bmp("..\\images\\RM.bmp");
}