#ifndef COLOR_FEATURE_H
#define COLOR_FEATURE_H

#include<cv.h>
#include<cxcore.h>
using namespace cv;


extern Mat r,g,b,y;    //



//TO FIND CENTER SURROUND DIFF RG AND BY

extern vector<Mat> cr_pyramid,cg_pyramid,cb_pyramid,cy_pyramid;
extern Mat temp;
extern Mat cr_cent;
extern Mat cr_srnd1,cr_srnd2;
extern Mat cg_cent;
extern Mat cg_srnd1,cg_srnd2;
extern Mat crg_fmap1;

void color_feature();


#endif // COLOR_FEATURE_H
