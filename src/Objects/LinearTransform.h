#ifndef __OBJECTS_LINEARTRANSFORM_H
#define __OBJECTS_LINEARTRANSFORM_H
#include "Objects/Unop.h"
#include "Mat3.h"

class LinearTransform : public Unop {
protected:
    Mat3 m, i;

public:
    LinearTransform(Object*, const Mat3&);

    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;

    static Mat3 scale(double, double, double);
    static Mat3 swapXY, swapXZ, swapYZ;
    static Mat3 rotateX(double);
    static Mat3 rotateY(double);
    static Mat3 rotateZ(double);
    static Mat3 rotate(double, double, double);
};

#endif
