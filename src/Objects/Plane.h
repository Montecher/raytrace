#ifndef RAYTRACE_PLANE_H
#define RAYTRACE_PLANE_H

#include "Object.h"

class Plane: public Object {
private:
    Vec3 normal;
    double offset;

public:
    Plane(const Vec3&, double);
    Plane(double, double, double, double);

    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_PLANE_H
