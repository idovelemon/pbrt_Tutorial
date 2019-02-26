#include <iostream>
#include "film.h"

int main() {
    static constexpr int kImageWidth = 256;
    static constexpr int kImageHeight = 256;
    pbrt_tutorial::Film film(pbrt_tutorial::Point2i(kImageWidth, kImageHeight), std::string("test.bmp"));

    std::unique_ptr<pbrt_tutorial::Point3f[]> image(new pbrt_tutorial::Point3f[kImageWidth * kImageHeight]);

    for (int i = 0; i < kImageHeight; i++) {
        for (int j = 0; j < kImageWidth; j++) {
            image[i * kImageWidth + j].x = 1.0f * i / kImageHeight;
            image[i * kImageWidth + j].y = 1.0f * i / kImageHeight;
            image[i * kImageWidth + j].z = 1.0f * i / kImageHeight;
        }
    }

    //for (int i = 0; i < kImageHeight; i++) {
    //    for (int j = 0; j < kImageWidth; j++) {
    //        image[i * kImageWidth + j].x = 1.0f * j / kImageHeight;
    //        image[i * kImageWidth + j].y = 1.0f * j / kImageHeight;
    //        image[i * kImageWidth + j].z = 1.0f * j / kImageHeight;
    //    }
    //}

    film.SetImage(image.get());
    film.WriteImage();

    system("pause");
    return 0;
}