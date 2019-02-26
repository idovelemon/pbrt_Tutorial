#ifndef PBRT_TUTORIAL_IMAGEIO_H_
#define PBRT_TUTORIAL_IMAGEIO_H_

#include <xstring>
#include "geometry.h"

namespace pbrt_tutorial {

void WriteImage(const std::string& fileName, float* rgb, const Point2i& resolution);

};

#endif  // PBRT_TUTORIAL_IMAGEIO_H_
