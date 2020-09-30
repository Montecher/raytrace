#include "color.h"
#include <cmath>
#include <algorithm>

inline double mod(double a, double b) {
    while(a<0) a += b;
    while(a>=b) a -= b;
    return a;
}

rgb_color hsv_to_rgb(hsv_color& hsv) {
    double c = hsv.v * hsv.s;
    double x = c * (1 - std::abs(mod((hsv.h/60), 2) - 1));
    double m = hsv.v - c;

    double r = 0, g = 0, b = 0;
    if(hsv.h<60) {
        r = c;
        g = x;
    } else if(hsv.h<120) {
        r = x;
        g = c;
    } else if(hsv.h<180) {
        g = c;
        b = x;
    } else if(hsv.h<240) {
        g = x;
        b = c;
    } else if(hsv.h<300) {
        b = c;
        r = x;
    } else {
        b = x;
        r = c;
    }

    return {
        r: (char) ((r+m) * 255),
        g: (char) ((g+m) * 255),
        b: (char) ((b+m) * 255)
    };
}

hsv_color rgb_to_hsv(rgb_color& rgb) {
    double r = rgb.r / 255.;
    double g = rgb.g / 255.;
    double b = rgb.b / 255.;

    double cmax = std::max(r, std::max(g, b));
    double cmin = std::min(r, std::min(g, b));
    double delta = cmax - cmin;

    double h;
    if(delta == 0) {
        h = 0;
    } else if(cmax==r) {
        h = 60 * mod((g-b) / delta, 6);
    } else if(cmax==g) {
        h = 60 * ((b-r) / delta + 2);
    } else {
        h = 60 * ((r-g) / delta + 4);
    }

    double s;
    if(cmax==0) {
        s = 0;
    } else {
        s = delta / cmax;
    }

    return {
        h: h,
        s: s,
        v: cmax
    };
}
