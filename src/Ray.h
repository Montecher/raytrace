#ifndef RAYTRACE_RAY_H
#define RAYTRACE_RAY_H

#include <iostream>
#include "Vec3.h"

class Ray {
protected:
    Vec3 orig;
    Vec3 dir;

public:
    Ray(Vec3 orig, Vec3 dir);
    // the destructor is implicit

    friend std::ostream& operator << (std::ostream&, const Ray&);

    // TODO add manipulations on rays
};

#endif
