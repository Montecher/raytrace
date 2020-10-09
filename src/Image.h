#ifndef __IMAGE_H
#define __IMAGE_H

#include "color.h"
#include <string>

class Image {
private:
    int w;
    int h;
    rgb_color* pixels;

public:
    Image(int w, int h);
    ~Image();

    int width() const;
    int height() const;
    rgb_color pixel(int x, int y) const;
    void pixel(int x, int y, rgb_color color);

    std::string to_string();
    std::string to_raw();
    std::string to_bmp();
};

inline int Image::width() const {
    return this->w;
}

inline int Image::height() const {
    return this->h;
}

inline rgb_color Image::pixel(int x, int y) const {
    return this->pixels[x + this->w*y];
}

inline void Image::pixel(int x, int y, rgb_color color) {
    this->pixels[x + this->w*y] = color;
}

#endif
