#include "Objects/AffineTransform.h"

AffineTransform::AffineTransform(Object* obj, const Mat3& m, const Vec3& d) : Unop(obj) {
    this->m = m;
    this->i = m.invert();
    this->d = d;
}

double AffineTransform::distance_to(const Vec3& point) const {
    return this->obj->distance_to(this->i * point - d);
}

Vec3 AffineTransform::normal_at(const Vec3& point) const {
    return this->m * this->obj->normal_at(this->i * point - d);
}

const Material* AffineTransform::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(this->i * point - d);
}

Mat3 AffineTransform::scale(double x, double y, double z) {
    return {
        x, 0, 0,
        0, y, 0,
        0, 0, z
    };
}

Mat3 AffineTransform::swapXY = {
    0, 1, 0,
    1, 0, 0,
    0, 0, 1
};

Mat3 AffineTransform::swapXZ = {
    0, 0, 1,
    0, 1, 0,
    1, 0, 0
};

Mat3 AffineTransform::swapYZ = {
    1, 0, 0,
    0, 0, 1,
    0, 1, 0
};

Mat3 AffineTransform::rotateX(double t) {
    double s = std::sin(t);
    double c = std::cos(t);
    return {
        +1, +0, +0,
        +0, +c, -s,
        +0, +s, +c
    };
}

Mat3 AffineTransform::rotateY(double t) {
    double s = std::sin(t);
    double c = std::cos(t);
    return {
        +c, +0, +s,
        +0, +1, +0,
        -s, +0, +c
    };
}

Mat3 AffineTransform::rotateZ(double t) {
    double s = std::sin(t);
    double c = std::cos(t);
    return {
        +c, +s, +0,
        -s, +c, +0,
        +0, +0, +1
    };
}

Mat3 AffineTransform::rotate(double yaw, double pitch, double roll) {
    return AffineTransform::rotateX(yaw) * AffineTransform::rotateY(pitch) * AffineTransform::rotateZ(roll);
}
