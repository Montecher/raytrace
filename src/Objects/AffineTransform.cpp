#include "Objects/AffineTransform.h"

AffineTransform::AffineTransform(Object* obj, const Mat3& m, const Vec3& d) : Unop(obj) {
    this->m = m;
    this->i = m.invert();
    this->d = d;
}

Object* AffineTransform::clone() const {
    return new AffineTransform(obj->clone(), m, d);
}

double AffineTransform::distance_to(const Vec3& point) const {
    return this->obj->distance_to(this->i * point - d);
}

Vec3 AffineTransform::normal_at(const Vec3& point) const {
    return this->m * this->obj->normal_at(this->i * point - d);
}

const Material* AffineTransform::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(this->i * point - d);
}
