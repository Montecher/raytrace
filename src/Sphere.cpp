//
// Created by ara0n on 9/17/20.
//

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

void Sphere::info() {
    std::cout << "coordinates of the center of the sphere: " << center << std::endl;
    std::cout << "radius: " << radius << std::endl;
}

std::ostream& operator<<(std::ostream& output, const Sphere& sphere){
    output << "center: " << sphere.center << " radius: " << sphere.radius;
    return output;
}
