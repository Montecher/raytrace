#ifndef RAYTRACE_TORUS_H
#define RAYTRACE_TORUS_H

#include "Object.h"

class Torus: public Object {
private:
    Vec3 center;
    double radius, thickness;

public:
    Torus();
    Torus(const Vec3& vec3, double radius, double thickness);
    Torus(double x, double y, double z, double radius, double thickness);

    virtual double distance_to(const Vec3&) const;
};


#endif
