#ifndef RAYTRACE_VEC3_H
#define RAYTRACE_VEC3_H

#include <iostream>
#include <cmath>

class Vec3 {
protected:
    double x, y, z;

public:
    // static x, y, z vectors
    static Vec3 X, Y, Z, O;

    // constructors
    Vec3();
    Vec3(double x, double y, double z);
    // the destructor is implicit

    // getters for the coordinates
    double get_x() const;
    double get_y() const;
    double get_z() const;

    // Vector x Vector operations
    // = operator is implicit
    Vec3 operator + (const Vec3&) const;
    Vec3 operator - (const Vec3&) const;
    Vec3 operator ^ (const Vec3&) const;
    double operator * (const Vec3&) const;
    Vec3 mult(const Vec3&) const;

    Vec3 operator += (const Vec3&);
    Vec3 operator -= (const Vec3&);
    Vec3 operator ^= (const Vec3&);

    // Vector x Scalar operations
    Vec3 operator * (double) const;
    Vec3 operator / (double) const;

    Vec3 operator *= (double);
    Vec3 operator /= (double);

    // invert
    Vec3 operator - ();

    // misc functions
    double hypot() const;
    double angle_to(const Vec3&) const;
    Vec3 normal() const;

    friend std::ostream& operator << (std::ostream&, const Vec3&);
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

inline Vec3 Vec3::mult(const Vec3& v) const {
    return Vec3(x*v.x, y*v.y, z*v.z);
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
