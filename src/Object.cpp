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


Intersection::Intersection(const Object* obj1, const Object* obj2) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

Intersection::Intersection(const Object* obj1, const Object* obj2, const Object* obj3) {
    this->obj1 = new Intersection(obj1, obj2);
    this->obj2 = obj3;
}

Intersection::Intersection(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4) {
    this->obj1 = new Intersection(obj1, obj2);
    this->obj2 = new Intersection(obj3, obj4);
}

Intersection::~Intersection() {
    delete this->obj1;
    delete this->obj2;
}

double Intersection::distance_to(const Vec3& point) const {
    return std::max(obj1->distance_to(point), obj2->distance_to(point));
}

const Material* Intersection::get_intersecting(const Vec3& point) const {
    return this->obj1->get_intersecting(point);
}

// Union section
Union::Union(const Object* obj1, const Object* obj2) {
    this->obj1 = obj1;
    this->obj2 = obj2;
}

Union::Union(const Object* obj1, const Object* obj2, const Object* obj3) {
    this->obj1 = new Union(obj1, obj2);
    this->obj2 = obj3;
}

Union::Union(const Object* obj1, const Object* obj2, const Object* obj3, const Object* obj4) {
    this->obj1 = new Union(obj1, obj2);
    this->obj2 = new Union(obj3, obj4);
}

Union::~Union() {
    delete this->obj1;
    delete this->obj2;
}

double Union::distance_to(const Vec3& point) const {
    return std::min(obj1->distance_to(point), obj2->distance_to(point));
}

//#include <iostream>
//using namespace std;
const Material* Union::get_intersecting(const Vec3& point) const {
//    cerr << "get_intersecting(" << point << "), hits " << (this->obj2->distance_to(point) <=0 ? "obj2" : "obj1") << " = " << *(this->obj2->distance_to(point) <= 0 ? this->obj2->get_intersecting(point) : this->obj1->get_intersecting(point)) << endl;
    if(this->obj2->distance_to(point) <= 0.) return this->obj2->get_intersecting(point);
    return this->obj1->get_intersecting(point);
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

const Material* Negation::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
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

const Material* Exclusion::get_intersecting(const Vec3& point) const {
    return this->obj1->get_intersecting(point);
}

Translation::Translation(const Object* obj, const Vec3 translate) {
    this->obj = obj;
    this->translate = translate;
}

Translation::~Translation() {
    delete this->obj;
}

double Translation::distance_to(const Vec3& point) const {
    return obj->distance_to(point - translate);
}

const Material* Translation::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
}


Scaling::Scaling(const Object* obj, const double factor) {
    if (factor == 0) {
        throw std::invalid_argument("the scaling factor can't be 0 !");
    }

    this->obj = obj;
    this->factor = factor;
}

Scaling::~Scaling() {
    delete this->obj;
}

double Scaling::distance_to(const Vec3& point) const {
    return obj->distance_to(point/factor) * factor;
}

const Material* Scaling::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(point);
}

WithMaterial::WithMaterial(const Object* obj, const Material* material) {
    this->obj = obj;
    this->material = material;
}

WithMaterial::~WithMaterial() {
    delete this->obj;
}

double WithMaterial::distance_to(const Vec3& point) const {
    return obj->distance_to(point);
}

const Material* WithMaterial::get_intersecting(const Vec3&) const {
    return this->material;
}
