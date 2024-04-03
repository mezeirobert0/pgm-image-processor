#include <iostream>
#include "Image.h"

int main()
{
    Image img;
    img.load("../images/small_image.ascii.pgm");
    img.save("../images/small_image.ascii.pgm");

    Image newImg;
    img.getROI(newImg, 1, 1, 2, 2);

    Image newImg2;
    img.getROI(newImg2, 0, 0, 2, 2);
    
    std::cout << newImg2 << "\n\n" << newImg << "\n\n" << newImg2 - newImg << "\n\n";

    std::cout << (int)(img.at(2, 1)) << "\n\n";

    std::cout << Image::zeros(4, 4);

    return 0;
}
