#include "Image.h"
#include <istream>
#include <fstream>
#include <ostream>
#include <string>
#include <stdexcept>
#include "Rectangle.h"
#include "Size.h"

Image::Image()
{
	m_data = nullptr;
	m_width = 0;
	m_height = 0;
}

Image::Image(unsigned int w, unsigned int h)
{
	m_width = w;
	m_height = h;

	m_data = new unsigned char* [h];

	for (unsigned i = 0; i < h; i++)
	{
		m_data[i] = new unsigned char[w];

		for (unsigned j = 0; j < w; j++)
			m_data[i][j] = static_cast<unsigned char>(0);
	}
}

Image::Image(const Image& other)
{
	m_width = other.m_width;
	m_height = other.m_height;

	m_data = new unsigned char* [m_height];

	for (unsigned i = 0; i < m_height; i++)
	{
		m_data[i] = new unsigned char[m_width];

		for (unsigned j = 0; j < m_width; j++)
			m_data[i][j] = static_cast<unsigned char>(0);
	}
}

Image& Image::operator=(const Image& other)
{
	return *this;
}

Image::~Image()
{
	for (unsigned i = 0; i < m_height; i++)
		delete[] m_data[i];
	
	delete[] m_data;
}

bool Image::load(std::string imagePath)
{
	std::ifstream fin(imagePath);

	if (!fin.is_open())
		return false;

	if (!(fin >> *this))
		return false;

	fin.close();

	return true;
}

bool Image::save(std::string imagePath) const
{
	std::ofstream fout(imagePath);

	if (!fout.is_open())
		return false;

	fout << *this;

	fout.close();

	return true;
}

Image Image::operator+(const Image& i)
{
	if (!(size() == i.size()))
		throw std::runtime_error("The images are different sizes");

	Image sumImage(m_width, m_height);

	for (unsigned j = 0; j < m_height; j++)
		for (unsigned k = 0; k < m_width; k++)
		{
			unsigned short charValue = static_cast<unsigned short>(m_data[j][k]) + static_cast<unsigned short>(i.m_data[j][k]);
			
			if (charValue > 255)
				charValue = 255;

			sumImage.m_data[j][k] = static_cast<unsigned char>(charValue);
		}

	return sumImage;
}

Image Image::operator-(const Image& i)
{
	if (!(size() == i.size()))
		throw std::runtime_error("The images are different sizes");

	Image diffImage(m_width, m_height);

	for (unsigned j = 0; j < m_height; j++)
		for (unsigned k = 0; k < m_width; k++)
		{
			short charValue = static_cast<unsigned short>(m_data[j][k]) - static_cast<unsigned short>(i.m_data[j][k]);

			if (charValue < 0)
				charValue = 0;

			diffImage.m_data[j][k] = static_cast<unsigned char>(charValue);
		}

	return diffImage;
}

/*
Image Image::operator*(double s)
{

}

bool Image::getROI(Image& roiImg, Rectangle roiRect)
{

}

bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{

}
*/

bool Image::isEmpty() const
{
	if (m_data == nullptr && m_width == 0 && m_height == 0)
		return true;

	return false;
}

Size Image::size() const
{
	return Size(m_width, m_height);
}

unsigned int Image::width() const
{
	return m_width;
}

unsigned int Image::height() const
{
	return m_height;
}

unsigned char& Image::at(unsigned int x, unsigned int y)
{
	return m_data[x][y];
}

unsigned char& Image::at(Point pt)
{
	return m_data[pt.getX()][pt.getY()];
}

/*
unsigned char* Image::row(int y)
{

}
*/

void Image::release()
{

}

std::istream& operator>>(std::istream& is, Image& dt)
{
	std::string magicNumber;
	std::getline(is, magicNumber);

	if (magicNumber != "P2")
		return is;

	std::string comment;
	std::getline(is, comment);

	unsigned w, h;
	is >> w >> h;

	if (dt.m_width != w || dt.m_height != h)
	{
		//delete the previous array
		dt.~Image();
		dt = Image(w, h);
	}

	char maxValue;
	is >> maxValue;

	unsigned short charValue;
	for (unsigned i = 0; i < h; i++)
		for (unsigned j = 0; j < w; j++)
		{
			is >> charValue;

			dt.m_data[i][j] = static_cast<unsigned char>(charValue);
		}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Image& dt)
{
	os << "P2\n" << "# PGM image\n" << dt.m_width << ' ' << dt.m_height << '\n' << 255 << '\n';

	unsigned short valuesPrinted = 0;
	for (unsigned i = 0; i < dt.m_height; i++)
	{
		//limiting number of char values to 15
		for (unsigned j = 0; j < dt.m_width; j++)
		{
			unsigned short charValue = static_cast<unsigned short>(dt.m_data[i][j]);

			os << charValue;
			valuesPrinted++;

			if (valuesPrinted < 15)
				os << ' ';
			else
			{
				os << '\n';
				valuesPrinted = 0;
			}
		}
	}

	return os;
}

Image Image::zeros(unsigned int width, unsigned int height)
{
	Image zeroImage(width, height);
	
	return zeroImage;
}

Image Image::ones(unsigned int width, unsigned int height)
{
	Image oneImage;
	
	oneImage.m_width = width;
	oneImage.m_height = height;

	oneImage.m_data = new unsigned char* [height];

	for (unsigned i = 0; i < height; i++)
	{
		oneImage.m_data[i] = new unsigned char[width];

		for (unsigned j = 0; j < width; j++)
			oneImage.m_data[i][j] = 255;
	}

	return oneImage;
}
