#include "Object.h"
#include "constants.h"
#include <cmath>


// Object section
//double Object::distance_to(const Vec3 &) const {
//    std::cout << "wsh" << std::endl;
//    return INFINITY;
//}

Vec3 Object::normal_at(const Vec3& point) const {
    double v, x, y, z;

    v = distance_to(point);
    x = distance_to(point + Vec3::X * EPSILON) - v;
    y = distance_to(point + Vec3::Y * EPSILON) - v;
    z = distance_to(point + Vec3::Z * EPSILON) - v;

    return Vec3(x, y, z).normal();
}


// Intersection section
//Intersection::Intersection(const Object objects...) {
//    this->elements = std::vector<Object>(objects...);
//}
Intersection::Intersection(const Object* obj1, const Object* obj2) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

Intersection::~Intersection() {
    delete this->obj1;
    delete this->obj2;
}

double Intersection::distance_to(const Vec3& point) const {
    return std::max(obj1->distance_to(point), obj2->distance_to(point));
}

// Union section
Union::Union(const Object* obj1, const Object* obj2) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

Union::~Union() {
    delete this->obj1;
    delete this->obj2;
}

double Union::distance_to(const Vec3& point) const {
    return std::min(obj1->distance_to(point), obj2->distance_to(point));
}

// Negation section
Negation::Negation(const Object* obj) {
    this->obj = obj;
}

Negation::~Negation() {
    delete this->obj;
}

double Negation::distance_to(const Vec3& point) const {
    return -obj->distance_to(point);
}

// Exclusion section
Exclusion::Exclusion(const Object* obj1, const Object* obj2) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

Exclusion::~Exclusion() {
    delete this->obj1;
    delete this->obj2;
}

double Exclusion::distance_to(const Vec3& point) const {
    return std::max(obj1->distance_to(point), -obj2->distance_to(point));
}
