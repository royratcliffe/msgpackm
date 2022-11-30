#include <msgpackm.h>

void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped)
{
    swapped[0] = swapping[1];
    swapped[1] = swapping[0];
}
