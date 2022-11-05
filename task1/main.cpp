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

    OptionParser op("Allowed options");

    //help
    auto help_option_   = op.add<Switch>("", "help", "produce help message");

    //B.h
    auto brightness_ = op.add<Value<int>>("", "brightness", "Brigness modification");
    auto contrast_ = op.add<Value<int>>("", "contrast", "Contrast modification");
    auto negative_  = op.add<Switch>("", "negative", "Turn image into negative");

    //G.h
    auto hflip_  = op.add<Switch>("", "hflip", "Horizontal Flip");
    auto vflip_  = op.add<Switch>("", "vflip", "Vertical Flip");
    auto dflip_  = op.add<Switch>("", "dflip", "Diagonal Flip");
    auto shrink_ = op.add<Value<int>>("", "shrink", "Image Shrinking");
    auto enlarge_ = op.add<Value<int>>("", "enlarge", "Image enlarging");

    //N.h
    auto alpha_  = op.add<Value<int>>("", "alpha", "Denoising image with Alpha-trimmed mean filter");
    auto gmean_  = op.add<Value<int>>("", "gmean", "Denoising image with Geometric mean filter");

    //E.h
    auto mse_  = op.add<Switch>("", "mse", "Mean square error");
    auto pmse_  = op.add<Switch>("", "pmse", "Peak mean square error");
    auto snr_  = op.add<Switch>("", "snr", "Signal to noise ratio");
    auto psnr_  = op.add<Switch>("", "psnr", "Peak signal to noise ratio");
    auto md_  = op.add<Switch>("", "md", "Maximum difference");

    op.parse(argc, argv);

    //help
    if (help_option_->is_set())
        cout << op << "\n";
    else
    {
        try{
            CImg<unsigned char> origin(argv[1]);
            CImg<unsigned char> test;
            if(mse_->is_set() || pmse_->is_set() || snr_->is_set() || psnr_->is_set() || md_->is_set())
                test = CImg(argv[2]);

            //B.h
            if (brightness_->is_set())
                brightness(origin, brightness_->value());
            if (contrast_->is_set())
                contrast(origin, contrast_->value());
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
                alpha_trimmed_mean_filter(origin, alpha_->value());
            if (gmean_->is_set())
                geometric_mean_filter(origin,gmean_->value());

            //E.h
            if (mse_->is_set())
            {
                std::cout<<"Original image: "<<argv[1]<<std::endl;
                std::cout<<"Test image: "<<argv[2]<<std::endl;
                std::cout<<"Mean square error: "<<mean_square_error(origin,test)<<std::endl;
            }
            if (pmse_->is_set())
            {
                std::cout<<"Original image: "<<argv[1]<<std::endl;
                std::cout<<"Test image: "<<argv[2]<<std::endl;
                std::cout<<"Peak mean error: "<<peak_mean_square_error(origin,test)<<std::endl;
            }
            if (snr_->is_set())
            {
                std::cout<<"Original image: "<<argv[1]<<std::endl;
                std::cout<<"Test image: "<<argv[2]<<std::endl;
                std::cout<<"Signal to noise radio: "<<signal_to_noise_radio(origin,test)<<std::endl;
            }
            if (psnr_->is_set())
            {
                std::cout<<"Original image: "<<argv[1]<<std::endl;
                std::cout<<"Test image: "<<argv[2]<<std::endl;
                std::cout<<"Peak signal to noise radio: "<<peak_signal_to_noise_radio(origin,test)<<std::endl;
            }
            if (md_->is_set())
            {
                std::cout<<"Original image: "<<argv[1]<<std::endl;
                std::cout<<"Test image: "<<argv[2]<<std::endl;
                std::cout<<"Maximum difference: "<<maximum_difference(origin,test)<<std::endl;
            }

        }catch(const CImgIOException& a)
        {
            //std::cout<<CImg exception<<std::endl;
        }
        catch ( ... )
        {
            //std::cout<<other exception<<std::endl;
        }
    }



    return 0;
}