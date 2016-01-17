/********************************************************************************************************
* File         :mainwindow.cpp                                                                          *
* Purpose      :To handle GUI actions.(signals and slots)                                               *
* Language Used:C++ bindings                                                                            *
* Author(s)    :RaviKiran,Subashini,Barath muthu kumar                                                  *
********************************************************************************************************/
/*****************************PreDefined*******************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QFileDialog>
#include<QDebug>
#include<cv.h>
#include<cxcore.h>
#include<highgui.h>
using namespace cv;

/*****************************User Defined******************************************************/
#include"initial_variables.h"
#include"intensity.h"
#include"color_feature.h"
#include"orientation_feature.h"
#include"saliency.h"
#include "winnertakeall.h"

/******************************************************
 *                Global Variables                    *
 *****************************************************/
Mat original_img;   //to store original image
Mat filtered_img;   //to store filtered image
Mat reduced_img;    //to store reduced image
Mat display;        //to store display image
Mat rgb_channels[3];// 3 MATRICES STORING SEPARATED R,G,B CHANNEL EACH


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->pushButton, SIGNAL (clicked()),this,SLOT(on_pushButton_clicked()));
    connect (ui->pushButton_2, SIGNAL (clicked()),this,SLOT(on_pushButton_2_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int ff=0;

void MainWindow::on_pushButton_clicked()
{
   file = QFileDialog::getOpenFileName(this,
        tr("Open Image"),"/home/ravikiran/Documents/testcodes/signboard/",tr("Image Files (*.png *.jpg *.bmp)"));
    ff++;
    if(ff==1)
    {
    original_img=imread(file.toAscii().data(),-1);
    //imshow("selected img",original_img);
    }
    else
    {
        original_img=imread(file.toAscii().data(),-1);
        imshow("selected img",original_img);
    }
   qDebug()<<file<<endl;
}

void MainWindow::on_pushButton_2_clicked()
{
    GaussianBlur(original_img,filtered_img,Size(3,3),0.5,0.5);//filtering image
    //resizing image
    cv::resize(filtered_img,reduced_img,Size(512,512),0,0,INTER_LINEAR);
    cv::resize(filtered_img,display,Size(256,256),0,0,INTER_LINEAR);
    //imshow("display image",display);

    cv::split(reduced_img,rgb_channels);//splitting to get each channel in RGB seperately

    //processing
    intensity_feature();//to find intensity feature
    color_feature();//to find color-feature
    orientation_feature();//to find orientation-features
    find_saliency();//to find saliency map
    winner_takeall();//to get set of salient regions
    waitKey(0);

}
