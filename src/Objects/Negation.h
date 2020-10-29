#ifndef __OBJECTS_NEGATION_H
#define __OBJECTS_NEGATION_H
#include "Objects/Unop.h"

/**
 * \class Negation
 * \brief This object codes the negation of an object.
 *
 * This Object is the concept of inverting the filled and non filled part of the Object given to the constructor, ie the interior becomes the exterior and vice-versa.
 */
class Negation: public Unop {
public:
    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};

#endif
