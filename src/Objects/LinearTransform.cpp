#include "Objects/LinearTransform.h"

LinearTransform::LinearTransform(Object* obj, const Mat3& m) : Unop(obj) {
    this->m = m;
    this->i = m.invert();
}

double LinearTransform::distance_to(const Vec3& point) const {
    return this->obj->distance_to(this->i * point);
}

Vec3 LinearTransform::normal_at(const Vec3& point) const {
    return this->m * this->obj->normal_at(this->i * point);
}

const Material* LinearTransform::get_intersecting(const Vec3& point) const {
    return this->obj->get_intersecting(this->i * point);
}

Mat3 LinearTransform::scale(double x, double y, double z) {
    return {
        x, 0, 0,
        0, y, 0,
        0, 0, z
    };
}

Mat3 LinearTransform::swapXY = {
    0, 1, 0,
    1, 0, 0,
    0, 0, 1
};

Mat3 LinearTransform::swapXZ = {
    0, 0, 1,
    0, 1, 0,
    1, 0, 0
};

Mat3 LinearTransform::swapYZ = {
    1, 0, 0,
    0, 0, 1,
    0, 1, 0
};

Mat3 LinearTransform::rotateX(double t) {
    double s = std::sin(t);
    double c = std::cos(t);
    return {
        +1, +0, +0,
        +0, +c, -s,
        +0, +s, +c
    };
}

Mat3 LinearTransform::rotateY(double t) {
    double s = std::sin(t);
    double c = std::cos(t);
    return {
        +c, +0, +s,
        +0, +1, +0,
        -s, +0, +c
    };
}

Mat3 LinearTransform::rotateZ(double t) {
    double s = std::sin(t);
    double c = std::cos(t);
    return {
        +c, +s, +0,
        -s, +c, +0,
        +0, +0, +1
    };
}

Mat3 LinearTransform::rotate(double yaw, double pitch, double roll) {
    return LinearTransform::rotateX(yaw) * LinearTransform::rotateY(pitch) * LinearTransform::rotateZ(roll);
}
