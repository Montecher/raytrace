#include <iostream>
#include "Sphere.h"
#include "Cam.h"
#include "Plane.h"
#include "Box.h"

using namespace std;

Object* scene1() {
    Object* s1 = new WithMaterial(new Sphere(0, 0, 0, 1), &Material::red);
    Object* s2 = new WithMaterial(new Sphere(0, 1, 1, .5), &Material::mirror);
    Object* spheres = new Union(s1, s2);

    Object* floor = new WithMaterial(new Plane(0, 0, 1, 2), &Material::white);
    Object* backwall = new WithMaterial(new Plane(-1, 0, 0, 2), &Material::blue);
    Object* sidewalls = new WithMaterial(new Union(new Plane(0, -1, 0, 2.5), new Plane(0, 1, 0, 2.5)), &Material::green);
    Object* walls = new Union(floor, new Union(backwall, sidewalls));

    Object* scene = new Union(spheres, walls);

    return scene;
}

int main(){

    Object* scene = scene1();
    Object* light = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
    scene = new Union(scene, light);

    Cam cam = Cam();
    cam.setPos(Vec3::Z*3. - Vec3::X*5.);
    cam.setPointing(Vec3::O);

    //cerr << cam << endl;

    //Image img = cam.render_shaded(scene, 200, 200);
    Image img = cam.render_realistic(scene, 200, 200, 500);

    cout << img.to_bmp();

    return 0;
}
