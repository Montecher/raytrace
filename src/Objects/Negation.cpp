#include "Objects/Negation.h"

double Negation::distance_to(const Vec3& point) const {
    return -obj->distance_to(point);
}

const Material* Negation::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
}
