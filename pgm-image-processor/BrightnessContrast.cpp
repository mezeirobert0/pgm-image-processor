#include "BrightnessContrast.h"

BrightnessContrast::BrightnessContrast()
{
	gain = 1;
	bias = 0;
}

BrightnessContrast::BrightnessContrast(double gain, double bias)
{
	this->gain = gain;
	this->bias = bias;
}

void BrightnessContrast::process(const Image& src, Image& dst)
{
	dst = src * gain + Image::ones(src.width(), src.height()) * bias;
}
