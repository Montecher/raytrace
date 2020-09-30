#include <iostream>
#include "Sphere.h"
#include "Vec3.h"

Sphere::Sphere() {
    this->center = Vec3();
    this->radius = 0;
}

Sphere::Sphere(Vec3 vec3, double radius) {
    this->center = vec3;
    this->radius = radius;
}

Sphere::Sphere(double x, double y, double z, double radius) {
    this->center = Vec3(x, y, z);
    this->radius = radius;
}

Sphere::~Sphere() {}

double Sphere::distance_to(const Vec3& point) const {
    return (center - point).hypot() - radius;
}

Vec3 Sphere::normal_at(const Vec3& point) const {
    return (point - center).normal();
}
