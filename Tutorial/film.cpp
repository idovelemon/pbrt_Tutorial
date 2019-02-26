#include "film.h"
#include "imageio.h"

namespace pbrt_tutorial {

Film::Film(const Point2i& resolution, const std::string& fileName)
    : fullResolution(resolution)
    , fileName(fileName) {
    pixels = std::unique_ptr<Pixel[]>(new Pixel[fullResolution.x * fullResolution.y]);
}

Film::~Film() {
}

void Film::SetImage(const Point3f* img) const {
    int numberOfPixels = fullResolution.x * fullResolution.y;
    for (int i = 0; i < numberOfPixels; i++)
    {
        Pixel& p = pixels[i];
        p.xyz[0] = img[i].x;
        p.xyz[1] = img[i].y;
        p.xyz[2] = img[i].z;
    }
}

void Film::WriteImage() {
    int numberOfPixels = fullResolution.x * fullResolution.y;
    std::unique_ptr<float[]> rgb(new float[numberOfPixels * 3]);
    for (int i = 0; i < numberOfPixels; i++)
    {
        Pixel& p = pixels[i];
        rgb[i * 3 + 0] = p.xyz[0];
        rgb[i * 3 + 1] = p.xyz[1];
        rgb[i * 3 + 2] = p.xyz[2];
    }
    pbrt_tutorial::WriteImage(fileName, rgb.get(), fullResolution);
}

};