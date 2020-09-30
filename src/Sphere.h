#ifndef RAYTRACE_SPHERE_H
#define RAYTRACE_SPHERE_H

#include <iostream>
#include "Vec3.h"
#include "Ray.h"
#include "Object.h"

class Sphere: public Object {
private:
    Vec3 center;
    double radius;

public:
    Sphere();
    Sphere(Vec3 vec3, double radius);
    Sphere(double x, double y, double z, double radius);
    ~Sphere();

    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_SPHERE_H
