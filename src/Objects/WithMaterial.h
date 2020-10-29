#ifndef __OBJECTS_WITHMATERIAL_H
#define __OBJECTS_WITHMATERIAL_H
#include "Objects/Unop.h"

/**
 * \class WithMaterial
 * \brief Changes the Material of its Object.
 *
 * This Object will change the material of its represented Object with the new Material specified.
 */
class WithMaterial: public Unop {
protected:
    const Material* material;  ///< new Material.

public:
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

#endif
