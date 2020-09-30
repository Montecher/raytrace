//
// Created by ara0n on 9/17/20.
//

#include <iostream>
#include "Vec3.h"
#include "Sphere.h"
#include "Ray.h"
#include "Cam.h"

#include <vector>

using namespace std;

int main(){

    Sphere s1 = Sphere(4, 0, 0, 1);
    Sphere s2 = Sphere(3, 1, 1, 0.5);
    vector<Object*> scene;
    scene.push_back(&s1);
    scene.push_back(&s2);

    Cam cam = Cam();

    cout << cam.render_string(scene, 100, 100) << endl;

    return 0;
}
