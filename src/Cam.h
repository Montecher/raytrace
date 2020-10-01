#ifndef RAYTRACE_CAM_H
#define RAYTRACE_CAM_H

#include "Vec3.h"
#include "Object.h"
#include "Ray.h"
#include <vector>
#include <string>

class Cam {
private:
    Vec3 orig, dir, right, up;
    double width, height;

    Ray ray(int, int, int, int) const;
    bool get_pixel(std::vector<Object*>, int, int, int, int, double*, Vec3*, Vec3*) const;

public:
    Cam();
    Cam(Vec3, Vec3, const Vec3&, double , double);

    std::string render_string(std::vector<Object*>, int, int);
    std::string render_raw(std::vector<Object*>, int, int);
};

inline Ray Cam::ray(int x, int y, int w, int h) const {
    double dx = (x / (w - 1.) - 0.5) * this->width;
    double dy = (y / (h - 1.) - 0.5) * this->height;
    Vec3 dir = (this->dir + this->right * dx - this->up * dy).normal();
    return Ray(this->orig, dir);
}

#endif
