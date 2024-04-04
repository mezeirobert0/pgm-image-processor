#include "DrawingModule.h"

void DrawingModule::drawCircle(Image& image, Point center, int radius, unsigned char color) 
{
	for (int y = center.getY() - radius; y <= center.getY() + radius; y++)
		for (int x = center.getX() - radius; x <= center.getX() + radius; x++)
			if (std::sqrt(std::pow(x - center.getX(), 2) + std::pow(y - center.getY(), 2)) <= radius) 
				image.at(x, y) = color;
}

void DrawingModule::drawLine(Image& img, Point p1, Point p2, unsigned char color)
{
	auto x1 = p1.getX(), y1 = p1.getY(), x2 = p2.getX(), y2 = p2.getY();
	
	short sx, sy; //the increment variables

	int dx = abs(p2.getX() - p1.getX());
	if (p1.getX() < p2.getX())
		sx = 1;
	else
		sx = -1;
    
	int dy = -abs(p2.getY() - p1.getY());
	if (p1.getY() < p2.getY())
		sy = 1;
	else
		sy = -1;

	int e = dx + dy;

	while (true)
	{
		img.at(x1, y1) = color;

		if (x1 == x2 && y1 == y2)
			break;

		int e2 = 2 * e;

		if (e2 >= dy)
		{
			if (x1 == x2)
				break;
			e += dy;
			x1 += sx;
		}
		
		if (e2 <= dy)
		{
			if (y1 == y2)
				break;
			e += dx;
			y1 += sy;
		}
	}
}

void DrawingModule::drawRectangle(Image& img, Rectangle r, unsigned char color)
{
	for (short i = r.getX(); i <= r.getX() + r.getWidth() - 1; i++)
		img.at(i, r.getY()) = img.at(i, r.getY() + r.getHeight() - 1) = color;

	for (short j = r.getY(); j <= r.getY() + r.getHeight() - 1; j++)
		img.at(r.getX(), j) = img.at(r.getX() + r.getWidth() - 1, j) = color;

}

void DrawingModule::drawRectangle(Image& img, Point tl, Point br, unsigned char color)
{
	Rectangle r = Rectangle(tl.getX(), tl.getY(), br.getX() - tl.getX() + 1, br.getY() - tl.getY() + 1);
	drawRectangle(img, r, color);
}