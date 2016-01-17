/********************************************************************************************************
* File         :winner_takeall.cpp                                                                      *
* Purpose      :To find salient region in obtained saliency map                                         *
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
#include "winnertakeall.h"
#include "classifier.h"


/******************************************************
 *                Global Variables                    *
 *****************************************************/
Mat block; //to store current block of pixels
Scalar sum_of_intensity;//to store sum of intensities of each block

int saliency_width; //width of saliency map
int saliency_height; //height of saliency map
char decision='y';

void winner_takeall()
{
    float great=0;
    int pixel_x,pixel_y;
    saliency_width=(saliency_map.cols);
    saliency_height=(saliency_map.rows);
    int i,j;
    int count=0;

    int high,wide;//to keep condition in loop so that we get exact last block

    high=(saliency_height-BLOCK_SIZE);

    wide=(saliency_width-BLOCK_SIZE);

    do
    {
        for(i=0;i<=high;i+=shift_size)
        {
            for(j=0;j<=wide;j+=shift_size)
            {
                Rect roi(i,j,BLOCK_SIZE,BLOCK_SIZE);
                block=saliency_map(roi);
                sum_of_intensity=sum(block);

                //cout<<"intensities in "<<i<<"\t"<<j<<"\t"<<sum_of_intensity.val[0]<<endl;

                if(sum_of_intensity.val[0]>great)
                {
                    great=sum_of_intensity.val[0];
                    pixel_x=i;
                    pixel_y=j;

                }
            }
        }
        //cout<<"pixel locations with greatest intensity are:"<<pixel_x<<" "<<pixel_y<<"\t"<<endl;
        //cout<<"greatest intensity :"<<great<<endl;
        Point p1(pixel_x,pixel_y);
        Point p2(pixel_x+(BLOCK_SIZE-1),pixel_y+(BLOCK_SIZE-1));
        //Scalar color(255,255,255);
        rectangle(saliency_map,p1,p2,CV_RGB(255,255,255),1,8,0);
        rectangle(display,p1,p2,CV_RGB(255,0,0),1,8,0);

        if(count==0)
        {
            waitKey(500);
            imshow("salient most inhibition",saliency_map);
            waitKey(500);
            classify(pixel_x,pixel_y);
        }

        else if(count==1)
        {
            waitKey(500);
            imshow("2nd most salient inhibition",saliency_map);
            waitKey(500);
            classify(pixel_x,pixel_y);
        }

        else if(count==2)
        {
            waitKey(500);
            imshow("3 most salient inhibition",saliency_map);
            waitKey(500);
           classify(pixel_x,pixel_y);
        }

        else if(count==3)
        {
            waitKey(500);
            imshow("4 most salient inhibition",saliency_map);
            waitKey(500);
            classify(pixel_x,pixel_y);
        }
        else if(count==4)
        {
            waitKey(500);
            imshow("5 most salient inhibition",saliency_map);
            waitKey(500);
            classify(pixel_x,pixel_y);
        }
        else if(count==5)
        {
            waitKey(500);
            imshow("6th most salient inhibition",saliency_map);
            waitKey(500);
            classify(pixel_x,pixel_y);
        }

        count++;

           for(i=pixel_y;i<(pixel_y+BLOCK_SIZE);i++)//(pixel_x+BLOCK_SIZE)
            {
                for(j=pixel_x;j<(pixel_x+BLOCK_SIZE);j++)
                {


                     saliency_map.at<float>(i,j)=0;


                }
            }

            great=0;
            pixel_x=0;
            pixel_y=0;

    }while(count<6);
     imshow("total-regions",display);
}
