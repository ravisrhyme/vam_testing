/********************************************************************************************************
* File         :cassifier.cpp                                                                           *
* Purpose      :To classify the obtained  salient region(As signboard(SB) or Nonsign-board(NSB))        *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/
/*****************************PreDefined*******************************************************/
#include<iostream>
#include<fstream>
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
#include "winnertakeall.h"
#include "classifier.h"
#include "template.h"

/******************************************************
 *                Global Variables                    *
 *****************************************************/
Mat block_sum;
float sal_feature[6];
int ind;
int cls;//class labels 0 for non signboards and 1 for signboards

void calculate_sum(Rect roi,Mat img)
{
    block_sum=img(roi);
    sum_of_intensity=sum(block_sum);
    sal_feature[ind]=sum_of_intensity.val[0];
    ind++;

}
void classify(int pixel_x,int pixel_y)
{

    Rect roi(pixel_x,pixel_y,BLOCK_SIZE,BLOCK_SIZE);
    ind=0;


    calculate_sum(roi,crg_fmap1);
    calculate_sum(roi,orient135_fmap1);
    calculate_sum(roi,intensity_consmap);
    calculate_sum(roi,intensity_fmap2);
    calculate_sum(roi,orient90_fmap2);
    calculate_sum(roi,orient90_fmap1);

   /* cout<< sal_feature[0]<<"\t";
    cout<< sal_feature[1]<<"\t";
    cout<< sal_feature[2]<<"\t";
    cout<< sal_feature[3]<<"\t";
    cout<< sal_feature[4]<<"\t";
    cout<< sal_feature[5]<<endl;*/

    //classification

    if(sal_feature[0]>70.1667)
    {
        cls=1;
    }
    else
    {
        if(sal_feature[1]<=47.8334)
        {
            cls=0;
        }
        else
        {
            if(sal_feature[2]<=105.951)
            {
                cls=0;
            }
            else
            {
                if(sal_feature[3]<=126.294)
                {
                    cls=1;
                }
                else
                {
                    if(sal_feature[4]>2.41562)
                    {
                        cls=0;
                    }
                    else
                    {
                        if(sal_feature[5]<1.46015)
                        {
                            cls=0;
                        }
                        else
                        {
                            cls=1;
                        }
                    }
                }
            }
        }
    }

    if(cls==1)
    {
        cout<<"class label is sb"<<endl;

        //call for classification label(template matching)


        Mat source_image;
        source_image = Mat(display,roi);
                imshow("sd1",source_image);

        template_match(source_image);

    }
    else
    {
        cout<<"class label is nsb"<<endl;
    }

}//end of function classify()
