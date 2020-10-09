#include "Cam.h"
#include "constants.h"
#include "color.h"
#include "endian.h"
#include <cmath>

Cam::Cam() {
    this->orig = Vec3::O;
    this->dir = Vec3::X;
    this->right = Vec3::Y;
    this->up = Vec3::Z;

    this->width = 1;
    this->height = 1;
}

Cam::Cam(Vec3 orig, Vec3 dir, const Vec3& right, double width, double height) {
    this->orig = orig;
    this->dir = dir;
    this->right = right.normal();
    this->up = (dir ^ right).normal();

    this->width = width;
    this->height = height;
}

bool Cam::get_pixel(Object* scene, int x, int y, int w, int h, double* t, Vec3* impact, Vec3* normal, const Object** obj) const {
    Ray ray = this->ray(x, y, w, h);
    bool hit = false;
    *t = MAX_DIST;

    hit = ray.intersect(scene, t, impact, normal);
    if(hit) {
        *obj = scene->get_intersecting(*impact);
    }

    return hit;
}

#define pi std::acos(-1)
inline double clamp(double min, double max, double val) {
    return std::min(std::max(min, val), max);
}
static rgb_color shade(Object* scene, Vec3 normal, Vec3 ray, Vec3 impact, double dist, const Object* obj) {
    static Vec3 lightsource = Vec3(2, -1, -1);
    Ray rayToLight = Ray(lightsource, impact-lightsource);
    double distToLight = MAX_DIST;
    Vec3 normalToLight;
    Vec3 impactToLight;
    rayToLight.intersect(scene, &distToLight, &impactToLight, &normalToLight);
    if(obj!=scene->get_intersecting(impactToLight)) return {0, 0, 0};
    double angleToLight = (lightsource-impact).angle_to(normal);
    distToLight = (impactToLight-impact).hypot();

    double angle = ray.angle_to(normal);
    hsv_color hsv = {
        h: 45 - angle * 180 / pi / 2,
        s: clamp(0., 1., angleToLight / pi),
        v: clamp(0., 1., 5 / (distToLight*distToLight))
    };
    return hsv_to_rgb(hsv);
}

Image Cam::render(Object* scene, int w, int h) {
    Image img = Image(w, h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            double t;
            Vec3 impact, normal;
            const Object* obj;
            bool hit = get_pixel(scene, x, y, w, h, &t, &impact, &normal, &obj);

            if (hit) {
                rgb_color rgb = shade(scene, normal, orig-impact, impact, t, obj);
                img.pixel(x, y, rgb);
            } else {
                img.pixel(x, y, rgb_black);
            }
        }
    }
    return img;
}
