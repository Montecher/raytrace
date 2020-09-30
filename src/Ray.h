#ifndef RAYTRACE_RAY_H
#define RAYTRACE_RAY_H

#include <iostream>
#include "Vec3.h"
#include "Object.h"

class Ray {
protected:
    Vec3 orig;
    Vec3 dir;

public:
    Ray(Vec3 orig, Vec3 dir);
    // the destructor is implicit

    Vec3 point(double) const;
    bool intersect(Object*, double*, Vec3*, Vec3*) const;

    friend std::ostream& operator << (std::ostream&, const Ray&);
};

inline Vec3 Ray::point(double t) const {
    return orig + dir * t;
}

inline std::ostream& operator<<(std::ostream& output, const Ray& ray){
    output << "(x, y, z) = " << ray.orig << " + t * " << ray.dir;
    return output;
}

#endif
