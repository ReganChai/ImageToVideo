﻿// ImageToVidio.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<opencv2/opencv.hpp>
#include<iostream>

#pragma warning(disable:4996)

using namespace std;
using namespace cv;

void Image_To_Video( int m );

int main( )
{
	int frame_count = 1000;
	Image_To_Video( frame_count );            //图像整合成视频

	return 0;
}

void Image_To_Video( int p_num )
{
	char image_name[800];
	string s_image_name;
	//初始化视频编写器
	cv::VideoWriter writer;
	bool isColor = true;    //true
	int frame_fps = 15;
	int frame_width = 640;
	int frame_height = 332;
	using namespace cv;
	string video_name = "E:/视频库/视频集_avi/Trans.avi";
	writer = VideoWriter( video_name, CV_FOURCC( 'X', 'V', 'I', 'D' ), frame_fps, Size( frame_width, frame_height ), isColor );
	namedWindow( "image to video", CV_WINDOW_AUTOSIZE );
	int i = 1;
	Mat img;
	while ( i <= p_num )
	{
		string picture_name = "E:/视频库/视频集/Trans/img/%04d.jpg";
		sprintf( image_name, picture_name, i++ );
		s_image_name = image_name;
		img = imread( s_image_name );//读入图片
		if ( !img.data )            
		{
			cout << "Could not load image file...\n" << endl;
			break;
		}
		if ( !img.empty( ) )                  
			imshow( "image to video", img );

		//写入
		writer.write( img );
		if ( waitKey( 30 ) == 27 )       //ESC：ASCⅡ码27
		{
			cout << "按下ESC键" << endl;
			break;
		}
	}
}
