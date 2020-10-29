#include "endianswap.h"

static inline bool is_little_endian() {
    int n = 1;
    return *(char*)&n == 1;
}

uint16_t to_little_endian(uint16_t val) {
    if(is_little_endian()) return val;
    return val<<8 | val >> 8;
}

uint32_t to_little_endian(uint32_t val) {
    if(is_little_endian()) return val;
    return val >> 24 | val << 24 | ((val << 8) & 0x00ff0000) | ((val >> 8) & 0x0000ff00);
}
