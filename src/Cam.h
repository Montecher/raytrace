#ifndef RAYTRACE_CAM_H
#define RAYTRACE_CAM_H

#include "Vec3.h"
#include "Ray.h"

class Cam {
protected:
    Vec3 center;
    Vec3 dir, right;
    double fovW, fovH;

public:
    Cam();
    Cam(const Vec3&, const Vec3&, const Vec3&, double, double);

    void setCenter(const Vec3&);
    void setDir(const Vec3&, const Vec3&);

    Ray getRay(int x, int y, int maxX, int maxY);
};

#endif
