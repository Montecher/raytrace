#ifndef __OBJECTS_WAVES_H
#define __OBJECTS_WAVES_H
#include "Object.h"

class Waves: public Object {
public:
    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};

#endif
