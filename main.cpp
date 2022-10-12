#include <iostream>
#include <functional>
#include <vector>
#include <thread>
#include "Image.h"
#include "ImageDataProviderFactory.h"

void blendRegion(Image& output, const Image& imgA, const Image& imgB,
    std::function <Image::Color(Image::Color, Image::Color)>& func
    , int minX, int minY, int maxX, int maxY) {

    for (auto y = minY; y < maxY; y++) {
        for (auto x = minX; x < maxX; x++) {
            auto colorA = imgA(x, y);
            auto colorB = imgB(x, y);
            output(x, y) = func(colorA, colorB);
        }
    }
}

Image blendImages(const Image& imgA, const Image& imgB, int numThreads,
    std::function<Image::Color(Image::Color, Image::Color)>& func) {

    auto outWidth = imgA.getWidth();
    auto outHeight = imgA.getHeigth();

    //TODO:  znalezienie obszaru wynikowego

    Image outImg(outWidth, outHeight);

    std::vector<std::thread> jobs(numThreads);
}

int main()
{
    ImageDataProviderFactory fabryka;
    Image wczytany = fabryka.load_image("C:\Users\XVND83\source\repos\SI\W17_SI\Image_blending\moon.ppm");
    wczytany.print();
    Image obrazek(20, 20);
    obrazek(0, 0).r = 1;
    obrazek(2, 3).g = 0.5;
    obrazek(2, 3).b = 1;

    fabryka.save_image("C:\Users\XVND83\source\repos\SI\W17_SI\Image_blending\moon.ppm", obrazek);

}