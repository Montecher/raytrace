#ifndef RAYTRACE_OBJECT_H
#define RAYTRACE_OBJECT_H

#include <iostream>
#include "Material.h"
#include "Vec3.h"
#include "constants.h"

/**
 * \class Object
 * \brief Abstract class responsible of the priciple of the 3D objects.
 *
 * All the created 3D objects need to inherit from this abstract class to be able to work.
 */
class Object {
public:
    /**
     * Object destructor
     */
    virtual ~Object() {};

    /**
     * \brief Computes the distance to some point in space.
     *
     * This function computes a minimal distance between the Object itself and the specified point.
     *
     * \param point Point the distance is asked to.
     *
     * @return A minimal distance between the object and the point.
     */
    virtual double distance_to(const Vec3& point) const = 0;

    /**
     * \brief Computes the normal at a certain point from the surface.
     *
     * This function determines the normal from a point compared to the surface of the Object.
     *
     * @param point Point from which the normal is asked from.
     *
     * @return The normal from the point.
     */
    virtual Vec3 normal_at(const Vec3& point) const;

    /**
     * \brief Gives the Material of the Object at the intersection point.
     * This function is the way to get an access to the Material of the Object currently being rendered.
     *
     * @param point Point of the intersection with the Object.
     * @return Material of the intersected Object.
     */
    virtual const Material* get_intersecting(const Vec3& point) const;
};

#endif //RAYTRACE_OBJECT_H
