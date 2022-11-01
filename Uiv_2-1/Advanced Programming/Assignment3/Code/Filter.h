#pragma once

#include <string>

class BitmapImage;

class Filter
{
public:
	virtual std::string getName() = 0;
	virtual BitmapImage process(const BitmapImage& im) = 0;
};

class NegativeFilter : public Filter
{
	virtual std::string getName();
	virtual BitmapImage process(const BitmapImage& im);
};

class GaussianFilter : public Filter
{
	virtual std::string getName();
	virtual BitmapImage process(const BitmapImage& im);
};

class ZoomInFilter : public Filter
{
	virtual std::string getName();
	virtual BitmapImage process(const BitmapImage& im);
};

class ZoomOutFilter : public Filter
{
	virtual std::string getName();
	virtual BitmapImage process(const BitmapImage& im);
};

class Free1Filter : public Filter
{
	virtual std::string getName();
	virtual BitmapImage process(const BitmapImage& im);
};

class Free2Filter : public Filter
{
	virtual std::string getName();
	virtual BitmapImage process(const BitmapImage& im);
};
