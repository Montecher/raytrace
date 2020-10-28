#ifndef RAYTRACE_OBJECT_H
#define RAYTRACE_OBJECT_H

#include <iostream>
#include "Material.h"
#include "Vec3.h"

/**
 * \class Object
 * \brief Abstract class responsible of the priciple of the 3D objects.
 *
 * All the created 3D objects need to inherit from this abstract class to be able to work.
 */
class Object {
public:
    /**
     * Object destructor
     */
    virtual ~Object() {};

    /**
     * \brief Computes the distance to some point in space.
     *
     * This function computes a minimal distance between the Object itself and the specified point.
     *
     * \param point Point the distance is asked to.
     *
     * @return A minimal distance between the object and the point.
     */
    virtual double distance_to(const Vec3& point) const = 0;

    /**
     * \brief Computes the normal at a certain point from the surface.
     *
     * This function determines the normal from a point compared to the surface of the Object.
     *
     * @param point Point from which the normal is asked from.
     *
     * @return The normal from the point.
     */
    virtual Vec3 normal_at(const Vec3& point) const;

    /**
     * \brief Gives the Material of the Object at the intersection point.
     * This function is the way to get an access to the Material of the Object currently being rendered.
     *
     * @param point Point of the intersection with the Object.
     * @return Material of the intersected Object.
     */
    virtual const Material* get_intersecting(const Vec3& point) const;
};


/**
 * \class Intersection
 * \brief This Object codes the intersection of 2 objects.
 *
 * This Object is the concept of a composite object having the shape of the common part of all it's composing Object.
 */
class Intersection: public Object {
protected:
    const Object* obj1;  ///< first object in the Intersection.
    const Object* obj2;  ///< second object in the Intersection.

public:
    /**
     * Intersection destructor.
     */
    ~Intersection();

    /**
     * \brief Intersection constructor for 2 objects.
     *
     * @param obj1 First object of the Intersection.
     * @param obj2 Second object of the Instersection.
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
};


/**
 * \class Union
 * \brief This Object codes the union of 2 objects.
 *
 * This Object is the concept of a composite Object having the shape of the exterior part of all it's composing Objects.
 */
class Union: public Object {
protected:
    const Object* obj1;  ///< first object in the Union.
    const Object* obj2;  ///< first object in the Union.

public:
    /**
     * Union destructor.
     */
    ~Union();

    /**
     * \brief Union constructor for 2 objects.
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
};


/**
 * \class Negation
 * \brief This object codes the negation of an object.
 *
 * This Object is the concept of inverting the filled and non filled part of the Object given to the constructor, ie the interior becomes the exterior and vice-versa.
 */
class Negation: public Object {
protected:
    const Object* obj;  ///< Object that will be inverted.

public:
    /**
     * Negation destructor.
     */
    ~Negation();

    /**
     * Negation constructor.
     * @param obj Object that is asked to be inverted.
     */
    Negation(const Object* obj);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};


/**
 * \class Exclusion
 *
 * \brief This object code the exclusion of an object on another.
 *
 * This Object is the concept of taking a first Object and remove any part it has in common with a second Object.
 */
class Exclusion: public Object {
protected:
    const Object* obj1;  ///< main Object
    const Object* obj2;  ///< Object being excluded

public:
    /**
     * Exclusion destructor.
     */
    ~Exclusion();

    /**
     * Exclusion constructor.
     *
     * @param obj1 Main Object.
     * @param obj2 Object being removed from the other one.
     */
    Exclusion(const Object* obj1, const Object* obj2);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};


/**
 * \class Translation
 *
 * \brief Object representing the translation of its Object.
 *
 * This class allows you to translate an Object by a distance characterised by a Vec3.
 */
class Translation: public Object {
protected:
    const Object* obj;  ///< Object being translated.
    Vec3 translate;  ///< Vec3 giving the translation amount.

public:
    /**
     * Translation destructor.
     */
    ~Translation();

    /**
     * \brief Translation constructor.
     *
     * @param obj Object being translated.
     * @param translate Translation amount.
     */
    Translation(const Object* obj, const Vec3 translate);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};


/**
 * \class Scaling
 *
 * \brief Object representing the scaling of an Object.
 *
 * This Object scales it's inputted object by the asked factor.
 */
class Scaling: public Object {
protected:
    const Object* obj;  ///< Object to be scaled.
    double factor;  ///< scale factor.

public:
    /**
     * Scaling destructor.
     */
    ~Scaling();

    /**
     * \brief Scaling constructor.
     *
     * @param obj Object to be scaled.
     * @param factor scaling factor.
     */
    Scaling(const Object* obj, const double factor);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};


/**
 * \class WithMaterial
 * \brief Changes the Material of its Object.
 *
 * This Object will change the material of its represented Object with the new Material specified.
 */
class WithMaterial: public Object {
protected:
    const Object* obj;  ///> Object to be changed.
    const Material* material;  ///< new Material.

public:
    /**
     * WithMaterial destructor.
     */
    ~WithMaterial();

    /**
     * \brief WithMaterial contructor.
     *
     * @param obj Object to be changed.
     * @param material new Material.
     */
    WithMaterial(const Object* obj, const Material* material);

    virtual double distance_to(const Vec3&) const;
    virtual const Material* get_intersecting(const Vec3&) const;
};

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

    virtual double distance_to(const Vec3& point) const;
    virtual const Material* get_intersecting(const Vec3& point) const;
};


#endif //RAYTRACE_OBJECT_H
