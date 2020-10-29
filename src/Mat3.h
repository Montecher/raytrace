#ifndef __MAT3_H
#define __MAT3_H
#include "Vec3.h"

class Mat3 {
protected:
    double _a, _b, _c;
    double _d, _e, _f;
    double _g, _h, _i;

public:
    Mat3(double, double, double, double, double, double, double, double, double);
    Mat3();

    static Mat3 I, O;

    static Mat3 cofactor;

    double a() const;
    double b() const;
    double c() const;
    double d() const;
    double e() const;
    double f() const;
    double g() const;
    double h() const;
    double i() const;

    Mat3 operator + (const Mat3&) const;
    Mat3 operator * (const Mat3&) const;
    Mat3 operator - (const Mat3&) const;
    Mat3 mult(const Mat3&) const;
    
    Mat3 operator - () const;
    Mat3 trans() const;

    Mat3 operator * (double) const;
    Mat3 operator / (double) const;

    Vec3 operator * (const Vec3&) const;

    Mat3 invert() const;
    Mat3 minor() const;
    double det() const;
};

inline double Mat3::a() const { return _a; }
inline double Mat3::b() const { return _b; }
inline double Mat3::c() const { return _c; }
inline double Mat3::d() const { return _d; }
inline double Mat3::e() const { return _e; }
inline double Mat3::f() const { return _f; }
inline double Mat3::g() const { return _g; }
inline double Mat3::h() const { return _h; }
inline double Mat3::i() const { return _i; }

inline Mat3 Mat3::operator+(const Mat3& o) const {
    return {
        _a+o._a, _b+o._b, _c+o._c,
        _d+o._d, _e+o._e, _f+o._f,
        _g+o._g, _h+o._h, _i+o._i
    };
}

inline Mat3 Mat3::operator-(const Mat3& o) const {
    return {
        _a-o._a, _b-o._b, _c-o._c,
        _d-o._d, _e-o._e, _f-o._f,
        _g-o._g, _h-o._h, _i-o._i
    };
}

inline Mat3 Mat3::operator*(const Mat3& o) const {
    return {
        _a*o._a + _b*o._d + _c*o._g, _a*o._b + _b*o._e + _c*o._h, _a*o._c + _b*o._f + _c*o._i,
        _d*o._a + _e*o._d + _f*o._g, _d*o._b + _e*o._e + _f*o._h, _d*o._c + _e*o._f + _f*o._i,
        _g*o._a + _h*o._d + _i*o._g, _g*o._b + _h*o._e + _i*o._h, _g*o._c + _h*o._f + _i*o._i
    };
}

inline Mat3 Mat3::mult(const Mat3& o) const {
    return {
        _a*o._a, _b*o._b, _c*o._c,
        _d*o._d, _e*o._e, _f*o._f,
        _g*o._g, _h*o._h, _i*o._i
    };
}

inline Mat3 Mat3::operator-() const {
    return {
        -_a, -_b, -_c,
        -_d, -_e, -_f,
        -_g, -_h, -_i
    };
}

inline Mat3 Mat3::trans() const {
    return {
        _a, _d, _g,
        _b, _e, _h,
        _c, _f, _i
    };
}

inline Mat3 Mat3::operator*(double o) const {
    return {
        _a*o, _b*o, _c*o,
        _d*o, _e*o, _f*o,
        _g*o, _h*o, _i*o
    };
}

inline Mat3 Mat3::operator/(double o) const {
    return {
        _a/o, _b/o, _c/o,
        _d/o, _e/o, _f/o,
        _g/o, _h/o, _i/o
    };
}

inline Vec3 Mat3::operator*(const Vec3& o) const {
    double x = o.get_x();
    double y = o.get_y();
    double z = o.get_z();

    return {
        x*_a + y*_b + z*_c,
        x*_d + y*_e + z*_f,
        x*_g + y*_h + z*_i
    };
}

#endif
