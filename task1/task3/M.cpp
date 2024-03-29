#include "M.h"

#include <utility>

CImg<unsigned char> erosion(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage = image;
    for (int x = 1; x < image.width() - 1; x++) {
        for (int y = 1; y < image.height() - 1 ; y++) {
            bool flag = true;
            for(int q = 0; q < 3; q++) {
                for(int w = 0; w < 3; w++) {
                    if( mask[3*w+q] == 1 and image(x + q - 1, y + w - 1, 0) == 0)
                        flag = false;
                }
            }
            if(flag) {
                newImage(x, y, 0) = 255;
                newImage(x, y, 1) = 255;
                newImage(x, y, 2) = 255;
            }
            else {
                newImage(x, y, 0) = 0;
                newImage(x, y, 1) = 0;
                newImage(x, y, 2) = 0;
            }
        }
    }
    return newImage;
}

CImg<unsigned char> dilation(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage = image;
    for (int x = 0; x < image.width() ; x++) {
        for (int y = 0; y < image.height()  ; y++) {
            newImage(x, y, 0) = 0;
            newImage(x, y, 1) = 0;
            newImage(x, y, 2) = 0;
        }
    }
    for (int x = 1; x < image.width() - 1; x++) {
        for (int y = 1; y < image.height() - 1 ; y++) {
            if( mask[4] == 1 and image(x , y , 0) == 255) {
                for(int q = 0; q < 3; q++) {
                    for (int w = 0; w < 3; w++) {
                        if(mask[3*q+w]==1)
                        {
                            newImage(x + q - 1, y + w - 1, 0) = 255;
                            newImage(x + q - 1, y + w - 1, 1) = 255;
                            newImage(x + q - 1, y + w - 1, 2) = 255;
                        }
                    }
                }
            }
        }
    }
    return newImage;
}

void opening(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage1 = image;
    for (int x = 1; x < image.width() - 1; x++) {
        for (int y = 1; y < image.height() - 1 ; y++) {
            bool flag = true;
            for(int q = 0; q < 3; q++) {
                for(int w = 0; w < 3; w++) {
                    if( mask[3*w+q] == 1 and image(x + q - 1, y + w - 1, 0) == 0)
                        flag = false;
                }
            }
            if(flag) {
                newImage1(x, y, 0) = 255;
                newImage1(x, y, 1) = 255;
                newImage1(x, y, 2) = 255;
            }
            else {
                newImage1(x, y, 0) = 0;
                newImage1(x, y, 1) = 0;
                newImage1(x, y, 2) = 0;
            }
        }
    }

    CImg<unsigned char> newImage2 = newImage1;
    for (int x = 0; x < newImage1.width() ; x++) {
        for (int y = 0; y < newImage1.height()  ; y++) {
            newImage2(x, y, 0) = 0;
            newImage2(x, y, 1) = 0;
            newImage2(x, y, 2) = 0;
        }
    }
    for (int x = 1; x < newImage1.width() - 1; x++) {
        for (int y = 1; y < newImage1.height() - 1 ; y++) {
            if( mask[4] == 1 and newImage1(x , y , 0) == 255) {
                for(int q = 0; q < 3; q++) {
                    for (int w = 0; w < 3; w++) {
                        if(mask[3*q+w]==1)
                        {
                            newImage2(x + q - 1, y + w - 1, 0) = 255;
                            newImage2(x + q - 1, y + w - 1, 1) = 255;
                            newImage2(x + q - 1, y + w - 1, 2) = 255;
                        }
                    }
                }
            }
        }
    }
    newImage2.save_bmp("..\\images\\Opening.bmp");
}

void closing(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage1 = image;
    for (int x = 0; x < image.width() ; x++) {
        for (int y = 0; y < image.height()  ; y++) {
            newImage1(x, y, 0) = 0;
            newImage1(x, y, 1) = 0;
            newImage1(x, y, 2) = 0;
        }
    }
    for (int x = 1; x < image.width() - 1; x++) {
        for (int y = 1; y < image.height() - 1 ; y++) {
            if( mask[4] == 1 and image(x , y , 0) == 255) {
                for(int q = 0; q < 3; q++) {
                    for (int w = 0; w < 3; w++) {
                        if(mask[3*q+w]==1)
                        {
                            newImage1(x + q - 1, y + w - 1, 0) = 255;
                            newImage1(x + q - 1, y + w - 1, 1) = 255;
                            newImage1(x + q - 1, y + w - 1, 2) = 255;
                        }
                    }
                }
            }
        }
    }
    CImg<unsigned char> newImage2 = newImage1;
    for (int x = 1; x < newImage1.width() - 1; x++) {
        for (int y = 1; y < newImage1.height() - 1 ; y++) {
            bool flag = true;
            for(int q = 0; q < 3; q++) {
                for(int w = 0; w < 3; w++) {
                    if( mask[3*w+q] == 1 and newImage1(x + q - 1, y + w - 1, 0) == 0)
                        flag = false;
                }
            }
            if(flag) {
                newImage2(x, y, 0) = 255;
                newImage2(x, y, 1) = 255;
                newImage2(x, y, 2) = 255;
            }
            else {
                newImage2(x, y, 0) = 0;
                newImage2(x, y, 1) = 0;
                newImage2(x, y, 2) = 0;
            }
        }
    }
    newImage2.save_bmp("..\\images\\Closing.bmp");
}

void HMT(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage = image;
    for (int x = 1; x < image.width() - 1; x++) {
        for (int y = 1; y < image.height() - 1 ; y++) {
            bool flag = true;
            for(int q = 0; q < 3; q++) {
                for(int w = 0; w < 3; w++) {
                    if( !(mask[3*w+q] == 1 and image(x + q - 1, y + w - 1, 0) == 255) and
                        !(mask[3*w+q] == 0 and image(x + q - 1, y + w - 1, 0) == 0) and mask[3*w+q] != 2)
                        flag = false;
                }
            }
            if(flag) {
                newImage(x, y, 0) =255;
                newImage(x, y, 1) = 255;
                newImage(x, y, 2) = 255;
            }
            else {
                newImage(x, y, 0) = 0;
                newImage(x, y, 1) = 0;
                newImage(x, y, 2) = 0;
            }
        }
    }
    newImage.save_bmp("..\\images\\HMT.bmp");
}

void recur(CImg<unsigned char> &image,CImg<unsigned char> &newImage1, std::vector<int> mask,int x, int y) {
    newImage1(x, y, 0) = 255;
    newImage1(x, y, 1) = 255;
    newImage1(x, y, 2) = 255;
    for(int q = 0; q < 3; q++) {
        for (int w = 0; w < 3; w++) {
            if( image(x + q - 1 , y + w - 1 , 0) == 0 and mask[3*q+w]==1
            and newImage1(x + q - 1 , y + w - 1 , 0) == 0 and x>1 and x<image.width() and y>1 and y<image.height())
            {
                recur(image, newImage1, mask, x + q - 1, y + w - 1);
            }
        }
    }
}

void M2(CImg<unsigned char> &image, std::vector<int> mask, int xx, int yy) {
    CImg<unsigned char> newImage1 = image;
    for (int x = 0; x < image.width() ; x++) {
        for (int y = 0; y < image.height()  ; y++) {
            newImage1(x, y, 0) = 0;
            newImage1(x, y, 1) = 0;
            newImage1(x, y, 2) = 0;
        }
    }
    recur(image, newImage1, std::move(mask), xx, yy);
    for (int x = 0; x < image.width() ; x++) {
        for (int y = 0; y < image.height()  ; y++) {
            if(newImage1(x, y, 0)==255 or image(x, y, 0)==255) {
                newImage1(x, y, 0)=255;
                newImage1(x, y, 1)=255;
                newImage1(x, y, 2)=255;
            }
        }
    }
    newImage1.save_bmp("..\\images\\M2.bmp");
}

void M1_1(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage1 = dilation(image, std::move(mask));
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {

            if(image(x,y,0) == 255)
            {
                newImage1(x,y,0) = 0;
                newImage1(x,y,1) = 0;
                newImage1(x,y,2) = 0;
            }
        }
    }
    newImage1.save_bmp("..\\images\\M1_1.bmp");
}

void M1_2(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage1 = erosion(image, std::move(mask));
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {

            if(newImage1(x,y,0) == 255)
            {
                image(x,y,0) = 0;
                image(x,y,1) = 0;
                image(x,y,2) = 0;
            }
        }
    }
    image.save_bmp("..\\images\\M1_2.bmp");
}

void M1_3(CImg<unsigned char> &image, std::vector<int> mask) {
    CImg<unsigned char> newImage1 = erosion(image, mask);
    newImage1.save_bmp("..\\images\\M1_3_.bmp");
    CImg<unsigned char> newImage2 = dilation(image, mask);
    newImage2.save_bmp("..\\images\\M1_3__.bmp");
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() ; y++) {

            if(newImage1(x,y,0) == 255)
            {
                newImage2(x,y,0) = 0;
                newImage2(x,y,1) = 0;
                newImage2(x,y,2) = 0;
            }
        }
    }

    newImage2.save_bmp("..\\images\\M1_3.bmp");
}