#include "Rectangle.h"

Rectangle::Rectangle()
{
	x = 0;
	y = 0;

	width = 0;
	height = 0;
}

Rectangle::Rectangle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;

	this->width = width;
	this->height = height;
}

int Rectangle::getX()
{
	return x;
}

int Rectangle::getY()
{
	return y;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getHeight()
{
	return height;
}

void Rectangle::setX(int x)
{
	this->x = x;
}

void Rectangle::setY(int y)
{
	this->y = y;
}

void Rectangle::setWidth(int width)
{
	this->width = width;
}

void Rectangle::setHeight(int height)
{
	this->height = height;
}

Rectangle operator+(const Rectangle& rect, const Point& point)
{
	return Rectangle(rect.x + point.getX(), rect.y + point.getY(), rect.width, rect.height);
}

Rectangle operator-(const Rectangle& rect, const Point& point)
{
	return Rectangle(rect.x - point.getX(), rect.y - point.getY(), rect.width, rect.height);
}

Rectangle operator&(const Rectangle& rect1, const Rectangle& rect2)
{
	int newX, newY, newWidth, newHeight;

	//top-left corner of rect2 is in rect1
	if (rect1.x <= rect2.x && rect2.x <= rect1.x + rect1.width - 1)
		if (rect1.y <= rect2.y && rect2.y <= rect1.y + rect1.height - 1)
		{
			newX = rect2.x;
			newY = rect2.y;

			if (rect2.x + rect2.width <= rect1.x + rect1.width)
				newWidth = rect2.width;

			else newWidth = rect1.x + rect1.width - rect2.x;

			if (rect2.y + rect2.height <= rect1.y + rect1.height)
				newHeight = rect2.height;

			else newHeight = rect1.y + rect1.height - rect2.y;
		}

	//top-left corner of rect1 is in rect2
	if (rect2.x <= rect1.x && rect1.x <= rect2.x + rect2.width - 1)
		if (rect2.y <= rect1.y && rect1.y <= rect2.y + rect2.height - 1)
		{
			newX = rect1.x;
			newY = rect1.y;

			if (rect1.x + rect1.width <= rect2.x + rect2.width)
				newWidth = rect1.width;

			else newWidth = rect2.x + rect2.width - rect1.x;

			if (rect1.y + rect1.height <= rect2.y + rect2.height)
				newHeight = rect1.height;

			else newHeight = rect2.y + rect2.height - rect1.y;
		}

	//bottom-left corner of rect2 is in rect1
	int bottomLeftX = rect2.x;
	int bottomLeftY = rect2.y + rect2.height - 1;
	if (rect1.x <= bottomLeftX && bottomLeftX <= rect1.x + rect1.width - 1)
		if (rect1.y <= bottomLeftY && bottomLeftY <= rect1.y + rect1.height - 1)
		{
			newX = rect2.x;
			newY = rect1.y;

			if (rect2.x + rect2.width <= rect1.x + rect1.width)
				newWidth = rect2.width;

			else newWidth = rect1.x + rect1.width - rect2.x;

			if (rect1.y + rect1.height <= rect2.y + rect2.height)
				newHeight = rect1.height;

			else newHeight = rect2.y + rect2.height - rect1.y;
		}

	return Rectangle(newX, newY, newWidth, newHeight);
}