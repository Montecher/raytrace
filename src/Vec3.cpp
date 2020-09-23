#include <cmath>
#include "Vec3.h"


Vec3::Vec3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vec3::Vec3(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// Vector x Vector operations
Vec3 Vec3::operator+(const Vec3& vec3) const {
    return {x + vec3.x, y + vec3.y, z + vec3.z};
}

Vec3 Vec3::operator-(const Vec3& vec3) const {
    return {x - vec3.x, y - vec3.y, z - vec3.z};
}

Vec3 Vec3::operator*(const Vec3& vec3) const {
    return {y*vec3.z - z*vec3.y, z*vec3.x - x*vec3.z, x*vec3.y - y*vec3.x};
}

Vec3 Vec3::operator+=(const Vec3& vec3) {
    *this = *this + vec3;
    return *this;
}

Vec3 Vec3::operator-=(const Vec3& vec3) {
    *this = *this - vec3;
    return *this;
}

Vec3 Vec3::operator*=(const Vec3& vec3) {
    *this = *this * vec3;
    return *this;
}

// Vector x Scalar operation
Vec3 Vec3::operator*(const double scalar) const {
    return {x*scalar, y*scalar, z*scalar};
}

Vec3 Vec3::operator/(const double scalar) const {
    return {x/scalar, y/scalar, z/scalar};
}

Vec3 Vec3::operator*=(const double scalar) {
    *this = *this * scalar;
    return *this;
}

Vec3 Vec3::operator/=(const double scalar) {
    *this = *this / scalar;
    return *this;
}

double Vec3::hypot() const {
    return std::sqrt(x*x + y*y + z*z);
}

Vec3 Vec3::normal() const {
    double norm = this->hypot();
    return *this / norm;
}

std::ostream& operator<<(std::ostream& output, const Vec3& vec3){
    output << "(" << vec3.x << ", " << vec3.y << ", " << vec3.z << ")";
    return output;
}
