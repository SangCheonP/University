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
};

class GaussianFilter : public Filter
{
};

class ZoomInFilter : public Filter
{
};

class ZoomOutFilter : public Filter
{
};

class Free1Filter : public Filter
{
};

class Free2Filter : public Filter
{
};
