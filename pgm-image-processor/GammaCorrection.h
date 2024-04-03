#pragma once
#include "ImageProcessing.h"

class GammaCorrection : public ImageProcessing
{
public:
	double gamma;

	void process(const Image& src, Image& dst) override;

	GammaCorrection();

	GammaCorrection(double gamma);
};

