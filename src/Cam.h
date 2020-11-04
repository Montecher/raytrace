#ifndef RAYTRACE_CAM_H
#define RAYTRACE_CAM_H

#include "Vec3.h"
#include "Object.h"
#include "Ray.h"
#include "Image.h"
#include <vector>
#include <string>

/**
 * \brief camera object
 *
 * This class is responsible of the PoV.
 */
class Cam {
private:
    Vec3 orig;  ///< point where the Cam is.
    Vec3 dir;  ///< pointing direction of Cam.
    Vec3 right;  ///< direction of the right of the Cam.
    Vec3 up;  ///< direction of up for the Cam.
    double width;  ///< width of the FoV.
    double height;  ///< height of the FoV.

    /**
     * \brief computes Ray for the pixels of the Image.
     *
     * @param x x coordinate of the pixel in the Image.
     * @param y y coordinate of the pixel in the Image.
     * @param w width of the Image.
     * @param h height of the Image.
     * @return corresponding Ray.
     */
    Ray ray(int x, int y, int w, int h) const;

    /**
     * \brief get pixel
     *
     * @param scene scene that is processed.
     * @param x x coordinate of the pixel in the Image.
     * @param y y coordinate of the pixel in the Image.
     * @param w width of the Image.
     * @param h height of the Image.
     * @param t distance to object (give the max distance to is, and returns the real distance).
     * @param impact returns the impact Vec3.
     * @param normal return the normal Vec3.
     * @param obj return the material that was hit.
     * @return if it touched something.
     */
    bool get_pixel(Object* scene, int x, int y, int w, int h, double* t, Vec3* impact, Vec3* normal, const Material** obj) const;

public:
    /**
     * \brief Cam default constructor.
     *
     * Places the Cam at (0, 0, 0), facing (1, 0, 0) with (0, 1, 0) as its right and (0, 0, 1) as its up.
     */
    Cam();

    /**
     * \brief Cam constructor.
     *
     * @param orig position of Cam.
     * @param dir facing direction of the Cam.
     * @param right right of the Cam.
     * @param width width of the Fov.
     * @param height height of the FoV.
     */
    Cam(Vec3 orig, Vec3 dir, const Vec3& right, double width, double height);

    /**
     * \brief changes the Cam position.
     * @param pos new position of the Cam.
     */
    void setPos(const Vec3& pos);

    /**
     * changes the pointing direction of the Cam.
     * @param pointing new pointing direction.
     */
    void setPointing(const Vec3& pointing);

    /**
     * \brief creates the shaded render of the Image
     * @param scene scene to be rendered.
     * @param w width of the Image.
     * @param h height of the Image.
     * @return rendered shaded Image.
     */
    Image render_shaded(Object* scene, int w, int h) const;

    /**
     * \brief creates the shaded render of the Image.
     * @param scene scene to be rendered.
     * @param w width of the Image.
     * @param h height of the Image.
     * @param samples number of Ray per pixel.
     * @param depth max number of bounces per Ray.
     * @return rendered realistic Image.
     */
    Image render_realistic(Object* scene, int w, int h, int samples=RPP, int depth=DEPTH) const;

    /**
     * \brief description of a Cam object.
     * @param out ostream operator where the Cam info is sent
     * @param cam Cam object being described.
     * @return ostream loaded with the Cam info.
     */
    friend std::ostream& operator << (std::ostream& out, const Cam& cam);
};

inline Ray Cam::ray(int x, int y, int w, int h) const {
    double dx = (x / (w - 1.) - 0.5) * this->width;
    double dy = (y / (h - 1.) - 0.5) * this->height;
    Vec3 dir = (this->dir + this->right * dx - this->up * dy).normal();
    return Ray(this->orig, dir);
}

inline std::ostream& operator << (std::ostream& out, const Cam& cam) {
    return out << "Cam(orig=" << cam.orig << "; dir=" << cam.dir << "; right=" << cam.right << "; up=" << cam.up << "; width=" << cam.width << "; height=" << cam.height << ")";
}

#endif
