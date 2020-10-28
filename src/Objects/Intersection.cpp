#include "Objects/Intersection.h"

Intersection::Intersection(const Object* obj1, const Object* obj2) : Binop(obj1, obj2) {}

Intersection::Intersection(const Object* obj1, const Object* obj2, const Object* obj3) : Binop(new Intersection(obj1, obj2), obj3) {}

Intersection::Intersection(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4) : Binop(new Intersection(obj1, obj2), new Intersection(obj3, obj4)) {}

double Intersection::distance_to(const Vec3& point) const {
    return std::max(obj1->distance_to(point), obj2->distance_to(point));
}

const Material* Intersection::get_intersecting(const Vec3& point) const {
    return this->obj1->get_intersecting(point);
}
