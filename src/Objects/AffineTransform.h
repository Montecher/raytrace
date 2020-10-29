#ifndef __OBJECTS_AFFINETRANSFORM_H
#define __OBJECTS_AFFINETRANSFORM_H
#include "Objects/Unop.h"
#include "Mat3.h"

class AffineTransform : public Unop {
protected:
    Mat3 m, i;
    Vec3 d;

public:
    AffineTransform(Object*, const Mat3&, const Vec3&);

    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};

#endif
