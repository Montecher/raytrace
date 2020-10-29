#ifndef RAYTRACE_CAM_H
#define RAYTRACE_CAM_H

#include "Vec3.h"
#include "Object.h"
#include "Ray.h"
#include "Image.h"
#include <vector>
#include <string>

class Cam {
private:
    Vec3 orig, dir, right, up;
    double width, height;

    Ray ray(int, int, int, int) const;
    bool get_pixel(Object*, int, int, int, int, double*, Vec3*, Vec3*, const Material**) const;

public:
    Cam();
    Cam(Vec3, Vec3, const Vec3&, double , double);

    void setPos(const Vec3&);
    void setPointing(const Vec3&);

    Image render_shaded(Object*, int, int) const;
    Image render_realistic(Object*, int, int, int samples=RPP, int depth=DEPTH) const;

    friend std::ostream& operator << (std::ostream&, const Cam&);
};

inline Ray Cam::ray(int x, int y, int w, int h) const {
    double dx = (x / (w - 1.) - 0.5) * this->width;
    double dy = (y / (h - 1.) - 0.5) * this->height;
    Vec3 dir = (this->dir + this->right * dx - this->up * dy).normal();
    return Ray(this->orig, dir);
}

inline std::ostream& operator << (std::ostream& out, const Cam& cam) {
    return out << "Cam(orig=" << cam.orig << "; dir=" << cam.dir << "; right=" << cam.right << "; up=" << cam.up << "; width=" << cam.width << "; height=" << cam.height << ")";
}

#endif
