#ifndef __LIGHT_H
#define __LIGHT_H
#include "VecN.h"
#include "MatN.h"
#include "color.h"
#include <cmath>

/**
 * \class Light
 * \brief object responsible for the rgb + UV light in the engine.
 */
class Light : public Vec<4> {
public:
    /**
     * \brief Light default constructor
     * No light is emitted.
     */
    Light();

    /**
     * \brief Light constructor specifying all 4 light colors.
     *
     * @param r red light.
     * @param g green light.
     * @param b blue light.
     * @param u UV light.
     */
    Light(double r, double g, double b, double u);

    /**
     * \brief Light constructor to recast a Vac<4> into light.
     * @param rgbu Vec<4> being recasted.
     */
    Light(const Vec<4>& rgbu);

    /**
     * \brief red light getter.
     * @return red light value.
     */
    double r() const;

    /**
     * \brief green light getter.
     * @return green light value.
     */
    double g() const;

    /**
     * \brief blue light getter.
     * @return blue light value.
     */
    double b() const;

    /**
     * \brief UV light getter.
     * @return UV light value.
     */
    double u() const;

    /**
     * \brief add 2 Light values together.
     * @param other second Light used.
     * @return resulting Light.
     */
    Light add(const Light& other) const;

    /**
     * \brief transform the Light into the rgb_color format.
     * @return rgb_format of Light.
     */
    rgb_color rgb() const;

    static Light white;  ///< full white bright light.
    static Light black;  ///< pitch black darkness.

    /**
     * \brief transform linear rgb color to srgb color
     *
     * transform a value for the linear rgb color space to the srgb color space with a value between 0 and 255
     *
     * @param v linear rgb color space value.
     * @return srgb color space value.
     */
    static unsigned char srgb(double v);
};

/**
 * \class Diffusion
 * \brief Mat<4> defining bouncing color.
 */
class Diffusion : public Mat<4> {
public:
    /**
     * \brief default Diffusion constructor.
     *
     * Will always render black.
     */
    Diffusion();

    /**
     * \brief Diffusion constructor with every color coefficient possible.
     *
     * @param rr red reflection for incoming red.
     * @param rg red reflection for incoming green.
     * @param rb red reflection for incoming blue.
     * @param ru red reflection for incoming UV.
     * @param gr green reflection for incoming red.
     * @param gg green reflection for incoming green.
     * @param gb green reflection for incoming blue.
     * @param gu green reflection for incoming UV.
     * @param br blue reflection for incoming red.
     * @param bg blue reflection for incoming green.
     * @param bb blue reflection for incoming blue.
     * @param bu blue reflection for incoming UV.
     * @param ur UV reflection for incoming red.
     * @param ug UV reflection for incoming green.
     * @param ub UV reflection for incoming blue.
     * @param uu UV reflection for incoming UV.
     */
    Diffusion(double rr, double rg, double rb, double ru, double gr, double gg, double gb, double gu, double br, double bg, double bb, double bu, double ur, double ug, double ub, double uu);

    /**
     * \brief Diffusion constructor specifing returned Light if white Light was hitting.
     * @param diagonal returning Light.
     */
    Diffusion(const Light& diagonal);

    /**
     * \brief applies Diffusion to an incoming Light.
     * @param source incoming Light.
     * @return returning Light.
     */
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
