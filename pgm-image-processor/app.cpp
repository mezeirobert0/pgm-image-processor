#include <iostream>
#include "Rectangle.h"

int main()
{
    Rectangle R1 = Rectangle(0, 0, 6, 6);
    Rectangle R2 = Rectangle(3, 2, 5, 6);
    Rectangle R3 = R2 & R1;

    std::cout << R3.getX() << " " << R3.getY() << " " << R3.getWidth() << " " << R3.getHeight() << '\n';
}
