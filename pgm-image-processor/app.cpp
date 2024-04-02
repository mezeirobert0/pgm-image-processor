#include <iostream>
#include "Image.h"

int main()
{
    Image img;
    img.load("../images/small_image.ascii.pgm");
    img.save("../images/small_image.ascii.pgm");

    return 0;
}
