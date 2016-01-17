#ifndef WINNERTAKEALL_H
#define WINNERTAKEALL_H

#include<iostream>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>
using namespace std;
using namespace cv;

#define BLOCK_SIZE 32 //size of block is 64*64
#define shift_size 10 //each time moves by 10 pixels either horizontally or vertically

extern Mat block;//to store each block of size 32*32
//extern Mat display;

extern Scalar sum_of_intensity;//to store sum of intensties in each block

void winner_takeall();

#endif // WINNERTAKEALL_H
