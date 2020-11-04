#include "Objects/Negation.h"

Negation::Negation(Object* obj): Unop(obj) {}

Object* Negation::clone() const {
    return new Negation(obj->clone());
}

double Negation::distance_to(const Vec3& point) const {
    return -obj->distance_to(point);
}

const Material* Negation::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
}
