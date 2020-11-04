#include "Objects/Cylinder.h"
#include "Vec3.h"
#include <cmath>

Cylinder::Cylinder() {
    this->center = Vec3();
    this->radius = 1;
    this->len = 1;
}

Cylinder::Cylinder(Vec3 center, double radius, double len) {
    this->center = center;
    this->radius = radius;
    this->len = len;
}

Cylinder::Cylinder(double x, double y, double z, double radius, double len) {
    this->center = Vec3(x, y, z);
    this->radius = radius;
    this->len = len;
}

Object* Cylinder::clone() const {
    return new Cylinder(center, radius, len);
}

Cylinder::~Cylinder() {}

double Cylinder::distance_to(const Vec3& point) const {
    double cZ = center.get_z();
    double pZ = point.get_z();

    double dX = center.get_x() - point.get_x();
    double dY = center.get_y() - point.get_y();
    double circleDist = std::sqrt(dX*dX + dY*dY) - radius;

    double verticalDist = std::abs(cZ - pZ) - len;

    return std::max(circleDist, verticalDist);
}

Vec3 Cylinder::normal_at(const Vec3& point) const {
    double cZ = center.get_z();
    double pZ = point.get_z();

    double dX = center.get_x() - point.get_x();
    double dY = center.get_y() - point.get_y();
    double circleDist = std::sqrt(dX*dX + dY*dY) - radius;

    double verticalDist = std::abs(cZ - pZ) - len;

    if(circleDist > verticalDist) return (point - center).normal();
    else if(cZ < pZ) return Vec3::Z;
    else return -Vec3::Z;
}

