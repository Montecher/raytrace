#ifndef __MATERIAL_H
#define __MATERIAL_H
#include "Light.h"

/**
 * \enum ReflectionType
 * \brief different ways light interact when bouncing
 */
typedef enum ReflectionType {
    DIFFUSE,  ///< equiprobability of bounce in every direction from impact point.
    REFLECTIVE,  ///< reflection angle = incidence angle.
    REFRACTIVE,  ///< \todo implement the refraction.
    STOP  ///< stops the rays here.
} ReflectionType;

/**
 * \class Material
 * \brief material manager for the Object.
 */
class Material {
private:
    Diffusion _color;  ///< color used for the recoloration of the bouncing light.
    Light _emission;  ///< color of emitted light, if emitting any.
    ReflectionType _reflection;  ///< way that light interact if bouncing.

public:
    static Material lightsource;  ///< white light source with no UV.
    static Material white;  ///< white diffusing material.
    static Material black;  ///< black stopping material.
    static Material mirror;  ///< perfectly reflective material.
    static Material red;  ///< red diffusing material.
    static Material green;  ///< green diffusing material.
    static Material blue;  ///< blue diffusing material.

    static Material uvlight;  ///< dark purple diffusing material emiting UV light
    static Material fluorescent;  ///< grey diffusing material, yellowish green fluorescence under UV light.

    /**
     * \brief Material constructor with Diffusion, Light, ReflectionType specified.
     * @param color color used for the recoloration of the bouncing light.
     * @param emission color of emitted light, if emitting any.
     * @param reflection way that light interact if bouncing.
     */
    Material(const Diffusion& color, const Light& emission, ReflectionType reflection);

    /**
     * \brief Material constructor with Light, Light, ReflectionType specified.
     * @param color color used for the recoloration of the bouncing light.
     * @param emission color of emitted light, if emitting any.
     * @param reflection way that light interact if bouncing.
     */
    Material(const Light& color, const Light& emission, ReflectionType reflection);

    /**
     * \brief Material constructor with Diffusion, ReflectionType specified.
     * @param color color used for the recoloration of the bouncing light.
     * @param emission color of emitted light, if emitting any.
     */
    Material(const Diffusion& color, const Light& emission);

    /**
     * \brief Material constructor with Light, ReflectionType specified.
     * @param color color used for the recoloration of the bouncing light.
     * @param emission color of emitted light, if emitting any.
     */
    Material(const Light& color, const Light& emission);

    /**
     * \brief Material constructor with Diffusion specified.
     * @param color color used for the recoloration of the bouncing light.
     */
    Material(const Diffusion& color);

    /**
     * \brief Material constructor with Light specified.
     * @param color color used for the recoloration of the bouncing light.
     */
    Material(const Light& color);

    /**
     * \brief default Material constructor.
     */
    Material();

    /**
     * \brief Material color getter.
     * @return this._color
     */
    Diffusion color() const;

    /**
     * \brief Material emission getter.
     * @return this._emission
     */
    Light emission() const;

    /**
     * \brief Material reflection getter.
     * @return this._reflection
     */
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
