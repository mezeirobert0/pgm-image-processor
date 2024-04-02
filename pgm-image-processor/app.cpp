#include <iostream>
#include "Image.h"

int main()
{
    Image img;
    img.load("../images/small_image.ascii.pgm");
    Image newImg;
    img.getROI(newImg, 1, 1, 2, 2);
    img.save("../images/small_image.ascii.pgm");
    newImg.save("../images/small_image_roi.ascii.pgm");

    return 0;
}
