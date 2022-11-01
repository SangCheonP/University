#include "Filter.h"
#include "BitmapImage.h"

std::string NegativeFilter::getName()
{
	return "Negative";
}

BitmapImage NegativeFilter::process(const BitmapImage& im)
{
	BitmapImage p = BitmapImage::BitmapImage(im);
	for (int i = 0; i < p.getHeight(); ++i)
	{
		for (int j = 0; j < p.getWidth(); ++j)
		{
			p.setPixel(i, j, 1.0 - p.getPixel(i, j));
		}
	}
	return p;
}


std::string GaussianFilter::getName()
{
	return "Gaussian";
}

BitmapImage GaussianFilter::process(const BitmapImage& im)
{
	double sum = 0;
	BitmapImage p = BitmapImage::BitmapImage(im);
	double kernel[5][5] = { {0.003,0.013,0.022,0.013,0.003},
	{0.013,0.059,0.097,0.059,0.013}, 
	{0.022,0.097,0.159,0.097,0.022},  
	{0.013,0.059,0.097,0.059,0.013},
	{0.003,0.013,0.022,0.013,0.003} };

	for (int y = 0; y < p.getHeight(); ++y)
	{
		for (int x = 0; x < p.getWidth(); ++x)
		{
			sum = 0;
			for (int i = -1 * 5 / 2; i <= 5 / 2; ++i)
			{
				for (int j = -1 * 5 / 2; j <= 5 / 2; ++j)
				{

					int y2 = y + i;
					int x2 = x + j;

					if (y2 < 0) y2 = 0;
					else if (y2 > p.getWidth() - 1) y2 = p.getWidth() - 1;

					if (x2 < 0) x2 = 0;
					else if (x2 > p.getHeight() - 1) x2 = p.getHeight() - 1;

					sum += p.getPixel(y2, x2) * kernel[5 / 2 + i][5 / 2 + j];
				}
			}
			sum = sum / (double)(5 * 5);
			p.setPixel(y, x, sum);
		}
	}
	return p;
}


std::string ZoomInFilter::getName()
{
	return "Zoom In";
}

BitmapImage ZoomInFilter::process(const BitmapImage& im)
{
	BitmapImage p = BitmapImage::BitmapImage(im);
	for (int i = 0; i < im.getHeight(); ++i)
	{
		for (int j = 0; j < im.getWidth(); ++j)
		{
			p.setPixel(i, j, im.getPixel(i * 0.8, j * 0.8));
		}
	}
	return p;
}


std::string ZoomOutFilter::getName()
{
	return "Zoom Out";
}

BitmapImage ZoomOutFilter::process(const BitmapImage& im)
{
	BitmapImage p = BitmapImage::BitmapImage(im);
	for (int i = 0; i < im.getHeight(); ++i)
	{
		for (int j = 0; j < im.getWidth(); ++j)
		{
			p.setPixel(i, j, im.getPixel(i * 1.25, j * 1.25));
		}
	}
	return p;
}


std::string Free1Filter::getName()
{
	return "Free1";
}

BitmapImage Free1Filter::process(const BitmapImage& im) //8방향 검출
{
	double sum = 0;
	BitmapImage p = BitmapImage::BitmapImage(im);
	double kernel[3][3] = { {1,1,1},{1,-8,1},{1,1,1} };

	for (int y = 0; y < p.getHeight(); ++y)
	{
		for (int x = 0; x < p.getWidth(); ++x)
		{
			sum = 0;
			for (int i = -1 * 3 / 2; i <= 3 / 2; ++i)
			{
				for (int j = -1 * 3 / 2; j <= 3 / 2; ++j)
				{

					int y2 = y + i;
					int x2 = x + j;

					if (y2 < 0) y2 = 0;
					else if (y2 > p.getWidth() - 1) y2 = p.getWidth() - 1;

					if (x2 < 0) x2 = 0;
					else if (x2 > p.getHeight() - 1) x2 = p.getHeight() - 1;

					sum += p.getPixel(y2, x2) * kernel[3 / 2 + i][3 / 2 + j];
				}
			}
			sum = sum / (double)(3 * 3);
			p.setPixel(y, x, sum);
		}
	}
	return p;
}

std::string Free2Filter::getName()
{
	return "Free2";
}

BitmapImage Free2Filter::process(const BitmapImage& im)  //4방향 검출
{
	double sum = 0;
	BitmapImage p = BitmapImage::BitmapImage(im);
	double kernel[3][3] = { {0,1,0},{1,-4,1},{0,1,0} };

	for (int y = 0; y < im.getHeight(); ++y)
	{
		for (int x = 0; x < im.getWidth(); ++x)
		{
			sum = 0;
			for (int i = -1 * 3 / 2; i <= 3 / 2; ++i)
			{
				for (int j = -1 * 3 / 2; j <= 3 / 2; ++j)
				{

					int y2 = y + i;
					int x2 = x + j;

					if (y2 < 0) y2 = 0;
					else if (y2 > im.getWidth() - 1) y2 = im.getWidth() - 1;

					if (x2 < 0) x2 = 0;
					else if (x2 > im.getHeight() - 1) x2 = im.getHeight() - 1;

					sum += im.getPixel(y2, x2) * kernel[3 / 2 + i][3 / 2 + j];
				}
			}
			sum = sum / (double)(3 * 3);
			p.setPixel(y, x, sum);
		}
	}
	return p;
}