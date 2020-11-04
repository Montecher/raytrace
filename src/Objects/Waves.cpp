#include "Objects/Waves.h"
#include <cmath>

Object* Waves::clone() const {
    return new Waves;
}

double Waves::distance_to(const Vec3& point) const {
    double dist = std::sin(point.get_x()) + std::sin(point.get_y()) + point.get_z();
    return dist / std::sqrt(3);
}

Vec3 Waves::normal_at(const Vec3& point) const {
    return Vec3(-std::cos(point.get_x()), -std::cos(point.get_y()), 1).normal();
}
