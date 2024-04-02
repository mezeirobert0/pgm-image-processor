#pragma once
#include "Point.h"
class Rectangle
{
private:
	int x, y; //coordinates of top-left corner
	int width, height;

public:
	Rectangle();
	Rectangle(int x, int y, int width, int height);

	int getX();
	int getY();
	int getWidth();
	int getHeight();

	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);

	friend Rectangle operator+(const Rectangle&, const Point&);
	friend Rectangle operator-(const Rectangle&, const Point&);

	friend Rectangle operator&(const Rectangle& rect1, const Rectangle& rect2);
	//friend Rectangle operator|(const Rectangle& rect1, const Rectangle& rect2);
};
