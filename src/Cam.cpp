#include "Cam.h"
#include "constants.h"

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

bool Cam::get_pixel(std::vector<Object*> scene, int x, int y, int w, int h, double* t, Vec3* impact, Vec3* normal) const {
    Ray ray = this->ray(x, y, w, h);
    bool hit = false;
    *t = MAX_DIST;

    for (auto obj: scene) {
        hit |= ray.intersect(obj, t, impact, normal);
    }
    return hit;
}

std::string Cam::render_string(std::vector<Object*> scene, int w, int h) {
    std::string render = "";

    for (int y = 0; y < h; y++) {
        if (y != 0) {
            render += "\n";
        }

        for (int x = 0; x < w; x++) {
            double t;
            Vec3 impact, normal;
            bool hit = get_pixel(scene, x, y, w, h, &t, &impact, &normal);

            if (hit) {
                render += "\xe2\x96\x88";
            } else {
                render += " ";
            }
        }
    }

    return render;
}
