#include "tgaimage.h"
#include <iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
	for (float t = 0.; t < 1.; t += .01)
	{
		int x = x0 + (x1 - x0) * t;
		int y = y0 + (y1 - y0) * t;
		image.set(x, y, color);
	}
}

int main(int argc, char **argv)
{
	TGAImage image(100, 100, TGAImage::RGB);
	line(40, 40, 40, 80, image, white);
	image.flip_vertically();
	image.write_tga_file("output.tga");
	return 0;
}
