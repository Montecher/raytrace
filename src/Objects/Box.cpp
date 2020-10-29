#include "Objects/Box.h"

Box::Box() {
    this->a = Vec3(-0.5, -0.5, -0.5);
    this->b = Vec3(0.5, 0.5, 0.5);
}

Box::Box(Vec3 point) {
    this->a = Vec3(std::min(0., point.get_x()), std::min(0., point.get_y()), std::min(0., point.get_z()));
    this->b = Vec3(std::max(0., point.get_x()), std::max(0., point.get_y()), std::max(0., point.get_z()));
}

Box::Box(double x, double y, double z) {
    this->a = Vec3(std::min(0., x), std::min(0., y), std::min(0., z));
    this->b = Vec3(std::max(0., x), std::max(0., y), std::max(0., z));
}

Box::Box(Vec3 point1, Vec3 point2) {
    this->a = Vec3(std::min(point1.get_x(), point2.get_x()), std::min(point1.get_y(), point2.get_y()), std::min(point1.get_z(), point2.get_z()));
    this->b = Vec3(std::max(point1.get_x(), point2.get_x()), std::max(point1.get_y(), point2.get_y()), std::max(point1.get_z(), point2.get_z()));
}

Box::Box(double xa, double ya, double za, double xb, double yb, double zb) {
    this->a = Vec3(std::min(xa, xb), std::min(ya, yb), std::min(za, zb));
    this->b = Vec3(std::max(xa, xb), std::max(ya, yb), std::max(za, zb));
}



double Box::distance_to(const Vec3& point) const {
    return std::max(
        std::max(a.get_x() - point.get_x(), std::max(a.get_y() - point.get_y(), a.get_z() - point.get_z())),
        std::max(point.get_x() - b.get_x(), std::max(point.get_y() - b.get_y(), point.get_z() - b.get_z()))
    );
}

//Vec3 Box::normal_at(const Vec3& point) const {
//
//}
