#include "Objects/Torus.h"
#include <cmath>

Torus::Torus() {
    this->center = Vec3::O;
    this->radius = 1.;
    this->thickness = .1;
}

Torus::Torus(const Vec3& center, double radius, double thickness) {
    this->center = center;
    this->radius = radius;
    this->thickness = thickness;
}

Torus::Torus(double x, double y, double z, double radius, double thickness) {
    this->center = { x, y, z };
    this->radius = radius;
    this->thickness = thickness;
}

double Torus::distance_to(const Vec3& point) const {
    double dX = point.get_x() - center.get_x();
    double dY = point.get_y() - center.get_y();
    double dH = std::abs(std::sqrt(dX*dX + dY*dY) - radius);

    double dZ = point.get_z() - center.get_z();
    return std::sqrt(dH*dH + dZ*dZ) - thickness;
}
