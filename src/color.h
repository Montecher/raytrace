#ifndef __COLOR_H
#define __COLOR_H

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_color;

typedef struct {
    double h;
    double s;
    double v;
} hsv_color;

hsv_color rgb_to_hsv(rgb_color& rgb);
rgb_color hsv_to_rgb(hsv_color& hsv);

const rgb_color rgb_black = {0, 0, 0};
const hsv_color hsv_black = {0., 0., 0.};

#endif
