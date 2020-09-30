#include <cmath>
#include "Vec3.h"


// static x, y, z vectors
Vec3 Vec3::X = Vec3(1, 0, 0);
Vec3 Vec3::Y = Vec3(0, 1, 0);
Vec3 Vec3::Z = Vec3(0, 0, 1);
Vec3 Vec3::O = Vec3();


// constructors
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
