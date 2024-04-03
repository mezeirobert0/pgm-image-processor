#pragma once
#include "ImageProcessing.h"
class BrightnessContrast : public ImageProcessing
{
public:
	double gain, bias;

	void process(const Image& src, Image& dst) override;

	BrightnessContrast();

	BrightnessContrast(double gain, double bias);
};

