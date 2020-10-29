#include "Mat3.h"

Mat3 Mat3::I = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

Mat3 Mat3::O = {
    0, 0, 0,
    0, 0, 0,
    0, 0, 0
};

Mat3 Mat3::cofactor = {
    +1, -1, +1,
    -1, +1, -1,
    +1, -1, +1
};

Mat3::Mat3(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
    _f = f;
    _g = g;
    _h = h;
    _i = i;
}

Mat3::Mat3() {
    _a = 0;
    _b = 0;
    _c = 0;
    _d = 0;
    _e = 0;
    _f = 0;
    _g = 0;
    _h = 0;
    _i = 0;
}

double Mat3::det() const {
    return 
        + _a * (_e*_i - _h*_f)
        - _b * (_d*_i - _f*_g)
        + _c * (_d*_h - _e*_g);
}

Mat3 Mat3::minor() const {
    return {
        _e*_i - _f*_h, _d*_i - _f*_g, _d*_h - _e*_g,
        _b*_i - _c*_h, _a*_i - _c*_g, _a*_h - _b*_g,
        _b*_f - _c*_e, _a*_f - _c*_d, _a*_e - _b*_d
    };
}

Mat3 Mat3::invert() const {
    return minor().mult(Mat3::cofactor).trans() / det();
}
