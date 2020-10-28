#ifndef __OBJECTS_INTERSECTION_H
#define __OBJECTS_INTERSECTION_H
#include "Objects/Binop.h"

/**
 * \class Intersection
 * \brief This Object codes the intersection of 2 objects.
 *
 * This Object is the concept of a composite object having the shape of the common part of all it's composing Object.
 */
class Intersection: public Binop {
public:
    /**
     * \brief Intersection constructor for 2 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = obj1
     *  - this->obj2 = obj2
     *
     * @param obj1 First object of the Intersection.
     * @param obj2 Second object of the Intersection.
     */
    Intersection(const Object* obj1, const Object* obj2);

    /**
     * \brief Intersection constructor for 3 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = new Intersection(obj1, oj2)
     *  - this->obj2 = obj3
     *
     * @param obj1 First object of the Intersection.
     * @param obj2 Second object of the Intersection.
     * @param obj3 Third object of the Intersection.
     */
    Intersection(const Object* obj1, const Object* obj2, const Object* obj3);

    /**
     * \brief Intersection constructor for 3 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = new Intersection(obj1, oj2)
     *  - this->obj2 = new Intersection(obj3, obj4)
     *
     * @param obj1 First object of the Intersection.
     * @param obj2 Second object of the Intersection.
     * @param obj3 Third object of the Intersection.
     * @param obj4 Fourth object of the Intersection.
     */
    Intersection(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};

#endif
