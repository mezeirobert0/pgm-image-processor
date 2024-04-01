#include "Size.h"

Size::Size()
{
	w = 0;
	h = 0;
}

Size::Size(unsigned width, unsigned height)
{
	w = width;
	h = height;
}

unsigned Size::getW()
{
	return w;
}

unsigned Size::getH()
{
	return h;
}

void Size::setW(unsigned width)
{
	w = width;
}

void Size::setH(unsigned height)
{
	h = height;
}

bool operator==(const Size& size1, const Size& size2)
{
	return size1.w * size1.h == size2.w * size2.h;
}

bool operator<(const Size& size1, const Size& size2)
{
	return size1.w * size1.h < size2.w * size2.h;
}

bool operator>(const Size& size1, const Size& size2)
{
	return size1.w * size1.h > size2.w * size2.h;
}

bool operator<=(const Size& size1, const Size& size2)
{
	return size1.w * size1.h <= size2.w * size2.h;
}

bool operator>=(const Size& size1, const Size& size2)
{
	return size1.w * size1.h >= size2.w * size2.h;
}
