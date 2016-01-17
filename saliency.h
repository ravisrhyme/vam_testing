#ifndef SALIENCY_H
#define SALIENCY_H

#include<cv.h>
#include<highgui.h>
#include<cxcore.h>
using namespace cv;

extern Mat saliency_map;//to store saliency map

void find_saliency();

#endif // SALIENCY_H
