#include "Objects/Union.h"

Union::Union(const Object* obj1, const Object* obj2) : Binop(obj1, obj2) {}

Union::Union(const Object* obj1, const Object* obj2, const Object* obj3) : Binop(new Union(obj1, obj2), obj3) {}

Union::Union(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4) : Binop(new Union(obj1, obj2), new Union(obj3, obj4)) {}

double Union::distance_to(const Vec3& point) const {
    return std::min(obj1->distance_to(point), obj2->distance_to(point));
}

const Material* Union::get_intersecting(const Vec3& point) const {
    if(this->obj2->distance_to(point) <= 0.) return this->obj2->get_intersecting(point);
    return this->obj1->get_intersecting(point);
}

Vec3 Union::normal_at(const Vec3& point) const {
    double d1 = this->obj1->distance_to(point);
    double d2 = this->obj2->distance_to(point);
    if(-d1>EPSILON) {
        return this->obj1->normal_at(point);
    } else if(-d2>EPSILON) {
        return this->obj2->normal_at(point);
    } else {
        return Object::normal_at(point);
    }
}
