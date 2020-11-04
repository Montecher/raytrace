#ifndef __OBJECTS_LINEARTRANSFORM_H
#define __OBJECTS_LINEARTRANSFORM_H
#include "Objects/Unop.h"
#include "Mat3.h"

/**
 * \class LinearTransform
 * \brief Linear transformtion of an object.
 *
 * Includes rotation, Scaling, shearing.
 */
class LinearTransform : public Unop {
protected:
    Mat3 m;  ///< tranformation matrix.
    Mat3 i;  ///< inverse of m.

public:
    /**
     * \brief LinearTransform constructor.
     *
     * @param obj Object to be transformed.
     * @param m transformation matrix.
     */
    LinearTransform(Object* obj, const Mat3& m);

    virtual Object* clone() const;
    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;

    /**
     * \brief scaling operation
     *
     * Scales in all 3 axis with the specified amount.
     *
     * @param x x axis.
     * @param y y axis.
     * @param z z axis.
     * @return scaling matrix.
     */
    static Mat3 scale(double x, double y, double z);

    static Mat3 swapXY;  ///< swaps X and Y values
    static Mat3 swapXZ;  ///< swaps X and Z values
    static Mat3 swapYZ;  ///< swaps Y and Z values

    /**
     * \brief rotation on the X axis by theta.
     *
     * @param t angle theta of rotation.
     * @return X rotation matrix.
     */
    static Mat3 rotateX(double t);

    /**
     * \brief rotation on the Y axis by theta.
     *
     * @param t angle theta of rotation.
     * @return Y rotation matrix.
     */
    static Mat3 rotateY(double t);

    /**
     * \brief rotation on the Z axis by theta.
     *
     * @param t angle theta of rotation.
     * @return Z rotation matrix.
     */
    static Mat3 rotateZ(double t);

    /**
     * \brief rotation on all 3 axis.
     *
     * @param yaw angle of rotation for the X axis.
     * @param pitch angle of rotation for the Y axis.
     * @param roll angle of rotation for the Z axis.
     * @return roattion matrix.
     */
    static Mat3 rotate(double yaw, double pitch, double roll);
};

#endif
