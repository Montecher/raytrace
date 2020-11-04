#ifndef RAYTRACE_RAY_H
#define RAYTRACE_RAY_H

#include <iostream>
#include "Vec3.h"
#include "Object.h"

/**
 * \class Ray
 * \brief manages the light rays for the engine.
 */
class Ray {
protected:
    Vec3 orig;  ///< starting point of the Ray.
    Vec3 dir;  ///< direction of the Ray.

public:
    /**
     * \brief Ray constructor.
     * The dir is normalised in the constructor.
     *
     * @param orig starting point of the Ray.
     * @param dir drection of the Ray.
     */
    Ray(Vec3 orig, Vec3 dir);
    // the destructor is implicit

    /**
     * \brief Gives a point at a distance t for the origin following the direction.
     * @param t distance from origin.
     * @return point at the specified distance.
     */
    Vec3 point(double t) const;

    /**
     * \brief computes the ray intersection with an Object.
     *
     * @param object Object being tested
     * @param t distance to object (give the max distance to is, and returns the real distance).
     * @param impact returns the impact point.
     * @param normal return the normal Vec3 ant the impact point.
     * @return if it touched something.
     */
    bool intersect(Object* object, double* t, Vec3* impact, Vec3* normal) const;

    /**
     * \brief Ray origin getter.
     * @return this.orig.
     */
    Vec3 get_orig() const;

    /**
     * \brief Ray direction getter.
     * @return this.dir.
     */
    Vec3 get_dir() const;

    /**
     * \brief description of a Ray object.
     * @param out ostream operator where the Ray info is sent
     * @param ray Ray object being described.
     * @return ostream loaded with the Ray info.
     */
    friend std::ostream& operator << (std::ostream& output, const Ray& ray);
};

inline Vec3 Ray::point(double t) const {
    return orig + dir * t;
}

inline std::ostream& operator<<(std::ostream& output, const Ray& ray){
    output << "(x, y, z) = " << ray.orig << " + t * " << ray.dir;
    return output;
}

inline Vec3 Ray::get_orig() const {
    return orig;
}
inline Vec3 Ray::get_dir() const {
    return dir;
}

#endif
