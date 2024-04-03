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
	// dst = src * gain + (Image::ones(src.width(), src.height()) * (double)(1/255)) * bias;

	dst = src;

	for (unsigned i = 0; i < dst.height(); i++)
		for (unsigned j = 0; j < dst.width(); j++)
		{
			unsigned short charValue = static_cast<unsigned short>(dst.at(i, j));

			if (charValue * gain + bias > 255)
				charValue = 255;

			else if (charValue * gain + bias < 0)
				charValue = 0;

			else charValue = charValue * gain + bias;

			dst.at(i, j) = static_cast<unsigned char>(charValue);
		}
}
