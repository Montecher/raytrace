#ifndef RAYTRACE_TORUS_H
#define RAYTRACE_TORUS_H

#include "Object.h"

/**
 * \class Torus
 * \brief Representation of a 3D Torus.
 *
 * This object will manage all torus shaped objects.
 */
class Torus: public Object {
private:
    Vec3 center;  ///< center point of the Torus.
    double radius;  ///< radius of the Torus.
    double thickness;  ///< thickness of the Torus ring.

public:
    /**
     * \brief Torus default constructor
     *
     * This will create a Torus centered on (0, 0, 0), with a radius of 1 and a thickness of 0.1.
     */
    Torus();

    /**
     * \brief Torus constructor with a Vec3 center, radius and thickness specified.
     *
     * This constructor will create a Torus centered on the Vec3, with the radius and thickness specified.
     *
     * @param center center point of the Torus.
     * @param radius radius of the Torus.
     * @param thickness thickness of the Torus.
     */
    Torus(const Vec3& center, double radius, double thickness);

    /**
     * \brief Torus constructor with a set of coordinates, radius and thickness specified.
     *
     * This constructor will create a Torus centered on the (x, y, z), with the radius and thickness specified.
     *
     * @param x x coordinate of the center of the Torus.
     * @param y y coordinate of the center of the Torus.
     * @param z z coordinate of the center of the Torus.
     * @param radius radius of the Torus.
     * @param thickness thickness of the Torus.
     */
    Torus(double x, double y, double z, double radius, double thickness);

    virtual double distance_to(const Vec3&) const;
};


#endif
