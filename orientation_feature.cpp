/********************************************************************************************************
* File         :orientation_feature.cpp                                                                 *
* Purpose      :To find orientations features(o90fm1,o90fm2,o135fm1)                                    *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/
/*****************************PreDefined*******************************************************/
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
#include<math.h>
using namespace std;
using namespace cv;

/*****************************User Defined******************************************************/
#include"initial_variables.h"
#include "orientation_feature.h"


/******************************************************
 *                Global Variables                    *
 *****************************************************/
int orient_loop;
int kernel_size=21;
int pos_sigma= 5;
int pos_lm = 50;
int pos_th[2] ={90,135};
int pos_psi = 90;
Mat grayscale_img;//to store gray scale image
Mat convol_src;//to store convolution source
Mat dest;//to store intermediate image after convolution
Mat final_dest[2];//to store final image after
Mat temp_orient;


/******************************To store pyramids******************************************/
  vector<Mat> orient90_pyr,orient135_pyr;

//to store center surroung differences
  Mat orient90_cent,orient135_cent;//centers for each orientation
  Mat orient90_srnd1,orient90_srnd2;//surrounds
  Mat orient135_srnd1;

 //to store center surroung differences

   Mat orient90_fmap1,orient90_fmap2;
   Mat orient135_fmap1;


Mat mkKernel(int ks, double sig, double th, double lm, double ps)
{

    int hks = (ks-1)/2;
    double theta = th*CV_PI/180;
    double psi = ps*CV_PI/180;
    double del = 2.0/(ks-1);
    double lmbd = lm;
    double sigma = sig/ks;
    double x_theta;
    double y_theta;
    Mat kernel(ks,ks, CV_32F);

    for (int y=-hks; y<=hks; y++)
    {
        for (int x=-hks; x<=hks; x++)
        {
            x_theta = x*del*cos(theta)+y*del*sin(theta);
            y_theta = -x*del*sin(theta)+y*del*cos(theta);
            kernel.at<float>(hks+y,hks+x) = (float)exp(-0.5*(pow(x_theta,2)+pow(y_theta,2))/pow(sigma,2))* cos(2*CV_PI*x_theta/lmbd + psi);
        }
    }
    return kernel;
}

void process(int theta_temp)
{
    double sig = pos_sigma;
    double lm = 0.5+pos_lm/100.0;
    double th = theta_temp;
    double ps = pos_psi;

    Mat kernel = mkKernel(kernel_size, sig, th, lm, ps);

    filter2D(convol_src,dest, CV_32F, kernel); //convolution of grayscale image with kernel and stored in dest

    switch(orient_loop)
    {

        case 0:

            pow(dest, 2.0, final_dest[orient_loop]);

            //imshow("Mag_90", final_dest[orient_loop]);
            break;

        case 1:

            pow(dest, 2.0, final_dest[orient_loop]);

            //imshow("Mag_135", final_dest[orient_loop]);
            break;
    }


}
void find_pyramids()
{
    // building pyramids

    buildPyramid(final_dest[0],orient90_pyr,3);
    buildPyramid(final_dest[1],orient135_pyr,3);


}

//90 degree map
void find_centersurround_90()
{
    Mat temp_orient90_fmap1,temp_orient90_fmap2;
    orient90_cent=orient90_pyr[1];

    pyrUp(orient90_pyr[2],orient90_srnd1,orient90_cent.size());

    pyrUp(orient90_pyr[3],temp_orient,orient90_pyr[2].size());

    pyrUp(temp_orient,orient90_srnd2,orient90_cent.size());

    absdiff(orient90_cent,orient90_srnd1,temp_orient90_fmap1);
    absdiff(orient90_cent,orient90_srnd2,temp_orient90_fmap2);

    normalize(temp_orient90_fmap1,orient90_fmap1,255,0,NORM_MINMAX,-1);
    normalize(temp_orient90_fmap2,orient90_fmap2,255,0,NORM_MINMAX,-1);

    imshow("orient90_fmap1",orient90_fmap1);
    imshow("orient90_fmap2",orient90_fmap2);

}
//135 degree maps
void find_centersurround_135()
{
    Mat temp_orient135_fmap1;

    orient135_cent=orient135_pyr[1];

    pyrUp(orient135_pyr[2],orient135_srnd1,orient135_cent.size());

    absdiff(orient135_cent,orient135_srnd1,temp_orient135_fmap1);


    normalize(temp_orient135_fmap1,orient135_fmap1,255,0,NORM_MINMAX,-1);



    imshow("orient135_fmap1",orient135_fmap1);


}

void orientation_feature()
{
   cvtColor(reduced_img, grayscale_img, CV_BGR2GRAY);



   double min,max;
   minMaxLoc(grayscale_img,&min,&max);


   grayscale_img.convertTo(convol_src, CV_32F,1.0/max,0);

   if (!kernel_size%2)
    {
        kernel_size+=1;
    }


   //function find orientation maps

    for(orient_loop=0;orient_loop<2;orient_loop++)
    {

        process(pos_th[orient_loop]);

    }

   find_pyramids();
   find_centersurround_90();
   find_centersurround_135();
}
