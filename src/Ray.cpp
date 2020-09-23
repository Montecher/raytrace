#include "Ray.h"

Ray::Ray(Vec3 orig, Vec3 dir) {
	this->orig = orig;
	this->dir = dir.normal();
}

std::ostream& operator<<(std::ostream& output, const Ray& ray){
    output << "(x, y, z) = " << ray.orig << " + t * " << ray.dir;
    return output;
}
