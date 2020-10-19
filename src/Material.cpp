#include "Material.h"

Material Material::lightsource = Material(Vec3(.75,  .75,  .75),  Vec3(.75, .75, .75), DIFFUSE   );
Material Material::white       = Material(Vec3(.75,  .75,  .75),  Vec3::O,             DIFFUSE   );
Material Material::glass       = Material(Vec3(.999, .999, .999), Vec3::O,             REFRACTIVE);
Material Material::mirror      = Material(Vec3(.999, .999, .999), Vec3::O,             REFLECTIVE);
Material Material::red         = Material(Vec3(.75,  .25,  .25),  Vec3::O,             DIFFUSE   );
Material Material::green       = Material(Vec3(.25,  .75,  .25),  Vec3::O,             DIFFUSE   );
Material Material::blue        = Material(Vec3(.25,  .25,  .75),  Vec3::O,             DIFFUSE   );

Material::Material(const Vec3& color, const Vec3& emission, ReflectionType reflection) {
    _color = color;
    _emission = emission;
    _reflection = reflection;
}

Material::Material(const Vec3& color, const Vec3& emission) {
    _color = color;
    _emission = emission;
    _reflection = DIFFUSE;
}

Material::Material() {
    _color = Vec3(1, 1, 1);
    _emission = Vec3::O;
    _reflection = DIFFUSE;
}

std::ostream& operator<<(std::ostream& out, const Material& m) {
    return out << "Material(color=" << m._color << ", emission=" << m._emission << ", reflection=" << m._reflection <<")";
}
