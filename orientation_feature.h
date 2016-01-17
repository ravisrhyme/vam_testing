#ifndef ORIENTATION_FEATURE_H
#define ORIENTATION_FEATURE_H

#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
using namespace cv;

 extern Mat reduced_img; //declared again in main() file

 extern int orient_loop;
 extern int kernel_size;
 extern int pos_sigma;
 extern int pos_lm;
 extern int pos_th[2];
 extern int pos_psi;
 extern Mat grayscale_img;
 extern Mat convol_src;//to store image to be convoluted.
 extern Mat dest;
 extern Mat final_dest[2];

 //to store pyramids
  extern vector<Mat> orient90_pyr,orient135_pyr;

 //to store center surroung differences
  extern Mat orient90_cent,orient135_cent;//centers for each orientation
  extern Mat orient90_srnd1,orient90_srnd2;
  extern Mat orient135_srnd1;

  //to store center surroung differences
   extern Mat orient90_fmap1,orient90_fmap2;
   extern Mat orient135_fmap1;


 void orientation_feature();

 Mat mkKernel(int ks, double sig, double th, double lm, double ps);//to make kernel to convolute in image
 void process(int theta_temp);

 void find_centersurround_90();
 void find_centersurround_135();

#endif // ORIENTATION_FEATURE_H
