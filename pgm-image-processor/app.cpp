#include <iostream>
#include "Image.h"
#include "BrightnessContrast.h"

int main()
{
    Image img;
    img.load("../images/small_image.ascii.pgm");
    img.save("../images/small_image.ascii.pgm");

    BrightnessContrast bc;
    bc.process(img, img);
    img.save("../images/small_image.ascii.pgm");

    return 0;
}
