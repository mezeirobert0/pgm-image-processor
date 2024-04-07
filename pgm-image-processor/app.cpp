#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "Image.h"
#include "BrightnessContrast.h"
#include "GammaCorrection.h"
#include "Convolution.h"
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    Image img;
    img.load("../images/small_image.ascii.pgm");

    img.save("../images/small_image.ascii.pgm");

    Image img1 = Image::zeros(4, 4);
    Image img2;
    std::cout << img1 << '\n';

    BrightnessContrast bc(4, 4);
    bc.process(img1, img2);
    std::cout << img2 << '\n';

    bc.process(img2, img1);
    std::cout << img1 << '\n';

    BrightnessContrast bc1(10, 10);
    bc1.process(img1, img2);
    std::cout << img2 << '\n';

    bc1.process(img2, img1);
    std::cout << img1 << '\n';

    BrightnessContrast(1, -5).process(img1, img2);
    std::cout << img2 << '\n';

    Image baboonImg1, baboonImg2;
    baboonImg1.load("../images/baboon.ascii.pgm");

    GammaCorrection gc(0.8);
    gc.process(baboonImg1, baboonImg2);
    baboonImg2.save("../images/baboon_2.ascii.pgm");

    DrawingModule::drawRectangle(baboonImg2, Point(10, 10), Point(100, 150), (unsigned char)255);
    baboonImg2.save("../images/baboon_2.ascii.pgm");

    DrawingModule::drawLine(baboonImg2, Point(-100, -100), Point(100, 150), (unsigned char)255);
    baboonImg2.save("../images/baboon_2.ascii.pgm");

    DrawingModule::drawCircle(baboonImg2, Point(500, 500), 20, (unsigned char)255);
    baboonImg2.save("../images/baboon_2.ascii.pgm");

    std::vector<std::vector<short>> ker(3, std::vector<short>(3));
    for (short i = 0; i < 3; i++)
        for (short j = 0; j < 3; j++)
            ker[i][j] = 1;

    Convolution c1(ker, scale);
    c1.process(baboonImg1, baboonImg2);
    baboonImg2.save("../images/baboon_3.ascii.pgm");

    // _CrtDumpMemoryLeaks();
    // code in main must be put in { } in order for the destructor to kick in before the _CrtDumpMemoryLeaks() gets called

    return 0;
}
