#include <iostream>
#include "imageSrc/MyImage.h"
int main()
{
	CByteImage image1(640, 480);
	image1.SetConstValue(0);

	CByteImage image2(image1);
	CByteImage image3;
	image3 = image1;

	int nWidth = image1.GetWidth();
	int nHeight = image1.GetHeight();
	int nChannel = image1.GetChannel();

	double incX = 255.0 / nWidth;
	double incY = 255.0 / nHeight;
	int r, c;
	for (r = 0; r < nHeight; r++)
	{
		for (c = 0; c < nWidth; c++)
		{
			image2.GetAt(c, r) = (BYTE)(c * incX);
			image3.GetAt(c, r) = (BYTE)(r * incY);
		}
	}

	image1.SaveImage("Black.bmp");
	image2.SaveImage("GradationX.bmp");
	image3.SaveImage("GradationY.bmp");

	return 0;
}