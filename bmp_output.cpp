#pragma once
#pragma pack(2) 

 
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"QrCode.hpp"
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std; 
typedef unsigned char  BYTE;  
typedef unsigned short WORD;  
typedef unsigned long  DWORD;  
typedef long    LONG;  
typedef struct {  
    WORD    bfType; // 图形类型 
    DWORD   bfSize; 
    //文件开始到图像数据储存位置区间大小：文件头+信息头+调色板  
    WORD    bfReserved1; //预留的两个变量，设为0 
    WORD    bfReserved2;  
    DWORD   bfOffBits; //    
	 //文件开始到图像数据储存位置区间大小：文件头+信息头+调色板+图像数据  

} BITMAPFILEHEADER;  //定义bmp文件头信息的结构体 
  
typedef struct {  
    DWORD      biSize;//信息头大小  
    LONG       biWidth; //图像宽度（以像素为单位） 
    LONG       biHeight;   
    WORD       biPlanes;  //目标设备级别，必须为1 
    WORD       biBitCount;  
	//色深，像素类型，必须为：单色（1）、16色（4）、256色（8）、真彩色（24）。 
    DWORD      biCompression;  
	//压缩方式，必须是：0，不压缩；1或2； 
    DWORD      biSizeImage;  //整个图像数据大小 
    LONG       biXPelsPerMeter;  //水平分辨率（单位：像素/米） 
    LONG       biYPelsPerMeter;  //竖直分辨率 
    DWORD      biClrUsed;  //BMP图像使用的颜色
    DWORD      biClrImportant;  //重要的颜色数
} BITMAPINFOHEADER;  //文件信息头 
typedef struct tagRGBQUAD { 
BYTE    rgbBlue; 
BYTE    rgbGreen; 
BYTE    rgbRed; 
BYTE    rgbReserved; 
} RGBQUAD;//调色板 

 
