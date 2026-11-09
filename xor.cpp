
#include <emscripten.h>
#include <cstdint>

static const uint8_t secret[32] = {
    '0','1','2','3','4','5','6','7',
    '8','9','a','b','c','d','e','f',
    '0','1','2','3','4','5','6','7',
    '8','9','a','b','c','d','e','f'
};

extern "C" {

EMSCRIPTEN_KEEPALIVE
void xor_data(uint8_t* data, uint32_t len) {
    for (uint32_t i = 0; i < len; i++) {
        data[i] ^= secret[i % 32];
    }
}

}
