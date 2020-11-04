#ifndef RAYTRACE_PLANE_H
#define RAYTRACE_PLANE_H

#include "Object.h"


/**
 * \class Plane
 * \brief Representation of a 2D plane.
 *
 * This Object represent a 2D plane or more precisely the surface of a half-space.
 */
class Plane: public Object {
private:
    Vec3 normal;  ///< normal of the Plane surface.
    double offset;  ///< distance via the normal to (0, 0, 0).

public:
    /**
     * \brief Plane constructor with normal vector and offset
     *
     * @param normal normal of the Plane.
     * @param offset offset of the Plane.
     */
    Plane(const Vec3& normal, double offset);

    /**
     * \brief Plane constructor with set of vector coordinates and offset
     *
     * @param x x coordinate of the normal Vec3 of the Plane;
     * @param y y coordinate of the normal Vec3 of the Plane.
     * @param z z coordinate of the normal Vec3 of the Plane.
     * @param offset offset of the Plane.
     */
    Plane(double x, double y, double z, double offset);

    virtual Object* clone() const;
    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_PLANE_H
