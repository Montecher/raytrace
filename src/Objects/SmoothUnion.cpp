#include "Objects/SmoothUnion.h"

SmoothUnion::SmoothUnion(const Object *obj1, const Object *obj2) : Union(obj1, obj2) {
    this->r = 0.5;
}

SmoothUnion::SmoothUnion(const Object *obj1, const Object *obj2, double r) : Union(obj1, obj2) {
    this->r = r;
}

SmoothUnion::SmoothUnion(const Object* obj1, const Object* obj2, const Object* obj3, double r) : Union(new SmoothUnion(obj1, obj2, r), obj3) {
    this->r = r;
}

SmoothUnion::SmoothUnion(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4, double r) : Union(new SmoothUnion(obj1, obj2, r), new SmoothUnion(obj3, obj4, r)) {
    this->r = r;
}

Object* SmoothUnion::clone() const {
    return new SmoothUnion(obj1->clone(), obj2->clone(), r);
}

double SmoothUnion::distance_to(const Vec3& point) const {
    double dt1 = obj1->distance_to(point);
    double dt2 = obj2->distance_to(point);
    double h = std::max(r - std::abs(dt1-dt2), 0.) / r;

    return std::min(dt1, dt2) - h*h*h*r/6.;
}

const Material* SmoothUnion::get_intersecting(const Vec3& point) const {
    return obj1->get_intersecting(point);
}

Vec3 SmoothUnion::normal_at(const Vec3& point) const {
    return Object::normal_at(point);
}
