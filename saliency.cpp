/********************************************************************************************************
* File         :saliency.cpp                                                                            *
* Purpose      :To find saliency map(from calculated features)                                          *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/

/*****************************PreDefined*******************************************************/
#include<iostream>
#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
using namespace std;
using namespace cv;

/*****************************User Defined******************************************************/

#include"initial_variables.h"
#include "color_feature.h"
#include "intensity.h"
#include "orientation_feature.h"
#include "saliency.h"

using namespace std;
using namespace cv;

/******************************************************
 *                Global Variables                    *
 *****************************************************/
Mat saliency_map;//to store saliency map

void find_saliency()
{
    int i,j;
    saliency_map=(intensity_consmap+orient90_fmap1+orient90_fmap2+orient135_fmap1+crg_fmap1)/5;

     for(i=0;i<9;i++)
     {
        for(j=110;j<256;j++)
        {
            saliency_map.at<float>(i,j)=0;
        }
     }
     for(i=0;i<14;i++)
     {
        for(j=230;j<256;j++)
        {
            saliency_map.at<float>(i,j)=0;
        }
     }
     imshow("saliency map",saliency_map);

}
