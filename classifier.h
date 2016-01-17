#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include<iostream>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>
using namespace std;
using namespace cv;

void classify(int pixel_x,int pixel_y);
void calculate_sum(Rect roi,Mat img);

#endif // CLASSIFIER_H
