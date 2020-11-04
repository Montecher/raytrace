#ifndef RAYTRACE_CYLINDER_H
#define RAYTRACE_CYLINDER_H

#include "Object.h"

/**
 * \class Cylinder
 * \brief representation of a 3D Cylinder
 *
 * This object will manage all cylinder shaped objects.
 */
class Cylinder: public Object {
private:
    Vec3 center;  ///< center point of the base.
    double radius;  ///< radius of the base.
    double len;  ///< lenght of the Cylinder.

public:
    /**
     * \brief Cylinder default constructor.
     *
     * This will create a Cylinder with a center on (0, 0, 0) and with a radius and length of 1.
     */
    Cylinder();

    /**
     * \brief Cylinder constructor with a Vec3 center, radius and length specified.
     *
     * This constructor will create a Cylinder centered on the Vec3, with the radius and length specified.
     *
     * @param center center point of the Cylinder base.
     * @param radius radius of the Cylinder base.
     * @param len length of the Cylinder.
     */
    Cylinder(Vec3 center, double radius, double len);

    /**
     * \brief Cylinder constructor with a set of coordinates, radius and length specified.
     *
     * This constructor will create a Cylinder centered on the (x, y, z), with the radius and length specified.
     *
     * @param x x coordinate of the center of the Cylinder.
     * @param y y coordinate of the center of the Cylinder.
     * @param z z coordinate of the center of the Cylinder.
     * @param radius radius of the Cylinder base.
     * @param len length of the Cylinder.
     */
    Cylinder(double x, double y, double z, double radius, double len);

    /**
     * \brief Cylinder destructor.
     */
    ~Cylinder();

    virtual Object* clone() const;
    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_SPHERE_H
