#ifndef RAYTRACE_SPHERE_H
#define RAYTRACE_SPHERE_H

#include "Object.h"


/**
 * \class Sphere
 * \brief Representation of a 3D Sphere.
 *
 * This Object will manage all the spheres.
 */
class Sphere: public Object {
private:
    Vec3 center;  ///< center point of the Sphere.
    double radius;  ///< radius of the Sphere.

public:
    /**
     * \brief Sphere default constructor.
     *
     * This will create a Sphere centered on (0, 0, 0) and of a radius 1.
     */
    Sphere();

    /**
     * \brief Sphere constructor with a point and a radius.
     *
     * This will create the Sphere centered on the point and with a radius of of radius.
     *
     * @param vec3 center point of the Sphere.
     * @param radius radius of the Sphere.
     */
    Sphere(Vec3 vec3, double radius);

    /**
     * \brief Sphere constructor with a set of coordinates and a radius.
     *
     * This will create a Sphere with a center point at the coordinates (x, y, z) and a radius of radius.
     *
     * @param x x coordinate of the center of the Sphere.
     * @param y y coordinate of the center of the Sphere.
     * @param z z coordinate of the center of the Sphere.
     * @param radius radius of the Sphere.
     */
    Sphere(double x, double y, double z, double radius);

    /**
     * Sphere destructor.
     */
    ~Sphere();

    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_SPHERE_H
