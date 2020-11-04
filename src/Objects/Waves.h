#ifndef __OBJECTS_WAVES_H
#define __OBJECTS_WAVES_H
#include "Object.h"

/**
 * \class Waves
 * \brief renders the surface of a plane in a wavy manner.
 *
 * This Object will render the surface of a plane with a sinusoidal noise.
 */
class Waves: public Object {
public:
    virtual Object* clone() const;
    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};

#endif
