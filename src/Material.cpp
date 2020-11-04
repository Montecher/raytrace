#include "Material.h"

Material Material::lightsource = Material(Light::black,       {.75, .75, .75, 0}, STOP      );
Material Material::white       = Material(Light::white*.75,   Light::black,       DIFFUSE   );
Material Material::mirror      = Material(Light::white*.999,  Light::black,       REFLECTIVE);
Material Material::red         = Material({.75, .25, .25, 0}, Light::black,       DIFFUSE   );
Material Material::green       = Material({.25, .75, .25, 0}, Light::black,       DIFFUSE   );
Material Material::blue        = Material({.25, .25, .75, 0}, Light::black,       DIFFUSE   );

Material Material::uvlight     = Material({.125, 0, .25, 0}, {0, 0, 0, 1}, DIFFUSE);
Material Material::fluorescent = Material({
    .25, .00, .00, .00,
    .00, .25, .00, .00,
    .00, .00, .25, .00,
    .25, .75, .00, .00
});

Material::Material(const Diffusion& color, const Light& emission, ReflectionType reflection) {
    _color = color;
    _emission = emission;
    _reflection = reflection;
}

Material::Material(const Light& color, const Light& emission, ReflectionType reflection) {
    _color = Diffusion(color);
    _emission = emission;
    _reflection = reflection;
}

Material::Material(const Diffusion& color, const Light& emission) {
    _color = color;
    _emission = emission;
    _reflection = DIFFUSE;
}

Material::Material(const Light& color, const Light& emission) {
    _color = Diffusion(color);
    _emission = emission;
    _reflection = DIFFUSE;
}

Material::Material(const Diffusion& color) {
    _color = color;
    _emission = Light::black;
    _reflection = DIFFUSE;
}

Material::Material(const Light& color) {
    _color = Diffusion(color);
    _emission = Light::black;
    _reflection = DIFFUSE;
}

Material::Material() {
    _color = Diffusion(Light::white);
    _emission = Light::black;
    _reflection = DIFFUSE;
}
