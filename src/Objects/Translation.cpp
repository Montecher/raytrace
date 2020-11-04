#include "Objects/Translation.h"

Translation::Translation(const Object* obj, const Vec3 translate) : Unop(obj) {
    this->translate = translate;
}

Object* Translation::clone() const {
    return new Translation(obj->clone(), translate);
}

double Translation::distance_to(const Vec3& point) const {
    return obj->distance_to(point - translate);
}

const Material* Translation::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
}
