#ifndef PBRT_TUTORIAL_FILM_H_
#define PBRT_TUTORIAL_FILM_H_

#include <memory>
#include <xstring>
#include "geometry.h"

namespace pbrt_tutorial {

class Film {
public:
    Film(const Point2i& resolution, const std::string& fileName);
    virtual ~Film();

    void SetImage(const Point3f* img) const;
    void WriteImage();

public:
    const Point2i fullResolution;
    const std::string fileName;

private:
    struct Pixel {
        float xyz[3] = {0.0f, 0.0f, 0.0f};
        float padding;
    };
    std::unique_ptr<Pixel[]> pixels;
};

};  // end namespace pbrt_tutorial

#endif  // PBRT_TUTORIAL_FILM_H_
