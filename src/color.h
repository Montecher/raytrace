#ifndef __COLOR_H
#define __COLOR_H

/**
 * \struct rgb_color
 * \brief rgb color definition.
 */
typedef struct {
    unsigned char r;  ///< red component.
    unsigned char g;  ///< green component.
    unsigned char b;  ///< blue component.
} rgb_color;

/**
 * \struct hsv_color
 * \brief hsv color definition.
 */
typedef struct {
    double h;  ///< hue component.
    double s;  ///< saturation component.
    double v;  ///< value component.
} hsv_color;

/**
 * \brief transform an rgb color into hsv.
 * @param rgb rbg_color to be transformed.
 * @return resulting hsv_color.
 */
hsv_color rgb_to_hsv(rgb_color& rgb);

/**
 * \brief transform an hsv color into rgb.
 * @param hsv hsv_color to be transformed.
 * @return resulting rbg_color.
 */
rgb_color hsv_to_rgb(hsv_color& hsv);

const rgb_color rgb_black = {0, 0, 0};  ///< default black rgb_color.
const hsv_color hsv_black = {0., 0., 0.};  ///< default black hsv_color.

#endif
