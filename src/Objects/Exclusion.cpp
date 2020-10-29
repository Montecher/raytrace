#include "Objects/Exclusion.h"

Exclusion::Exclusion(const Object* obj1, const Object* obj2) : Binop(obj1, obj2) {}

double Exclusion::distance_to(const Vec3& point) const {
    return std::max(obj1->distance_to(point), -obj2->distance_to(point));
}

const Material* Exclusion::get_intersecting(const Vec3& point) const {
    return this->obj1->get_intersecting(point);
}
