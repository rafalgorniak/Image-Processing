#include <iostream>
#include "CImg.h"
#include "B.h"
#include "N.h"
#include "G.h"
#include "E.h"
using namespace cimg_library;

int main(int argc, char *argv[]) {

    CImg<unsigned char> origin(R"(C:\Users\rafal\uczelnia\5 semestr\Image Processing\Image-Processing\task1\images\lena_ok.bmp)");
    CImg<unsigned char> noise(R"(C:\Users\rafal\uczelnia\5 semestr\Image Processing\Image-Processing\task1\images\lena_noise.bmp)");
    CImg<unsigned char> test(R"(C:\Users\rafal\uczelnia\5 semestr\Image Processing\Image-Processing\task1\images\out9.bmp)");

    /*
    if(argv[2]=="--brightness")
        brightness(image,atoi(argv[3]));
    else if(argv[2]=="--contrast")
        contrast(image,atoi(argv[3]));
    else if(argv[2]=="--negative")
        negative(image);

    else if(argv[2]=="--hflip")
        horizontal_flip(image);
    else if(argv[2]=="--vflip")
        vertical_flip(image);
    else if(argv[2]=="--dflip")
        diagonal_flip(image);
    else if(argv[2]=="--shrink" or argv[2]=="--enlarge")
        shrinking_enlargement(image,atoi(argv[3]));

    else if(argv[2]=="--alpha")
        alpha_trimmed_mean_filter(image,atoi(argv[3]));
    else if(argv[2]=="--gmean")
        geometric_mean_filter(image);

    else if(argv[2]=="--mse")
        mean_square_error(image);
    else if(argv[2]=="--pmse")
        peak_mean_square_error(image);
    else if(argv[2]=="--snr")
        signal_to_noise_radio(image);
    else if(argv[2]=="--psnr")
        peak_signal_to_noise_radio(image);
    else if(argv[2]=="--md")
        maximum_difference(image);
    else
        printf("Bad parameter imput");
    */

    //brightness(image);
    //contrast(image);
    //negative(image);
    //horizontal_flip(image);
    //vertical_flip(image);
    //diagonal_flip(image);
    //shrinking_enlargement(image, 2);
    //alpha_trimmed_mean_filter(noise,9);
    geometric_mean_filter(origin);

    /*
    std::cout<<"Error for noise: "<<mean_square_error(origin,noise)<<std::endl;
    std::cout<<"Error for retouch: "<<mean_square_error(origin,test)<<std::endl;
    std::cout<<"Peak error for noise: "<<peak_mean_square_error(origin,noise)<<std::endl;
    std::cout<<"Peak error for retouch: "<<peak_mean_square_error(origin,test)<<std::endl;
    std::cout<<"Signal to noise radio: "<<signal_to_noise_radio(origin,noise)<<std::endl;
    std::cout<<"Signal to noise radio: "<<signal_to_noise_radio(origin,test)<<std::endl;
    std::cout<<"Peak signal to noise radio: "<<peak_signal_to_noise_radio(origin,noise)<<std::endl;
    std::cout<<"Peak signal to noise radio: "<<peak_signal_to_noise_radio(origin,test)<<std::endl;
    std::cout<<"Maximum difference: "<<maximum_difference(origin,noise)<<std::endl;
    std::cout<<"Maximum difference: "<<maximum_difference(origin,test)<<std::endl;
    */

    //++ main.cpp -lgdi32 -o main.exe
    return 0;
}