#include "Image.h"
#include "endianswap.h"
#include <sstream>
#include <cstdint>
#include <algorithm>

Image::Image() {
    w = 0;
    h = 0;
    pixels = (rgb_color*) 0;
}

Image::Image(int w, int h) {
    this->w = w;
    this->h = h;
    this->pixels = new rgb_color[w*h];
}

Image::Image(const Image& cp) {
    w = cp.w;
    h = cp.h;
    pixels = new rgb_color[w*h];
    std::copy(&cp.pixels[0], &cp.pixels[w*h], &pixels[0]);
}

Image::~Image() {
    if(pixels) delete this->pixels;
}

std::string Image::to_string() {
    std::stringstream render;
    for(int y=0; y<this->h; y++) {
        for(int x=0; x<this->w; x++) {
            rgb_color pixel = this->pixel(x, y);
            render << "\x1b[48;2;" << (int) pixel.r << ";" << (int) pixel.g << ";" << (int) pixel.b << "m ";
        }
    }
    render << "\x1b[0m";
    return render.str();
}

std::string Image::to_raw() {
    std::string render = std::string(this->w * this->h * 3, '\0');
    for(int y=0; y<this->h; y++) {
        for(int x=0; x<this->w; x++) {
            rgb_color pixel = this->pixel(x, y);
            render[3 * (x + y*this->w)] = pixel.r;
            render[3 * (x + y*this->w) + 1] = pixel.g;
            render[3 * (x + y*this->w) + 2] = pixel.b;
        }
    }
    return render;
}

#ifdef _MVC_VER
#pragma pack(push, 1)
#endif
typedef struct {
    uint8_t magic[2]; // {'B', 'M'}
    uint32_t file_size; // always 26 + h*row_size
    uint16_t reserved0; // 0
    uint16_t reserved1; // 0
    uint32_t data_offset; // always 26
    uint32_t dib_header_size; // always 12
    uint16_t width;
    uint16_t height;
    uint16_t cplanes; // always 1
    uint16_t bpp; // always 24
}
#ifdef __GNUC__
__attribute__((packed))
#endif
bmp_header;
#ifdef _MVC_VER
#pragma pack(pop)
#endif

typedef union {
    bmp_header h;
    char bytes[26];
} bmp_header_bytes;

std::string Image::to_bmp() {
    std::stringstream render;
    uint32_t row_size = (24*this->w + 31)/32 * 4;

    bmp_header header;
    header.magic[0] = 'B';
    header.magic[1] = 'M';
    header.file_size = to_little_endian((uint32_t) 26 + this->h*row_size);
    header.reserved0 = 0;
    header.reserved1 = 0;
    header.data_offset = to_little_endian((uint32_t) 26);
    header.dib_header_size = to_little_endian((uint32_t) 12);
    header.width = to_little_endian((uint16_t) this->w);
    header.height = to_little_endian((uint16_t) this->h);
    header.cplanes = to_little_endian((uint16_t) 1);
    header.bpp = to_little_endian((uint16_t) 24);
    bmp_header_bytes header_bytes = {h: header};
    render << std::string(header_bytes.bytes, 26);

    std::string pixels = std::string(this->h*row_size, '\0');
    for(int y=0; y<this->h; y++) {
        for(int x=0; x<this->w; x++) {
            rgb_color pixel = this->pixel(x, y);
            int offset = 3*x + (this->h-y-1) * row_size;
            pixels[offset] = pixel.b;
            pixels[offset + 1] = pixel.g;
            pixels[offset + 2] = pixel.r;
        }
    }
    render << pixels;

    return render.str();
}
