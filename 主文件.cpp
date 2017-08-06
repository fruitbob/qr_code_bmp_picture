/**/
#pragma pack(2) 
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "QrCode.hpp"
#include "bmp_output.cpp"

using namespace std;
using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
/*用于向BMP图像中写入二维码数据并生成BMP格式图片*/
void saveBitmap(const char *name, const QrCode &test)
{
	const int w = 80;//图片边长
	const int height = w;  // 图像高 
	const int width = w;  //宽度 
	const int size = height * width * 3;//图像数据总大小  
	double x = 0, y = 0, x1 = 0, y1 = 0;  //像素坐标 ，图像从左刀右，从上到下扫描，数学二位坐标系 
	int index = 0;  //像素点位置 
	const double side = w / 4;

	BITMAPFILEHEADER fileHeader;  //建立一个bmp数据 

	fileHeader.bfType = 0x4D42; // bmp文件标志 
	fileHeader.bfReserved1 = 0;  //预留的两个变量，设为0 
	fileHeader.bfReserved2 = 0;  //
								 //图像大小：文件头+信息头+调色板（这里未用到）+图像数据 
	fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
	//文件开始到图像数据储存位置区间大小：文件头+信息头+调色板（这里未用到）  
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// 初始化数据，设为0 
	BITMAPINFOHEADER bitmapHeader = { 0 };

	bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);//  信息头大小 
	bitmapHeader.biHeight = height;  //图像宽度 
	bitmapHeader.biWidth = width;  //图像高度 
	bitmapHeader.biPlanes = 1;  //目标设备级别，必须为1 
	bitmapHeader.biBitCount = 24; // 
	bitmapHeader.biSizeImage = size;//图像数据大小 
	bitmapHeader.biCompression = 0; //压缩量 
	bitmapHeader.biXPelsPerMeter = 1;
	bitmapHeader.biYPelsPerMeter = 1;

	BYTE *bits = (BYTE *)malloc(size);  //开辟内存，储存图像数据 

	memset(bits, 0xFF, size);  //将bits指针后size个字节内的数据改为0xFF 
							   //即将图像数据初始化为白色 
	for (x = 0; x <= test.size; x = x + 1)
	{
		for (y = 0; y <= test.size; y += 1)
		{

			index = (int)((y + side) * w * 3 + (x + side) * 3);
			if (test.getModule(x, y) == 1)
			{
				bits[index + 0] = 1;
				bits[index + 1] = 1;
				bits[index + 2] = 1;
			}
		}
	}

	FILE *output = fopen(name, "wb");  // 读写方式打开文件，没有就创建 

	if (output == NULL)
	{
		printf("Cannot open file!\n");
	}
	else
	{
		fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output); //写入文件头 
		fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);//写入信息头 
		fwrite(bits, size, 1, output);//写入图像数据  
		fclose(output); //关闭文件 
		printf("%s二维码生成完毕\n",name);
	}
}
int main()
{
	string text0, name0,name1;
	string bmp = ".bmp";
	
	printf("输入二维码名称");
	cin  >> name0;
	printf("输入字符串");
	cin >> text0;

	name1 = name0 + bmp;
	const char *text = text0.c_str();
	const char *name = name1.c_str();

	const QrCode qr = QrCode::encodeText(text, QrCode::Ecc::HIGH);
	saveBitmap(name, qr);
	return 0;
}
