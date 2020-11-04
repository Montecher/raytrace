#include "scenes.h"

#include "Objects.h"
#include "Image.h"

Scene::Scene(Cam* cam, Object* scene) {
    _cam = cam;
    _scene = scene;
}

Scene::~Scene() {
    delete this->_cam;
    delete this->_scene;
}

static std::map<std::string, Scene*> scenes;

static Object* scene1() {
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

static Object* scene2() {

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

static Object* scene3() {
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

static Object* scene4() {
    Object* ceiling = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
    Object* floor = new WithMaterial(new Translation(new Waves, Vec3::Z*-5), &Material::mirror);

    Object* cylinder = new Cylinder(0, 0, 0, 1, .5);
    Object* sphere = new Sphere(1, 1, 0, 1);
    Object* stuff = new WithMaterial(new SmoothUnion(cylinder, sphere, 1), &Material::blue);

    Object* backwall = new WithMaterial(new Plane(-1, 0, 0, 6), &Material::white);
    Object* leftwall = new WithMaterial(new Plane(0, 1, 0, 4), &Material::green);
    Object* rightwall = new WithMaterial(new Plane(0, -1, 0, 4), &Material::red);
    Object* walls = new Union(backwall, leftwall, rightwall);

    return new Union(ceiling, floor, stuff, walls);
}

static Object* scene5() {
    static Material biglight = Material(Light::black, Light::white*2);
    static Material antilight = Material(Light::black, Light(-9, -5, 0, 0));
    static Material antimirror = Material(Light(-1, 1, 1, 1), Light(0, .05, 0, 0), REFLECTIVE);

    Object* floor = new WithMaterial(new Plane(0, 0, 1, 3), &Material::white);
    Object* lightsphere = new WithMaterial(new Sphere(0, 2, 0, 1), &biglight);
    Object* antilightsphere = new WithMaterial(new Sphere(0, -2, 0, 1), &antilight);
    Object* mirror = new WithMaterial(new Plane(-1, 0, 0, 3), &antimirror);
    return new Union(floor, lightsphere, antilightsphere, mirror);
}

static Object* scene6() {
    Object* lightsource = new WithMaterial(new Torus(0, 0, 0, 1, .25), &Material::lightsource);
    Object* midRing = new WithMaterial(new Torus(0, 0, 0, 2, .25), &Material::green);
    Object* outRing = new WithMaterial(new Torus(0, 0, 0, 3, .25), &Material::red);
    Object* mirror = new WithMaterial(new Plane(0, 0, 1, 1), &Material::mirror);
    return new Union(lightsource, midRing, outRing, mirror);
}

static Object* scene7() {
    Object* sphere = new WithMaterial(new Sphere(-1, .25, 0, .5), &Material::blue);
    Object* floor = new WithMaterial(new Plane(0, 0, 1, 2), &Material::red);
    Object* planes = new WithMaterial(new Union(new Plane(0, 1, 0, .1), new Plane(-1, -1, 0, 1)), &Material::mirror);
    Object* light = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
    return new Union(sphere, floor, planes, light);
}

static Object* scene8() {
    static Material yellowlight = Material(Light::white, Light(1, 1, 0, 0));
    static Material redlight = Material(Light::white, Light(1, 0, 0, 0));

    Object* centersphere = new WithMaterial(new Sphere(0, 0, 0, .5), &yellowlight);
    Object* outertorus = new WithMaterial(new Torus(0, 0, 0, 1, .25), &redlight);
    Object* floor = new WithMaterial(new Plane(0, 0, 1, 1), &Material::white);
    return new Union(centersphere, outertorus, floor);
}

static Object* scene9() {
    Mat3 transform = LinearTransform::rotate(.2, .2, .2);
    Object* matchstick = new Union(
        new WithMaterial(new Sphere(0, 0, 1, .5), &Material::red),
        new WithMaterial(new Cylinder(0, 0, 0, .25, 1), &Material::blue),
        new WithMaterial(new Sphere(0, .5, 0, .5), &Material::green)
    );
    Object* transformed = new AffineTransform(matchstick, transform, -Vec3::Z);

    Object* light = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
    return new Union(transformed, light);
}

static Object* sceneA() {
    Object* uvsource = new WithMaterial(new Sphere(0, 2, 0, 1), &Material::uvlight);
    Object* lightsource = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);
    Object* floor = new WithMaterial(new Plane(0, 0, 1, 3), &Material::white);
    Object* sphere = new WithMaterial(new Sphere(0, 0, 0, .5), &Material::fluorescent);
    return new Union(uvsource, lightsource, sphere, floor);
}

static Object* sceneB() {
    // constructing crust
    Object* bouboule = new Sphere();
    Object* carving = new Sphere({0, 0, 0}, 0.8);
    Object* crust = new Exclusion(bouboule, carving);

    // constructing poles
    Object* x_pole = new Cylinder({0, 0, 0}, 0.5, 1);
    Object* y_pole = new LinearTransform(x_pole->clone(), LinearTransform::swapYZ);
    Object* z_pole = new LinearTransform(x_pole->clone(), LinearTransform::swapXZ);
    Object* poles = new Union(x_pole, y_pole, z_pole);

    // carving the crust
    Object* holed_crust = new WithMaterial(new LinearTransform(new Exclusion(crust, poles), LinearTransform::rotate(.5, .5, .5) * 2), &Material::blue);
    Object* holed_crust2 = new WithMaterial(new LinearTransform(new Exclusion(crust->clone(), poles->clone()), LinearTransform::rotate(.5, .5, .5) * 1.5), &Material::white);
    Object* holed_crust3 = new WithMaterial(new LinearTransform(new Exclusion(crust->clone(), poles->clone()), LinearTransform::rotate(.5, .5, .5) * 1), &Material::red);

    Object* light = new WithMaterial(new Plane(0, 0, -1, 8), &Material::lightsource);

    return new Union(holed_crust, holed_crust2, holed_crust3, light);
}

static Cam normalCam;

std::map<std::string, Scene*>* Scene::getScenes() {
    if(scenes.empty()) {
        normalCam.setPos(Vec3::Z*3. - Vec3::X*5.);
        normalCam.setPointing(Vec3::O);

        scenes["scene 1"] = new Scene(&normalCam, scene1());
        scenes["scene 2"] = new Scene(&normalCam, scene2());
        scenes["scene 3"] = new Scene(&normalCam, scene3());
        scenes["scene 4"] = new Scene(&normalCam, scene4());
        scenes["scene 5"] = new Scene(&normalCam, scene5());
        scenes["scene 6"] = new Scene(&normalCam, scene6());
        scenes["scene 7"] = new Scene(&normalCam, scene7());
        scenes["scene 8"] = new Scene(&normalCam, scene8());
        scenes["scene 9"] = new Scene(&normalCam, scene9());
        scenes["scene A"] = new Scene(&normalCam, sceneA());
        scenes["scene B"] = new Scene(&normalCam, sceneB());
    }
    return &scenes;
}

Scene* Scene::getScene(std::string name) {
    return Scene::getScenes()->at(name);
}
