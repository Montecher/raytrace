#ifndef RAYTRACE_BOX_H
#define RAYTRACE_BOX_H

#include "Object.h"

class Box: public Object {
private:
    Vec3 a, b;

public:
    Box();
    Box(Vec3);
    Box(double, double, double);
    Box(Vec3, Vec3);
    Box(double, double, double, double, double, double);

    virtual double distance_to(const Vec3&) const;
//    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_BOX_H
