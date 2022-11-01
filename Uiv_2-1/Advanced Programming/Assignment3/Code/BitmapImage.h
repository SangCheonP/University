#pragma once

#include <string>

class BitmapImage
{
public:
	BitmapImage(int w, int h);
	BitmapImage(const std::string& path);
	
	~BitmapImage();

	BitmapImage(const BitmapImage& im);
	BitmapImage(BitmapImage&& im);

	BitmapImage& operator=(const BitmapImage& im);
	BitmapImage& operator=(BitmapImage&& im);

	void setPixel(int x, int y, double v);
	double getPixel(int x, int y) const;

	void clear();

	bool loadPGM(const std::string& path);
	bool savePGM(const std::string& path) const;

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }

private:
	int width;
	int height;
	double* bitmap;
};
