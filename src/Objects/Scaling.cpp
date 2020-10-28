#include "Objects/Scaling.h"

Scaling::Scaling(const Object* obj, const double factor) : Unop(obj) {
    if (factor == 0) {
        throw std::invalid_argument("the scaling factor can't be 0 !");
    }

    this->factor = factor;
}

double Scaling::distance_to(const Vec3& point) const {
    return obj->distance_to(point/factor) * factor;
}

const Material* Scaling::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
}
