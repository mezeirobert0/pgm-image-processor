#pragma once
#include "ImageProcessing.h"
#include <vector>

typedef int (*scalingFunction)(int);

int scale(int value);

class Convolution : public ImageProcessing
{
private:
	std::vector<std::vector<short>> kernel;
	scalingFunction scale;

public:
	void process(const Image& src, Image& dst) override;

	Convolution(std::vector<std::vector<short>>& kernel, scalingFunction scale) : kernel(kernel), scale(scale) {}
};

