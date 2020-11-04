#ifndef __OBJECTS_SMOOTHUNION_H
#define __OBJECTS_SMOOTHUNION_H
#include "Objects/Union.h"

/**
 * \class SmoothUnion
 * \brief A smoothed out Union.
 *
 * This is a version of Union that smooths the junctions between the two objects. To be properly used, all the objects used in it must have the same materials.
 */
class SmoothUnion: public Union {
protected:
    double r;  ///< smoothing radius
public:
    /**
     * \brief SmoothUnion constructor for 2 objects with default radius.
     *
     * @param obj1 First object of the SmoothUnion.
     * @param obj2 Second object of the SmoothUnion.
     */
    SmoothUnion(const Object* obj1, const Object* obj2);

    /**
     * \brief SmoothUnion constructor for 2 objects and a radius.
     *
     * @param obj1 First object of the SmoothUnion.
     * @param obj2 Second object of the SmoothUnion.
     * @param r radius of the smoothing effect.
     */
    SmoothUnion(const Object* obj1, const Object* obj2, double r);

    /**
     * \brief Union constructor for 4 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = new SmoothUnion(obj1, oj2)
     *  - this->obj2 = obj3
     *
     * @param obj1 First object of the SmoothUnion.
     * @param obj2 Second object of the SmoothUnion.
     * @param obj3 Third object of the SmoothUnion.
     * @param r radius of the smoothing effect.
     */
    SmoothUnion(const Object* obj1, const Object* obj2, const Object* obj3, double r);

    /**
     * \brief Union constructor for 4 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = new SmoothUnion(obj1, oj2)
     *  - this->obj2 = new SmoothUnion(obj3, obj4)
     *
     * @param obj1 First object of the SmoothUnion.
     * @param obj2 Second object of the SmoothUnion.
     * @param obj3 Third object of the SmoothUnion.
     * @param obj4 Fourth object of the SmoothUnion.
     * @param r radius of the smoothing effect.
     */
    SmoothUnion(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4, double r);

    virtual Object* clone() const;
    virtual double distance_to(const Vec3& point) const;
    virtual const Material* get_intersecting(const Vec3& point) const;
    virtual Vec3 normal_at(const Vec3& point) const;
};

#endif
