#ifndef __LIGHT_H
#define __LIGHT_H
#include "VecN.h"
#include "MatN.h"
#include "color.h"
#include <cmath>

class Light : public Vec<4> {
public:
    Light();
    Light(double r, double g, double b, double u);
    Light(const Vec<4>& rgbu);

    double r() const;
    double g() const;
    double b() const;
    double u() const;

    Light add(const Light& other) const;

    rgb_color rgb() const;

    static Light white;
    static Light black;

    static unsigned char srgb(double v);
};

class Diffusion : public Mat<4> {
public:
    Diffusion();
    Diffusion(double rr, double rg, double rb, double ru, double gr, double gg, double gb, double gu, double br, double bg, double bb, double bu, double ur, double ug, double ub, double uu);
    Diffusion(const Light& diagonal);

    Light apply(const Light& source) const;
};

inline Light::Light() : Vec<4>() {}

inline Light::Light(double r, double g, double b, double u) : Vec<4>() {
    _v[0] = r;
    _v[1] = g;
    _v[2] = b;
    _v[3] = u;
}

inline Light::Light(const Vec<4>& rgbu) : Vec<4>() {
    for(unsigned int i=0; i<4; i++) _v[i] = rgbu.v(i);
}

inline double Light::r() const { return v(0); }
inline double Light::g() const { return v(1); }
inline double Light::b() const { return v(2); }
inline double Light::u() const { return v(3); }

#define clamp(v) (v<0 ? 0 : v>1 ? 1 : v)
inline unsigned char Light::srgb(double v) {
    return (unsigned char) (pow(clamp(v), 1/2.2) * 255. + .5);
}
#undef clamp

inline rgb_color Light::rgb() const {
    return {
        Light::srgb(r()),
        Light::srgb(g()),
        Light::srgb(b())
    };
}

inline Light Light::add(const Light& other) const {
    return Light(*this + other);
}

inline Light Diffusion::apply(const Light& source) const {
    return Light(*this * source);
}

#endif
