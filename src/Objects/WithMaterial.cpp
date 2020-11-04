#include "Objects/WithMaterial.h"

WithMaterial::WithMaterial(const Object* obj, const Material* material) : Unop(obj) {
    this->material = material;
}

Object* WithMaterial::clone() const {
    return new WithMaterial(obj->clone(), material);
}

double WithMaterial::distance_to(const Vec3& point) const {
    return obj->distance_to(point);
}

const Material* WithMaterial::get_intersecting(const Vec3&) const {
    return this->material;
}
