#include "Object.h"
#include "constants.h"
#include <cmath>


Vec3 Object::normal_at(const Vec3& point) const {
    double v, x, y, z;

    v = distance_to(point);
    x = distance_to(point + Vec3::X * EPSILON) - v;
    y = distance_to(point + Vec3::Y * EPSILON) - v;
    z = distance_to(point + Vec3::Z * EPSILON) - v;

    return Vec3(x, y, z).normal();
}

const Material* Object::get_intersecting(const Vec3&) const {
    return &Material::white;
}
