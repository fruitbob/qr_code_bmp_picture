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
    WORD    bfType; // ͼ������ 
    DWORD   bfSize; 
    //�ļ���ʼ��ͼ�����ݴ���λ�������С���ļ�ͷ+��Ϣͷ+��ɫ��  
    WORD    bfReserved1; //Ԥ����������������Ϊ0 
    WORD    bfReserved2;  
    DWORD   bfOffBits; //    
	 //�ļ���ʼ��ͼ�����ݴ���λ�������С���ļ�ͷ+��Ϣͷ+��ɫ��+ͼ������  

} BITMAPFILEHEADER;  //����bmp�ļ�ͷ��Ϣ�Ľṹ�� 
  
typedef struct {  
    DWORD      biSize;//��Ϣͷ��С  
    LONG       biWidth; //ͼ���ȣ�������Ϊ��λ�� 
    LONG       biHeight;   
    WORD       biPlanes;  //Ŀ���豸���𣬱���Ϊ1 
    WORD       biBitCount;  
	//ɫ��������ͣ�����Ϊ����ɫ��1����16ɫ��4����256ɫ��8�������ɫ��24���� 
    DWORD      biCompression;  
	//ѹ����ʽ�������ǣ�0����ѹ����1��2�� 
    DWORD      biSizeImage;  //����ͼ�����ݴ�С 
    LONG       biXPelsPerMeter;  //ˮƽ�ֱ��ʣ���λ������/�ף� 
    LONG       biYPelsPerMeter;  //��ֱ�ֱ��� 
    DWORD      biClrUsed;  //BMPͼ��ʹ�õ���ɫ
    DWORD      biClrImportant;  //��Ҫ����ɫ��
} BITMAPINFOHEADER;  //�ļ���Ϣͷ 
typedef struct tagRGBQUAD { 
BYTE    rgbBlue; 
BYTE    rgbGreen; 
BYTE    rgbRed; 
BYTE    rgbReserved; 
} RGBQUAD;//��ɫ�� 

 
