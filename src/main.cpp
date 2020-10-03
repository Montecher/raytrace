#include <iostream>
#include "Sphere.h"
#include "Cam.h"
#include "Plane.h"
#include "Box.h"

#include <vector>

using namespace std;

int main(){

    Sphere* s1 = new Sphere(4, 0, 0, 1);
    Sphere* s2 = new Sphere(3, 1, 1, 0.5);
    Plane* navion = new Plane(0, -1, 1, 3);
    Plane* backwall = new Plane(-1, -.5, -1, 8);
    Box* boiboite = new Box(3.5, -0.825, 0.825, 4.5, -1.375, 1.375);
    Translation* decal = new Translation(boiboite, Vec3(-0.25, 0.5, 0));
    Exclusion* nope = new Exclusion(s1, new Sphere(3.75, .75, .75, 1));

    Object* walls = new Union(navion, backwall);
    Object* spheres = new Union(new Scaling(nope, Vec3(4, 0, 0), 0.75), s2);

    Object* scene = new Union(spheres, new Union(walls, decal));

    Cam cam = Cam(Vec3::Y, Vec3::X, Vec3::Y, 1, 1);

    cout << cam.render_raw(scene, 1080, 1080);

    return 0;
}
