#include "Ray.h"
#include "constants.h"

Ray::Ray(Vec3 orig, Vec3 dir) {
	this->orig = orig;
	this->dir = dir.normal();
}

bool Ray::intersect(Object* object, double* t, Vec3* impact, Vec3* normal) const {
    double last_t = EPSILON*10;
    double max_t = std::min(*t, MAX_DIST);

    while (last_t < max_t) {
        Vec3 current_pos = point(last_t);
        double dist = object->distance_to(current_pos);

        if (dist <= 0) {
            *normal = object->normal_at(current_pos);
            *impact = current_pos;
            *t = last_t;
            return true;
        }

        if (dist < EPSILON) {
            dist = EPSILON;
        }
        last_t += dist;
    }
    return false;
}
