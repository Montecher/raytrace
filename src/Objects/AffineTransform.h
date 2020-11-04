#ifndef __OBJECTS_AFFINETRANSFORM_H
#define __OBJECTS_AFFINETRANSFORM_H
#include "Objects/Unop.h"
#include "Mat3.h"

/**
 * \class AffineTransform
 * \brief Affine transformation of an Object.
 *
 * This is a combo of a LinearTransform and a Translation.
 */
class AffineTransform : public Unop {
protected:
    Mat3 m;  ///< tranformation matrix.
    Mat3 i;  ///< inverse of m.
    Vec3 d;  ///< displacement vector.

public:
    /**
     * \brief AffineTransform constructor.
     *
     * @param obj Object to be transformed.
     * @param m transformation matrix.
     * @param d displacement vector.
     */
    AffineTransform(Object* obj, const Mat3& m, const Vec3& d);

    virtual Object* clone() const;
    virtual double distance_to(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};

#endif
