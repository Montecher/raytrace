#ifndef RAYTRACE_VEC3_H
#define RAYTRACE_VEC3_H

#include <iostream>
#include <cmath>


/**
 * \class Vec3
 * \brief Representation of vectors and points in 3D
 *
 * This is the class responsible for the management of the points and vector coordinates for Object and Ray.
 */
class Vec3 {
protected:
    double x;  ///< x coordinate of the vector.
    double y;  ///< y coordinate of the vector.
    double z;  ///< z coordinate of the vector.

public:
    // static x, y, z and o vectors
    static Vec3 X;  ///< (1, 0, 0) vector.
    static Vec3 Y;  ///< (0, 1, 0) vector.
    static Vec3 Z;  ///< (0, 0, 1) vector.
    static Vec3 O;  ///< (0, 0, 0) vector.

    // constructors
    /**
     * \brief default Vec3 constructor.
     *
     * creates a (0, 0, 0) vector.
     */
    Vec3();

    /**
     * \brief Vec3 construct with coordinates
     *
     * construct the (x, y, z) vector.
     *
     * @param x x coordinate of the vector.
     * @param y y coordinate of the vector.
     * @param z z coordinate of the vector.
     */
    Vec3(double x, double y, double z);
    // the destructor is implicit

    // getters for the coordinates
    /**
     * \brief getter for this.x.
     * @return the value of the x coordinate.
     */
    double get_x() const;

    /**
     * \brief getter for this.y.
     * @return the value of the y coordinate.
     */
    double get_y() const;

    /**
     * \brief getter for this.z.
     * @return the value of the z coordinate.
     */
    double get_z() const;

    // Vector x Vector operations
    // = operator is implicit
    /**
     * \brief addition of 2 Vec3.
     *
     * Add their coordinates together.
     *
     * @param vec3 Vec3 to be added.
     * @return Vec3 resulting of the addition.
     */
    Vec3 operator + (const Vec3& vec3) const;

    /**
     * \brief subtraction of 2 Vec3.
     *
     * Subtract their coordinates together.
     *
     * @param vec3 Vec3 to be subtracted.
     * @return Vec3 resulting of the subtraction.
     */
    Vec3 operator - (const Vec3& vec3) const;

    /**
     * \brief cross product of 2 Vec3.
     *
     * Do the cross product of the 2 Vec3.
     *
     * @param vec3 Vec3 to be used in the cross product.
     * @return Vec3 resulting of the cross product.
     */
    Vec3 operator ^ (const Vec3& vec3) const;

    /**
     * \brief dot product of 2 Vec3.
     *
     * Do the dot product of the 2 Vec3.
     *
     * @param vec3 Vec3 to be used in the dot product.
     * @return double resulting of the dot product.
     */
    double operator * (const Vec3& vec3) const;

    /**
     * \brief one to one product of 2 Vec3.
     *
     * Do the product for with each corresponding coordinates.
     * @param vec3 Vec3 to be used in the operation.
     * @return Vec3 resulting of the one to one product.
     */
    Vec3 mult(const Vec3& vec3) const;

    /**
     * \brief addition of another Vec3 to this.
     *
     * Add their coordinates together.
     *
     * @param vec3 Vec3 to be added.
     */
    Vec3 operator += (const Vec3& vec3);

    /**
     * \brief subtraction of another Vec3 to this.
     *
     * Subtract their coordinates together.
     *
     * @param vec3 Vec3 to be subtracted.
     */
    Vec3 operator -= (const Vec3& vec3);

    /**
     * \brief cross product of another Vec3 to this.
     *
     * Do the cross product of the 2 Vec3.
     *
     * @param vec3 Vec3 to be used in the cross product.
     */
    Vec3 operator ^= (const Vec3& vec3);

    // Vector x Scalar operations
    /**
     * \brief product of the Vec3 with a scalar.
     *
     * Multiplies the coordinates of the Vec3 by the scalar amount.
     *
     * @param scalar Amount of the multiplication.
     * @return Vec3 updated with scalar multiplication
     */
    Vec3 operator * (double scalar) const;

    /**
     * \brief division of the Vec3 by a scalar.
     *
     * Divides the coordinates of the Vec3 by the scalar amount.
     *
     * @param scalar Amount of the division.
     * @return Vec3 updated with scalar division
     */
    Vec3 operator / (double scalar) const;


    /**
     * \brief product of this with a scalar.
     *
     * Multiplies the coordinates of this by the scalar amount.
     *
     * @param scalar Amount of the multiplication.
     */
    Vec3 operator *= (double scalar);

    /**
     * \brief division of this by a scalar.
     *
     * Divides the coordinates of this by the scalar amount.
     *
     * @param scalar Amount of the division.
     */
    Vec3 operator /= (double scalar);

    // invert
    /**
     * \brief coordinate value inversion
     *
     * Unary operator that is responsible of the inversion of all the coordinate values.
     *
     * @return Vec3 with inverted coordinates.
     */
    Vec3 operator - ();

    // misc functions
    /**
     * \brief distance calculation.
     *
     * This function calculates the distance of the point to the origin.
     *
     * @return distance to origin
     */
    double hypot() const;

    /**
     * \brief angle calculation.
     *
     * Calculates the angle between 2 Vec3.
     *
     * @param vec3 Other Vec3 of the angle.
     *
     * @return Angle value in the 2pi format.
     */
    double angle_to(const Vec3& vec3) const;

    /**
     * \brief normalize calculation.
     *
     * Calculates a normalized version of itself.
     *
     * @return A normalized Vec3 repesentation of this.
     */
    Vec3 normal() const;

    /**
     * \brief display of the Vec3
     *
     * This friend function is responsible of the display in an std::ostream of a Vec3.
     *
     * @param output output stream.
     * @param vec3 Vec3 being asked.
     * @return (vec3.x, vec3.y, vec3.z)
     */
    friend std::ostream& operator << (std::ostream& output, const Vec3& vec3);
    //friend std::istream& operator >> (std::istream&, Vec3&);
};

// getters for the coordinates
inline double Vec3::get_x() const {
    return x;
}

inline double Vec3::get_y() const {
    return y;
}

inline double Vec3::get_z() const {
    return z;
}


// Vector x Vector operations
inline Vec3 Vec3::operator+(const Vec3& vec3) const {
    return {x + vec3.x, y + vec3.y, z + vec3.z};
}

inline Vec3 Vec3::operator-(const Vec3& vec3) const {
    return {x - vec3.x, y - vec3.y, z - vec3.z};
}

inline Vec3 Vec3::operator^(const Vec3& vec3) const {
    return {y*vec3.z - z*vec3.y, z*vec3.x - x*vec3.z, x*vec3.y - y*vec3.x};
}

inline double Vec3::operator*(const Vec3& vec3) const {
    return this->x * vec3.x + this->y * vec3.y + this->z * vec3.z;
}

inline Vec3 Vec3::mult(const Vec3& vec3) const {
    return {x*vec3.x, y*vec3.y, z*vec3.z};
}


// auto assign operators
inline Vec3 Vec3::operator+=(const Vec3& vec3) {
    *this = *this + vec3;
    return *this;
}

inline Vec3 Vec3::operator-=(const Vec3& vec3) {
    *this = *this - vec3;
    return *this;
}

inline Vec3 Vec3::operator^=(const Vec3& vec3) {
    *this = *this ^ vec3;
    return *this;
}



// Vector x Scalar operation
inline Vec3 Vec3::operator*(const double scalar) const {
    return {x*scalar, y*scalar, z*scalar};
}

inline Vec3 Vec3::operator/(const double scalar) const {
    return {x/scalar, y/scalar, z/scalar};
}

inline Vec3 Vec3::operator*=(const double scalar) {
    *this = *this * scalar;
    return *this;
}

inline Vec3 Vec3::operator/=(const double scalar) {
    *this = *this / scalar;
    return *this;
}

// invert
inline Vec3 Vec3::operator-() {
    return {-x, -y, -z};
}


// misc functions
inline double Vec3::hypot() const {
    return std::sqrt(x*x + y*y + z*z);
}

inline Vec3 Vec3::normal() const {
    double norm = this->hypot();
    return *this / norm;
}

inline double Vec3::angle_to(const Vec3& vec3) const {
    return std::acos((*this * vec3) / (hypot() * vec3.hypot()));
}

inline std::ostream& operator<<(std::ostream& output, const Vec3& vec3){
    output << "(" << vec3.x << ", " << vec3.y << ", " << vec3.z << ")";
    return output;
}

#endif //RAYTRACE_VEC3_H
