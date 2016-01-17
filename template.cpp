#include "template.h"


#include<cv.h>
#include<highgui.h>
#include<cxcore.h>

#include<iostream>

using namespace cv;
using namespace std;
void template_match(Mat source_image)
{
    Mat template_image1, template_image2, template_image3, reduced_template_image1, reduced_template_image2, reduced_template_image3;
    Mat diff_image1, diff_image2, diff_image3;
    Mat block1, block2, block3;
    Scalar sum_of_matrix1, sum_of_matrix2, sum_of_matrix3;
    int avg1, avg2, avg3;


    template_image1 = imread("/home/rachadal/Documents/documents-export-2013-05-13/crossing.jpg",-1);
    cv::resize(template_image1,reduced_template_image1,Size(32,32),0,0,INTER_LINEAR);
    absdiff(source_image,reduced_template_image1,diff_image1);
    imshow("diff_image",diff_image1);
    Rect roi(0,0,31,31);
    block1 = diff_image1(roi);
    sum_of_matrix1 = sum(block1);
    avg1 = (sum_of_matrix1.val[0]+sum_of_matrix1.val[1]+sum_of_matrix1.val[2])/3;


    template_image2 = imread("/home/rachadal/Documents/documents-export-2013-05-13/cycle1.jpg",-1);
    cv::resize(template_image2,reduced_template_image2,Size(32,32),0,0,INTER_LINEAR);
    absdiff(source_image,reduced_template_image2,diff_image2);
    imshow("diff_image",diff_image2);
    block2 = diff_image2(roi);
    sum_of_matrix2 = sum(block2);
    avg2 = (sum_of_matrix2.val[0]+sum_of_matrix2.val[1]+sum_of_matrix2.val[2])/3;


    template_image3 = imread("/home/rachadal/Documents/documents-export-2013-05-13/pedestrian.jpg",-1);
    cv::resize(template_image3,reduced_template_image3,Size(32,32),0,0,INTER_LINEAR);
    absdiff(source_image,reduced_template_image3,diff_image3);
    imshow("diff_image",diff_image3);
    block3 = diff_image3(roi);
    sum_of_matrix3 = sum(block3);
    avg3 = (sum_of_matrix3.val[0]+sum_of_matrix3.val[1]+sum_of_matrix3.val[2])/3;


    if((avg1<avg2)&&(avg1<avg3))
    {
            cout<<"CROSSING AHEAD"<<endl;
    }
    if((avg2<avg1)&&(avg2<avg3))
    {
            cout<<"CYCLIST ZONE"<<endl;
    }
    if((avg3<avg1)&&(avg3<avg2))
    {
            cout<<"PEDESTRIAN CROSSING"<<endl;
    }
   }
