#include "GammaCorrection.h"
#include <cmath>

GammaCorrection::GammaCorrection()
{
	gamma = 1;
}

GammaCorrection::GammaCorrection(double gamma)
{
	this->gamma = gamma;
}

void GammaCorrection::process(const Image& src, Image& dst)
{
	dst = src;

	for (unsigned i = 0; i < dst.height(); i++)
		for (unsigned j = 0; j < dst.width(); j++)
		{
			unsigned short charValue = static_cast<unsigned short>(dst.at(i, j));

			double doubleCharValue = charValue;
			doubleCharValue = std::pow(doubleCharValue, gamma);
			
			if (doubleCharValue > 255)
				doubleCharValue = 255;

			charValue = doubleCharValue;

			dst.at(i, j) = static_cast<unsigned char>(charValue);
		}
}