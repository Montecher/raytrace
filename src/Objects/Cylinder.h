#ifndef RAYTRACE_CYLINDER_H
#define RAYTRACE_CYLINDER_H

#include "Object.h"

class Cylinder: public Object {
private:
    Vec3 center;
    double radius;
    double len;

public:
    Cylinder();
    Cylinder(Vec3 vec3, double radius, double len);
    Cylinder(double x, double y, double z, double radius, double len);
    ~Cylinder();

    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_SPHERE_H
