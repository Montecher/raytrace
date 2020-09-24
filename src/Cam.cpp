#include "Cam.h"

Cam::Cam() {
    this->center = Vec3();
    this->dir = Vec3(1.0, 0.0, 0.0);
    this->right = Vec3(0.0, 0.0, 1.0);
}

Cam::Cam(const Vec3& center, const Vec3& dir, const Vec3& right, double fovW, double fovH) {
    this->center = center;
    this->dir = dir;
    this->right = right.normal();
    this->fovW = fovW;
    this->fovH = fovH;
}

void Cam::setCenter(const Vec3& center) {
    this->center = center;
}

void Cam::setDir(const Vec3& dir, const Vec3& right) {
    this->dir = dir;
    this->right = right;
}

Ray Cam::getRay(int x, int y, int maxX, int maxY) {
   double left = this->fovW * ( ( x / (double)(maxX-1) ) - 0.5 );
   double top = this->fovH * ( ( y / (double)(maxY-1) ) - 0.5 );
   Vec3 up = (this->dir * this->right).normal();

   Vec3 dir = (this->dir + this->right * -left + up * top).normal();
   return Ray(this->center, dir);
}
