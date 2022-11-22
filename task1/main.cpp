#include <iostream>
#include "CImg.h"
#include "popl.hpp"
#include "task1/B.h"
#include "task1/N.h"
#include "task1/G.h"
#include "task1/E.h"
#include "task2/H.h"
#include "task2/C.h"
#include "task2/O.h"
#include "task2/S.h"
using namespace cimg_library;
using namespace popl;
using namespace std;

int main(int argc, char *argv[]) {

    OptionParser op("Allowed options");

    //help
    auto help_option_   = op.add<Switch>("", "help", "produce help message");

    //Task1
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
    auto max_  = op.add<Value<int>>("", "max", "Denoising image with Max filter");

    //E.h
    auto mse_  = op.add<Switch>("", "mse", "Mean square error");
    auto pmse_  = op.add<Switch>("", "pmse", "Peak mean square error");
    auto snr_  = op.add<Switch>("", "snr", "Signal to noise ratio");
    auto psnr_  = op.add<Switch>("", "psnr", "Peak signal to noise ratio");
    auto md_  = op.add<Switch>("", "md", "Maximum difference");

    //Task2
    //H.h
    auto histogram_  = op.add<Value<int>>("", "histogram", "Creating histogram from image");
    auto hexponent_  = op.add<Value<int>>("", "hexponent", "Draws an exponential final probability density function");

    //C.h
    auto mean_  = op.add<Value<int>>("", "cmean", "Calculate mean");
    auto variance_  = op.add<Value<int>>("", "cvariance", "Calculate variance");
    auto deviation_  = op.add<Value<int>>("", "cstdev", "Calculate deviation");
    auto variationCoefficient_  = op.add<Value<int>>("", "cvarcoi", "Calculate variation coefficient !");
    auto asymmetryCoefficient_  = op.add<Value<int>>("", "cflyco", "Calculate asymmetry coefficient");
    auto flatteningCoefficient_  = op.add<Value<int>>("", "casyco", "Calculate flattening coefficient");
    auto variationCoefficientII_  = op.add<Value<int>>("", "cvarcoii", "Calculate variation coefficient II");
    auto entropy_  = op.add<Value<int>>("", "centropy", "Calculate entropy");

    //S.h
    auto extraction_of_deteials_  = op.add<Value<int>>("", "sexdetii", " Linear image filtration algorithm in spatial domain basing on convolution");

    //O.h
    auto uolis_operator_  = op.add<Value<int>>("", "ouolis", "Non-linear image filtration algorithm in spatial domain");

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
            if (max_->is_set())
                maxFilter(origin,max_->value());

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

            //H.h
            if(histogram_->is_set())
                save_histogram(origin, histogram_->value());
            if(hexponent_->is_set())
                exponential_final_probability_density(origin, 0,hexponent_->value(),0.05);

            //C.h
            if(mean_->is_set())
                mean(origin, histogram_->value());
            if(variance_->is_set())
                variance(origin, histogram_->value());
            if(deviation_->is_set())
                deviation(origin, histogram_->value());
            if(variationCoefficient_->is_set())
                variationCoefficient(origin, histogram_->value());
            if(asymmetryCoefficient_->is_set())
                asymmetryCoefficient(origin, histogram_->value());
            if(flatteningCoefficient_->is_set())
                flatteningCoefficient(origin, histogram_->value());
            if(variationCoefficientII_->is_set())
                variationCoefficientII(origin, histogram_->value());
            if(entropy_->is_set())
                entropy(origin, histogram_->value());

            //S.h
            if(extraction_of_deteials_->is_set())
                extraction_of_deteials(origin, extraction_of_deteials_->value());

            //O.h
            if(uolis_operator_->is_set())
                uolis_operator(origin, uolis_operator_->value());


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