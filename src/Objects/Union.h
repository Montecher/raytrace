#ifndef __OBJECTS_UNION_H
#define __OBJECTS_UNION_H
#include "Objects/Binop.h"

/**
 * \class Union
 * \brief This Object codes the union of 2 objects.
 *
 * This Object is the concept of a composite Object having the shape of the exterior part of all it's composing Objects.
 */
class Union: public Binop {
public:
    /**
     * \brief Union constructor for 2 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = obj1
     *  - this->obj2 = obj2
     *
     * @param obj1 First object of the Union.
     * @param obj2 Second object of the Union.
     */
    Union(const Object* obj1, const Object* obj2);

    /**
     * \brief Union constructor for 3 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = new Union(obj1, oj2)
     *  - this->obj2 = obj3
     *
     * @param obj1 First object of the Union.
     * @param obj2 Second object of the Union.
     * @param obj3 Third object of the Union.
     */
    Union(const Object* obj1, const Object* obj2, const Object* obj3);

    /**
     * \brief Union constructor for 3 objects.
     *
     * The construction will be made as followed:
     *  - this->obj1 = new Union(obj1, oj2)
     *  - this->obj2 = new Union(obj3, obj4)
     *
     * @param obj1 First object of the Union.
     * @param obj2 Second object of the Union.
     * @param obj3 Third object of the Union.
     * @param obj4 Fourth object of the Union.
     */
    Union(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
    virtual Vec3 normal_at(const Vec3&) const;
};

#endif
