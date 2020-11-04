#include "Objects/Plane.h"

Plane::Plane(const Vec3& normal, double offset) {
    double norm = normal.hypot();

    this->normal = normal/norm;
    this->offset = offset/norm;
}

Plane::Plane(double x, double y, double z, double offset) {
    Vec3 normal = Vec3(x, y, z);
    double norm = normal.hypot();

    this->normal = normal/norm;
    this->offset = offset/norm;
}

Object* Plane::clone() const {
    return new Plane(normal, offset);
}

double Plane::distance_to(const Vec3& point) const {
    return point * normal + offset;
}

Vec3 Plane::normal_at(const Vec3&) const {
    return normal;
}
