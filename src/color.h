#ifndef __COLOR_H
#define __COLOR_H

typedef struct {
    char r;
    char g;
    char b;
} rgb_color;

typedef struct {
    double h;
    double s;
    double v;
} hsv_color;

hsv_color rgb_to_hsv(rgb_color& rgb);
rgb_color hsv_to_rgb(hsv_color& hsv);

#endif
