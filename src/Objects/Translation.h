#ifndef __OBJECTS_TRANSLATION_H
#define __OBJECTS_TRANSLATION_H
#include "Objects/Unop.h"

/**
 * \class Translation
 *
 * \brief Object representing the translation of its Object.
 *
 * This class allows you to translate an Object by a distance characterised by a Vec3.
 */
class Translation: public Unop {
protected:
    Vec3 translate;  ///< Vec3 giving the translation amount.

public:
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

#endif
