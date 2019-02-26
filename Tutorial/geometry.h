#ifndef PBRT_TUTORIAL_GEOMETRY_H_
#define PBRT_TUTORIAL_GEOMETRY_H_

namespace pbrt_tutorial {

template<typename T> class Point2 {
public:
    T x, y;

    Point2() { x = y = 0; }
    Point2(T x, T y) : x(x), y(y) {
    }
};

template<typename T> class Point3 {
public:
    T x, y, z;

    Point3() { x = y = z = 0; }
    Point3(T x, T y, T z) : x(x), y(y), z(z) {
    }
};

typedef Point2<float> Point2f;
typedef Point2<int> Point2i;
typedef Point3<float> Point3f;
typedef Point3<int> Point3i;

};  // namespace pbrt_tutorial

#endif  // PBRT_TUTORIAL_GEOMETRY_H_
