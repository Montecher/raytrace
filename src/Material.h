#ifndef __MATERIAL_H
#define __MATERIAL_H
#include "Light.h"

typedef enum ReflectionType {
    DIFFUSE,
    REFLECTIVE,
    REFRACTIVE,
    STOP
} ReflectionType;

class Material {
private:
    Diffusion _color;
    Light _emission;
    ReflectionType _reflection;

public:
    static Material lightsource, white, black, mirror, red, green, blue;
    static Material uvlight, fluorescent;

    Material(const Diffusion&, const Light&, ReflectionType);
    Material(const Light&, const Light&, ReflectionType);
    Material(const Diffusion&, const Light&);
    Material(const Light&, const Light&);
    Material(const Diffusion&);
    Material(const Light&);
    Material();

    Diffusion color() const;
    Light emission() const;
    ReflectionType reflection() const;
};

inline Diffusion Material::color() const {
    return _color;
}
inline Light Material::emission() const {
    return _emission;
}
inline ReflectionType Material::reflection() const {
    return _reflection;
}

#endif
