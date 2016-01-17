#ifndef INITIAL_VARIABLES_H
#define INITIAL_VARIABLES_H

#include<cv.h>
#include<cxcore.h>
using namespace cv;

extern Mat original_img;   //to store original image
extern Mat filtered_img;   //to store filtered image
extern Mat reduced_img;    //to store reduced image
extern Mat display;
extern Mat rgb_channels[3];// 3 MATRICES STORING SEPARATED R,G,B CHANNEL EACH

#endif // INITIAL_VARIABLES_H
