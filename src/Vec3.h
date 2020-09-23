#ifndef RAYTRACE_VEC3_H
#define RAYTRACE_VEC3_H

#include <iostream>
#include <cmath>

class Vec3 {
protected:
    double x, y, z;

public:
    Vec3();
    Vec3(double x, double y, double z);
    // the destructor is implicit

    // Vector x Vector operations
    // = operator is implicit
    Vec3 operator + (const Vec3&) const;
    Vec3 operator - (const Vec3&) const;
    Vec3 operator * (const Vec3&) const;

    Vec3 operator += (const Vec3&);
    Vec3 operator -= (const Vec3&);
    Vec3 operator *= (const Vec3&);

    // Vector x Scalar operations
    Vec3 operator * (double) const;
    Vec3 operator / (double) const;

    Vec3 operator *= (double);
    Vec3 operator /= (double);

    double hypot() const;
    Vec3 normal() const;

    friend std::ostream& operator << (std::ostream&, const Vec3&);
    //friend std::istream& operator >> (std::istream&, Vec3&);
};

#endif //RAYTRACE_VEC3_H
