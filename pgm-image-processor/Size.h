#pragma once
class Size
{
private:
	unsigned w, h; //width and height

public:
	Size();
	Size(unsigned width, unsigned height);
	
	unsigned getW();
	unsigned getH();
	
	void setW(unsigned width);
	void setH(unsigned height);

	friend bool operator==(const Size& size1, const Size& size2);
	friend bool operator<(const Size& size1, const Size& size2);
	friend bool operator>(const Size& size1, const Size& size2);
	friend bool operator<=(const Size& size1, const Size& size2);
	friend bool operator>=(const Size& size1, const Size& size2);
};
