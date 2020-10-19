#ifndef __MATERIAL_H
#define __MATERIAL_H

#include "Vec3.h"
#include <iostream>

typedef enum ReflectionType {
    DIFFUSE,
    REFLECTIVE,
    REFRACTIVE
} ReflectionType;

class Material {
private:
    Vec3 _emission;
    Vec3 _color;
    ReflectionType _reflection;

public:
    static Material lightsource, white, black, mirror, glass, red, green, blue;

    Material(const Vec3&, const Vec3&, ReflectionType);
    Material(const Vec3&, const Vec3&);
    Material();

    Vec3 emission() const;
    Vec3 color() const;
    ReflectionType reflection() const;

    friend std::ostream& operator << (std::ostream&, const Material&);
};

inline Vec3 Material::emission() const {
    return _emission;
}
inline Vec3 Material::color() const {
    return _color;
}
inline ReflectionType Material::reflection() const {
    return _reflection;
}

#endif
