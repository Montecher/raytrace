#ifndef __OBJECTS_SCALING_H
#define __OBJECTS_SCALING_H
#include "Objects/Unop.h"

/**
 * \class Scaling
 *
 * \brief Object representing the scaling of an Object.
 *
 * This Object scales it's inputted object by the asked factor.
 */
class Scaling: public Unop {
protected:
    double factor;  ///< scale factor.

public:
    /**
     * \brief Scaling constructor.
     *
     * @param obj Object to be scaled.
     * @param factor scaling factor.
     */
    Scaling(const Object* obj, const double factor);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};

#endif
