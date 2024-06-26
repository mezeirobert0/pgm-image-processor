#include "Convolution.h"
#include <stdexcept>

int scale(int value)
{
	if (value < 0)
		return 0;

	if (value > 255)
		return 255;

	return value;
}

void Convolution::process(const Image& src, Image& dst)
{
	if (kernel.size() % 2 == 0)
	{
		throw std::invalid_argument("Kernel size cannot be an even number!");
		return;
	}

	dst = src;

	int kernelSum = 0;
	int kernelSize = kernel.size();
	for (unsigned short i = 0; i < kernelSize; i++)
		for (unsigned short j = 0; j < kernelSize; j++)
			kernelSum += kernel[i][j];

	for (unsigned short i = 0; i < dst.height(); i++)
		for (unsigned short j = 0; j < dst.width(); j++)
		{
			short charValue = 0;

			for (unsigned short u = 0; u < kernelSize; u++)
				for (unsigned short v = 0; v < kernelSize; v++)
				{
					int xIndex = static_cast<int>(i - u + kernelSize / 2);
					int yIndex = static_cast<int>(j - v + kernelSize / 2);

					// Check for boundary conditions
					if (xIndex >= 0 && xIndex < dst.height() && yIndex >= 0 && yIndex < dst.width())
						charValue += kernel[u][v] * static_cast<unsigned short>(dst.at(xIndex, yIndex));
				}

			charValue = scale(charValue / kernelSum);

			dst.at(i, j) = static_cast<unsigned char>(charValue);
		}
}
