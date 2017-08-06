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
/*������BMPͼ����д���ά�����ݲ�����BMP��ʽͼƬ*/
void saveBitmap(const char *name, const QrCode &test)
{
	const int w = 80;//ͼƬ�߳�
	const int height = w;  // ͼ��� 
	const int width = w;  //��� 
	const int size = height * width * 3;//ͼ�������ܴ�С  
	double x = 0, y = 0, x1 = 0, y1 = 0;  //�������� ��ͼ������ң����ϵ���ɨ�裬��ѧ��λ����ϵ 
	int index = 0;  //���ص�λ�� 
	const double side = w / 4;

	BITMAPFILEHEADER fileHeader;  //����һ��bmp���� 

	fileHeader.bfType = 0x4D42; // bmp�ļ���־ 
	fileHeader.bfReserved1 = 0;  //Ԥ����������������Ϊ0 
	fileHeader.bfReserved2 = 0;  //
								 //ͼ���С���ļ�ͷ+��Ϣͷ+��ɫ�壨����δ�õ���+ͼ������ 
	fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
	//�ļ���ʼ��ͼ�����ݴ���λ�������С���ļ�ͷ+��Ϣͷ+��ɫ�壨����δ�õ���  
	fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// ��ʼ�����ݣ���Ϊ0 
	BITMAPINFOHEADER bitmapHeader = { 0 };

	bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);//  ��Ϣͷ��С 
	bitmapHeader.biHeight = height;  //ͼ���� 
	bitmapHeader.biWidth = width;  //ͼ��߶� 
	bitmapHeader.biPlanes = 1;  //Ŀ���豸���𣬱���Ϊ1 
	bitmapHeader.biBitCount = 24; // 
	bitmapHeader.biSizeImage = size;//ͼ�����ݴ�С 
	bitmapHeader.biCompression = 0; //ѹ���� 
	bitmapHeader.biXPelsPerMeter = 1;
	bitmapHeader.biYPelsPerMeter = 1;

	BYTE *bits = (BYTE *)malloc(size);  //�����ڴ棬����ͼ������ 

	memset(bits, 0xFF, size);  //��bitsָ���size���ֽ��ڵ����ݸ�Ϊ0xFF 
							   //����ͼ�����ݳ�ʼ��Ϊ��ɫ 
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

	FILE *output = fopen(name, "wb");  // ��д��ʽ���ļ���û�оʹ��� 

	if (output == NULL)
	{
		printf("Cannot open file!\n");
	}
	else
	{
		fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output); //д���ļ�ͷ 
		fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);//д����Ϣͷ 
		fwrite(bits, size, 1, output);//д��ͼ������  
		fclose(output); //�ر��ļ� 
		printf("%s��ά���������\n",name);
	}
}
int main()
{
	string text0, name0,name1;
	string bmp = ".bmp";
	
	printf("�����ά������");
	cin  >> name0;
	printf("�����ַ���");
	cin >> text0;

	name1 = name0 + bmp;
	const char *text = text0.c_str();
	const char *name = name1.c_str();

	const QrCode qr = QrCode::encodeText(text, QrCode::Ecc::HIGH);
	saveBitmap(name, qr);
	return 0;
}
