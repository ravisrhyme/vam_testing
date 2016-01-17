/********************************************************************************************************
* File:Color_feature.cpp                                                                                *
* Purpose:To find R,G,B components,pyramids and RG -feature map1(as selected by decision tree)          *
* Language Used:C++ bindings                                                                            *
* Author(s):RaviKiran,Subashini,Barath muthu kumar                                                      *
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
#include "color_feature.h"
#include"initial_variables.h"

/******************************************************
 *                Global Variables                    *
 *****************************************************/
Mat r,g,b,y; //to store r,g,b,y components.

vector<Mat> cr_pyramid,cg_pyramid,cb_pyramid,cy_pyramid;//to store pyramids

Mat cr_cent;
Mat cr_srnd1,cr_srnd2;
Mat cg_cent;
Mat cg_srnd1,cg_srnd2;
Mat crg_fmap1;

void color_feature()
{


      Mat temp;
      double min,max;//local variable to find min and max in each map

      Mat temp_crg_fmap1;//to store feature maps temporarily before conversion to 0-1 scale.


     r=((rgb_channels[0]-(rgb_channels[1]+rgb_channels[2]))/2);

     g=((rgb_channels[1]-(rgb_channels[0]+rgb_channels[2]))/2);

     b=((rgb_channels[2]-(rgb_channels[0]+rgb_channels[1]))/2);

     y=rgb_channels[0]+rgb_channels[1]-2*(abs(rgb_channels[0]-rgb_channels[1])+rgb_channels[2]);

/***********************************Pyramid construction*****************************************/
        buildPyramid(r,cr_pyramid,3);
        buildPyramid(g,cg_pyramid,3);


/*** Upscaling pyramids for Red-component pyramids and fixing center and surround*******/
              cr_cent=cr_pyramid[1];
              pyrUp(cr_pyramid[2],cr_srnd1,cr_cent.size());
              pyrUp(cr_pyramid[3],temp,cr_pyramid[2].size());
              pyrUp(temp,cr_srnd2,cr_cent.size());


/****Upscaling pyramids for Green-component pyramids and fixing center and surround*******/

              cg_cent=cg_pyramid[1];

              pyrUp(cg_pyramid[2],cg_srnd1,cg_cent.size());
              pyrUp(cg_pyramid[3],temp,cg_pyramid[2].size());
              pyrUp(temp,cg_srnd2,cg_cent.size());

/**********************CENTER SURROUND DIFF FR RG***************************************/

              absdiff((cr_cent-cg_cent),(cg_srnd1-cr_srnd1),temp_crg_fmap1);

             minMaxLoc(temp_crg_fmap1,&min,&max);
             temp_crg_fmap1.convertTo(crg_fmap1, CV_32F,1.0/max,0);
             imshow("RG-fmap1",crg_fmap1);


}
