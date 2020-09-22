//
// Created by ara0n on 9/17/20.
//

#ifndef RAYTRACE_SPHERE_H
#define RAYTRACE_SPHERE_H

#include <iostream>
#include "Vec3.h"

class Sphere {
private:
    Vec3 center;
    double radius;

public:
    Sphere();
    Sphere(Vec3 vec3, double radius);
    Sphere(double x, double y, double z, double radius);

    void info();

    friend std::ostream& operator << (std::ostream&, const Sphere&);
};


#endif //RAYTRACE_SPHERE_H
