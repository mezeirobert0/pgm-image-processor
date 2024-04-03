#include <iostream>
#include "Image.h"
#include "BrightnessContrast.h"

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
    std::cout << img2 << '\n'
        ;
    bc.process(img2, img1);
    std::cout << img1 << '\n';

    BrightnessContrast bc1(10, 10);
    bc1.process(img1, img2);
    std::cout << img2 << '\n';

    bc1.process(img2, img1);
    std::cout << img1 << '\n';

    BrightnessContrast(1, -5).process(img1, img2);
    std::cout << img2 << '\n';

    return 0;
}
