#include "scenes.h"

#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "Box.h"
#include "Image.h"

namespace SCENE {
    Object* scene1() {
        Object* s1 = new WithMaterial(new Sphere(0, 0, 0, 1), &Material::red);
        Object* s2 = new WithMaterial(new Sphere(0, 1, 1, .5), &Material::mirror);
        Object* spheres = new Union(s1, s2);

        Object* floor = new WithMaterial(new Plane(0, 0, 1, 2), &Material::white);
        Object* backwall = new WithMaterial(new Plane(-1, 0, 0, 2), &Material::blue);
        Object* sidewalls = new WithMaterial(new Union(new Plane(0, -1, 0, 2.5), new Plane(0, 1, 0, 2.5)), &Material::green);
        Object* walls = new Union(floor, new Union(backwall, sidewalls));

        Object* scene = new Union(spheres, walls);
        Object* light = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
        return new Union(scene, light);
    }

    Object* scene2() {

        Object* s1 = new Sphere();
        Object* scaled = new Scaling(s1, 1.2);
        Object* moved = new Translation(scaled, Vec3(3, 1, 1));
        Object* sphere = new WithMaterial(moved, &Material::blue);
        Object* wall = new WithMaterial(new Plane(0, -1, 0, 2.5), &Material::green);
        Object* backwall = new WithMaterial(new Plane(-1, 0, 0, 3), &Material::white);

        Object* mirror = new WithMaterial(new Plane(0, 0, 1, 2), &Material::mirror);
        Object* light = new WithMaterial(new Sphere(-1, 1, 1.5, .5), &Material::lightsource);

        return new Union(new Union(sphere, new Union(wall, backwall)), new Union(light, mirror));
    }

    Object* scene3() {
        Object* s1 = new WithMaterial(new Sphere(4, 0, 0, 1), &Material::mirror);
        Object* s2 = new WithMaterial(new Sphere(3, 1, 1, 0.5), &Material::green);
        Object* navion = new WithMaterial(new Plane(0, -1, 1, 3), &Material::blue);;
        Object* backwall = new WithMaterial(new Plane(-1, -.5, -1, 8), &Material::red);
        Object* boiboite = new Box(3.5, -0.825, 0.825, 4.5, -1.375, 1.375);
        Object* decal = new Translation(boiboite, Vec3(-0.25, 0.5, 0));
        Object* nope = new Exclusion(s1, new Sphere(3.75, .75, .75, 1));

        Object* walls = new Union(navion, backwall);
        Object* spheres = new Union(new Scaling(nope, 0.75), s2);

        Object* scene = new Union(spheres, new Union(walls, decal));

        Object* light = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
        return new Union(scene, light);
    }
}
