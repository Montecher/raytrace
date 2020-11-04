#ifndef __OBJECTS_EXCLUSION_H
#define __OBJECTS_EXCLUSION_H
#include "Objects/Binop.h"

/**
 * \class Exclusion
 *
 * \brief This object code the exclusion of an object on another.
 *
 * This Object is the concept of taking a first Object and remove any part it has in common with a second Object.
 */
class Exclusion: public Binop {
public:
    /**
     * \brief Exclusion constructor.
     * @param obj1 main Object.
     * @param obj2 Object to be removed.
     */
    Exclusion(const Object* obj1, const Object* obj2);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};

#endif
