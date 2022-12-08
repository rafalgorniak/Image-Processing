#include "M.h"

void erosion(CImg<unsigned char> &image, std::vector<int> mask) {
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
    newImage.save_bmp("..\\images\\Erosion.bmp");
}

void dilation(CImg<unsigned char> &image, std::vector<int> mask) {
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
                        newImage(x + q - 1, y + w - 1, 0) = 255;
                        newImage(x + q - 1, y + w - 1, 1) = 255;
                        newImage(x + q - 1, y + w - 1, 2) = 255;
                    }
                }
            }
        }
    }
    newImage.save_bmp("..\\images\\Dilation.bmp");
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
                        newImage2(x + q - 1, y + w - 1, 0) = 255;
                        newImage2(x + q - 1, y + w - 1, 1) = 255;
                        newImage2(x + q - 1, y + w - 1, 2) = 255;
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
                        newImage1(x + q - 1, y + w - 1, 0) = 255;
                        newImage1(x + q - 1, y + w - 1, 1) = 255;
                        newImage1(x + q - 1, y + w - 1, 2) = 255;
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
                newImage(x, y, 0) = 0;
                newImage(x, y, 1) = 0;
                newImage(x, y, 2) = 0;
            }
            else {
                newImage(x, y, 0) = 255;
                newImage(x, y, 1) = 255;
                newImage(x, y, 2) = 255;
            }
        }
    }
    newImage.save_bmp("..\\images\\HMT.bmp");
}

void M2(CImg<unsigned char> &image, std::vector<int> mask, int x, int y) {
    CImg<unsigned char> newImage = image;
    int counter=0;
    do {
        //spyać się pana
    }while(counter!=0);


}