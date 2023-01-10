#include <iostream>
#include "CImg.h"
#include "popl.hpp"

#include "task1/B.h"
#include "task1/E.h"
#include "task1/G.h"
#include "task1/N.h"

#include "task2/H.h"
#include "task2/C.h"
#include "task2/O.h"
#include "task2/S.h"

#include "task3/M.h"
#include "task3/R.h"

#include "task4/T.h"
using namespace cimg_library;
using namespace popl;
using namespace std;

int main(int argc, char *argv[]) {

    OptionParser op("Allowed options");

    //help
    auto help_option_ = op.add<Switch>("", "help", "produce help message");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Task1
    //B.h
    auto brightness_ = op.add<Value<int>>("", "brightness", "Brigness modification");
    auto contrast_ = op.add<Value<float>>("", "contrast", "Contrast modification");
    auto negative_ = op.add<Switch>("", "negative", "Turn image into negative");

    //G.h
    auto hflip_ = op.add<Switch>("", "hflip", "Horizontal Flip");
    auto vflip_ = op.add<Switch>("", "vflip", "Vertical Flip");
    auto dflip_ = op.add<Switch>("", "dflip", "Diagonal Flip");
    auto shrink_ = op.add<Value<int>>("", "shrink", "Image Shrinking");
    auto enlarge_ = op.add<Value<int>>("", "enlarge", "Image enlarging");

    //N.h
    auto alpha_ = op.add<Value<int>>("", "alpha", "Denoising image with Alpha-trimmed mean filter");
    auto gmean_ = op.add<Value<int>>("", "gmean", "Denoising image with Geometric mean filter");
    auto max_ = op.add<Value<int>>("", "max", "Denoising image with Max filter");

    //E.h
    auto allE_ = op.add<Switch>("", "allE", "All E similarities");
    auto mse_ = op.add<Switch>("", "mse", "Mean square error");
    auto pmse_ = op.add<Switch>("", "pmse", "Peak mean square error");
    auto snr_ = op.add<Switch>("", "snr", "Signal to noise ratio");
    auto psnr_ = op.add<Switch>("", "psnr", "Peak signal to noise ratio");
    auto md_ = op.add<Switch>("", "md", "Maximum difference");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Task2
    //H.h
    auto histogram_ = op.add<Value<int>>("", "histogram", "Creating histogram from image");
    auto hexponent_ = op.add<Value<float>>("", "hexponent", "Draws an exponential final probability density function");

    //C.h
    auto allC_ = op.add<Value<int>>("", "allC", "Calculate all characteristic for given image");
    auto mean_ = op.add<Value<int>>("", "cmean", "Calculate mean");
    auto variance_ = op.add<Value<int>>("", "cvariance", "Calculate variance");
    auto deviation_ = op.add<Value<int>>("", "cstdev", "Calculate deviation");
    auto variationCoefficient_ = op.add<Value<int>>("", "cvarcoi", "Calculate variation coefficient !");
    auto asymmetryCoefficient_ = op.add<Value<int>>("", "cflyco", "Calculate asymmetry coefficient");
    auto flatteningCoefficient_ = op.add<Value<int>>("", "casyco", "Calculate flattening coefficient");
    auto variationCoefficientII_ = op.add<Value<int>>("", "cvarcoii", "Calculate variation coefficient II");
    auto entropy_ = op.add<Value<int>>("", "centropy", "Calculate entropy");

    //S.h
    auto extraction_of_deteials_ = op.add<Value<int>>("", "sexdetii", " Linear image filtration algorithm in spatial domain basing on convolution");
    auto optimized_extraction_of_deteials_ = op.add<Switch>("", "optsexdetii", "Linear image filtration algorithm in spatial domain basing on convolution, but optimized");

    //O.h
    auto uolis_operator_ = op.add<Switch>("", "ouolis", "Non-linear image filtration algorithm in spatial domain");
    auto sobel_operator_ = op.add<Switch>("", "sobel", "Non-linear image filtration algorithm in spatial domain");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Task3
    //M.h
    auto dilation_ = op.add<Switch>("", "dilation", "Dilation");
    auto erosion_ = op.add<Switch>("", "erosion", "Erosion");
    auto opening_ = op.add<Switch>("", "opening", "Opening");
    auto closing_ = op.add<Switch>("", "closing", "Closing");
    auto HMT_ = op.add<Switch>("", "HMT", "HMT");
    auto M2_ = op.add<Switch>("", "M2", "M2");
    auto M1_1_ = op.add<Switch>("", "M1_1", "Closing");
    auto M1_2_ = op.add<Switch>("", "M1_2", "Closing");
    auto M1_3_ = op.add<Switch>("", "M1_3", "Closing");

    //R.h
    auto region_growing_merging_ = op.add<Switch>("", "RGM", "Closing");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Task4
    //T.h
    auto DFT_ = op.add<Switch>("", "DFT", "Discrete Furier Transform");
    auto FFT_ = op.add<Switch>("", "FFT", "Fast Furier Transform");
    auto IDFT_ = op.add<Switch>("", "IDFT", "Inverse Discrete Furier Transform");
    auto IFFT_ = op.add<Switch>("", "IFFT", "Inverse Fast Furier Transform");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    op.parse(argc, argv);

    //help
    if (help_option_->is_set())
        cout << op << "\n";
    else
    {
        try{
            CImg<unsigned char> origin(argv[1]);
            CImg<unsigned char> test;
            if(mse_->is_set() || pmse_->is_set() || snr_->is_set() || psnr_->is_set() || md_->is_set() || allE_->is_set())
                test = CImg(argv[2]);
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //Task1
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
            if(allE_->is_set())
            {
                std::cout<<"Original image: "<<argv[1]<<std::endl;
                std::cout<<"Test image: "<<argv[2]<<std::endl;
                std::cout<<"Mean square error: "<<mean_square_error(origin,test)<<std::endl;
                std::cout<<"Peak mean error: "<<peak_mean_square_error(origin,test)<<std::endl;
                std::cout<<"Signal to noise radio: "<<signal_to_noise_radio(origin,test)<<std::endl;
                std::cout<<"Peak signal to noise radio: "<<peak_signal_to_noise_radio(origin,test)<<std::endl;
                std::cout<<"Maximum difference: "<<maximum_difference(origin,test)<<std::endl;
            }
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
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //Task2
            //H.h
            if(histogram_->is_set())
                save_histogram(origin, histogram_->value());
            if(hexponent_->is_set())
                exponential_final_probability_density(origin, hexponent_->value(), 0.15);

            //C.h
            if(allC_->is_set())
            {
                std::cout<<"Mean: "<<mean(origin, allC_->value())<<std::endl;
                std::cout<<"Variance: "<<variance(origin, allC_->value())<<std::endl;
                std::cout<<"Standard deviation: "<<deviation(origin, allC_->value())<<std::endl;
                std::cout<<"Variation coefficient I: "<<variationCoefficient(origin, allC_->value())<<std::endl;
                std::cout<<"Asymmetry coefficient: "<<asymmetryCoefficient(origin, allC_->value())<<std::endl;
                std::cout<<"Flattening coefficient: "<<flatteningCoefficient(origin, allC_->value())<<std::endl;
                std::cout<<"Variation coefficient II: "<<variationCoefficientII(origin, allC_->value())<<std::endl;
                std::cout<<"Information source entropy: "<<entropy(origin, allC_->value())<<std::endl;
            }
            if(mean_->is_set())
                mean(origin, mean_->value());
            if(variance_->is_set())
                variance(origin, variance_->value());
            if(deviation_->is_set())
                deviation(origin, deviation_->value());
            if(variationCoefficient_->is_set())
                variationCoefficient(origin, variationCoefficient_->value());
            if(asymmetryCoefficient_->is_set())
                asymmetryCoefficient(origin, asymmetryCoefficient_->value());
            if(flatteningCoefficient_->is_set())
                flatteningCoefficient(origin, flatteningCoefficient_->value());
            if(variationCoefficientII_->is_set())
                variationCoefficientII(origin, variationCoefficientII_->value());
            if(entropy_->is_set())
                entropy(origin, entropy_->value());

            //S.h
            vector<int> vec = {-1,-1,-1,1,-2,1,1,1,1};
            if(extraction_of_deteials_->is_set())
                extraction_of_details(origin, extraction_of_deteials_->value(), vec);
            if(optimized_extraction_of_deteials_->is_set())
                optimized_extraction_of_details(origin);

            //O.h
            if(uolis_operator_->is_set())
                uolis_operator(origin);
            if(sobel_operator_->is_set())
                sobel_operator(origin);
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //Task3
            //M.h
            vector<int> mask = {0,1,0,1,1,1,0,1,0};
            vector<int> maskk1 = {1,2,2,1,0,2,1,2,2};
            vector<int> maskk2 = {1,1,1,2,0,2,2,2,2};
            vector<int> maskk3 = {2,2,1,2,0,1,2,2,1};
            vector<int> maskk4 = {2,2,2,2,0,2,1,1,1};
            if(dilation_->is_set())
                dilation(origin,mask);
            if(erosion_->is_set())
                erosion(origin,mask);
            if(opening_->is_set())
                opening(origin,mask);
            if(closing_->is_set())
                closing(origin,mask);
            if(HMT_->is_set())
                HMT(origin,maskk1);

            int x = 250;
            int y = 250;
            mask = {1,1,1,1,1,1,1,1,1};
            if(M2_->is_set())
                M2(origin,mask,x,y);
            if(M1_1_->is_set())
                M1_1(origin,mask);
            if(M1_2_->is_set())
                M1_2(origin,mask);
            if(M1_3_->is_set())
                M1_3(origin,mask);

            //R.h
            if(region_growing_merging_->is_set())
                region_growing_merging(origin,mask);
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //Task4
            //T.h
            if(DFT_->is_set())
                DFT(origin);
            if(IDFT_->is_set())
                IDFT(DFT(origin));
            if(FFT_->is_set())
                FFT(origin);
            if(IFFT_->is_set())
                IFFT(origin);
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////

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