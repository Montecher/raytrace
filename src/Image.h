#ifndef __IMAGE_H
#define __IMAGE_H

#include "color.h"
#include <string>

/**
 * \class Image
 *
 * \brief image that is being rendered from the scene.
 */
class Image {
private:
    int w;  ///< width of the Image.
    int h;  ///< height of the Image.
    rgb_color* pixels;  ///< pixel array of a w*h length containgn the rgb_color of each pixel.

public:
    /**
     * \brief default Image constructor.
     * Empty Image.
     */
    Image();

    /**
     * \brief creates an uninitialized Image of the specified size
     * @param w width of the Image.
     * @param h height of the Image.
     */
    Image(int w, int h);

    /**
     * \brief copy contructor.
     *
     * Qt whines if you don't have this usually implicit contructor in an explicit manner.
     *
     * @param copy Image to be copied
     */
    Image(const Image& copy);

    /**
     * \brief Image destructor.
     */
    ~Image();

    /**
     * \brief Image width getter.
     * @return width of the Image.
     */
    int width() const;

    /**
     * \brief Image height getter.
     * @return height of the Image.
     */
    int height() const;

    /**
     * \brief Image pixel color getter.
     * @return pixel color of the Image.
     */
    rgb_color pixel(int x, int y) const;

    /**
     * \brief pixel color setter
     * @param x x coordinate of the pixel.
     * @param y y coordinate of the pixel.
     * @param color rgb_color being set.
     */
    void pixel(int x, int y, rgb_color color);

    /**
     * \brief creates a directly usable string of the image.
     * @return string Image.
     */
    std::string to_string();

    /**
     * \brief creates a raw rgb data string of the Image.
     * @return raw rgb data of the Image.
     */
    std::string to_raw();

    /**
     * \brief creates a bmp render of the Image.
     * @return .bmp of the Image.
     */
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

#include <QMetaType>
Q_DECLARE_METATYPE(Image)

#endif
