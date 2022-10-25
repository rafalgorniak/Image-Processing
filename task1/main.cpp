#include <iostream>
#include "CImg.h"
#include "popl.hpp"
#include "B.h"
#include "N.h"
#include "G.h"
#include "E.h"
using namespace cimg_library;
using namespace popl;
using namespace std;

int main(int argc, char *argv[]) {

    //++ main.cpp -lgdi32 -o main.exe

    OptionParser op("Allowed options");

    //help
    auto help_option_   = op.add<Switch>("", "help", "produce help message");

    //B.h
    auto brightness_ = op.add<Value<int>>("", "brightness", "Brigness modification",20);
    auto contrast_ = op.add<Value<int>>("", "contrast", "Contrast modification",20);
    auto negative_  = op.add<Switch>("", "negative", "Turn image into negative");

    //G.h
    auto hflip_  = op.add<Switch>("", "hflip", "Horizontal Flip");
    auto vflip_  = op.add<Switch>("", "vflip", "Vertical Flip");
    auto dflip_  = op.add<Switch>("", "dflip", "Diagonal Flip");
    auto shrink_ = op.add<Value<int>>("", "shrink", "Image Shrinking",2);
    auto enlarge_ = op.add<Value<int>>("", "enlarge", "Image enlarging",2);

    //N.h
    auto alpha_  = op.add<Switch>("", "alpha", "Denoising image with Alpha-trimmed mean filter");
    auto gmean_  = op.add<Switch>("", "gmean", "Denoising image with Geometric mean filter");

    //E.h
    auto mse_  = op.add<Switch>("", "mse", "Mean square error");
    auto pmse_  = op.add<Switch>("", "pmse", "Peak mean square error");
    auto snr_  = op.add<Switch>("", "snr", "Peak mean square error");
    auto psnr_  = op.add<Switch>("", "psnr", "Peak signal to noise ratio");
    auto md_  = op.add<Switch>("", "md", "Maximum difference");

    op.parse(argc, argv);

    CImg<unsigned char> origin(argv[1]);
    //CImg<unsigned char> noise(R"(C:\Users\rafal\uczelnia\5 semestr\Image Processing\Image-Processing\task1\images\lenac_normal2.bmp)");
    if(mse_->is_set() || pmse_->is_set() || snr_->is_set() || psnr_->is_set() || md_->is_set())
        CImg<unsigned char> test(argv[2]);

    //help
    if (help_option_->is_set())
        cout << op << "\n";

    //B.h
    if (brightness_->is_set())
        brightness(origin, brightness_->value());
    if (contrast_->is_set())
        brightness(origin, contrast_->value());
    if (negative_->is_set())
        negative(origin);

    //G.h
    if (hflip_->is_set())
        horizontal_flip(origin);
    if (vflip_->is_set())
        vertical_flip(origin);
    if (dflip_->is_set())
        diagonal_flip(origin);
    if (shrink_->is_set())
        shrinking(origin, shrink_->value());
    if (enlarge_->is_set())
        enlargement(origin, enlarge_->value());

    //N.h
    if (alpha_->is_set())
        alpha_trimmed_mean_filter(origin);
    if (gmean_->is_set())
        geometric_mean_filter(origin);

    //E.h
    CImg<unsigned char> test;
    if (mse_->is_set())
        std::cout<<"Mean square error: "<<mean_square_error(origin,test)<<std::endl;
    if (pmse_->is_set())
        std::cout<<"Peak mean error: "<<peak_mean_square_error(origin,test)<<std::endl;
    if (snr_->is_set())
        std::cout<<"Signal to noise radio: "<<signal_to_noise_radio(origin,test)<<std::endl;
    if (psnr_->is_set())
        std::cout<<"Peak signal to noise radio: "<<peak_signal_to_noise_radio(origin,test)<<std::endl;
    if (md_->is_set())
        std::cout<<"Maximum difference: "<<maximum_difference(origin,test)<<std::endl;





    return 0;
}