#ifndef RAYTRACE_BOX_H
#define RAYTRACE_BOX_H

#include "Object.h"


/**
 * \class Box
 * \brief Representation of a 3D Box.
 *
 * This Object manages all the box-shaped objects.
 */
class Box: public Object {
private:
    Vec3 a;  ///< minimal point of the Box.
    Vec3 b;  ///< maximal point of the Box.

public:
    /**
     * \brief Box default constructor.
     *
     * This will create a Box centered on (0, 0, 0) with the minimal point in (-0.5, -0.5, -0.5) and the maximal point in (0.5, 0.5, 0.5).
     */
    Box();

    /**
     * \brief Single point Box constructor.
     *
     * This will use the specified point and (0, 0, 0) to construct the Box.
     *
     * @param point point used to construct the Box.
     */
    Box(Vec3 point);

    /**
     * \brief Single set of point coordinates Box constructor.
     *
     * This constructor will use the set of coordinates specified for a point (x, y, z) and (0, 0, 0) for the other point.
     *
     * @param x x coordinate of the point.
     * @param y y coordinate of the point.
     * @param z z coordinate of the point.
     */
    Box(double x, double y, double z);

    /**
     * \brief 2 point Box constructor.
     *
     * This contructor will use both points specified to build the Box.
     *
     * @param point1 first point used.
     * @param point2 second point used.
     */
    Box(Vec3 point1, Vec3 point2);

    /**
     * \brief 2 set of point coordinates Box constructor.
     *
     * this contructor will use the first set of coordinates to make the first point (xa, ya, za) and the sceond set of coordinates to make the second point (xb, yb, zb).
     *
     * @param xa x coordinate of the first point.
     * @param ya y coordinate of the first point.
     * @param za z coordinate of the first point.
     * @param xb x coordinate of the second point.
     * @param yb y coordinate of the second point.
     * @param zb z coordinate of the second point.
     */
    Box(double xa, double ya, double za, double xb, double yb, double zb);

    virtual double distance_to(const Vec3&) const;
//    virtual Vec3 normal_at(const Vec3&) const;
};


#endif //RAYTRACE_BOX_H
