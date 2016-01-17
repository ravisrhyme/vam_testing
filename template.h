#ifndef TEMPLATE_H
#define TEMPLATE_H

#include<cv.h>
#include<highgui.h>
#include<cxcore.h>

using namespace cv;

extern Mat template_image;
extern Mat matched_image;
void template_match(Mat source_image);
    
#endif // TEMPLATE_H
    
