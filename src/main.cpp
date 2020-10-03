//
// Created by ara0n on 9/17/20.
//

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
    Box* boiboite = new Box(3.5, -0.825, 0.825, 4.5, -1.375, 1.375);
    Translation* decal = new Translation(boiboite, Vec3(0, 1, 0.125));

    vector<Object*> scene;
    scene.push_back(s1);
    scene.push_back(s2);
    scene.push_back(navion);
    scene.push_back(boiboite);
    scene.push_back(decal);

    Cam cam = Cam();

    cout << cam.render_raw(scene, 1080, 1080);

    return 0;
}
