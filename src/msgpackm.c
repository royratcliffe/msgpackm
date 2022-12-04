#include <msgpackm.h>

int msgpack_format_int(struct msgpack_formatter *formatter, int value)
{
    if (-32 <= value && value <= 127)
    {
        if (formatter->size < 1) return 0;
        *formatter->data++ = value;
        formatter->size--;
        return 1;
    }
    return 0;
}

void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped)
{
    swapped[0] = swapping[1];
    swapped[1] = swapping[0];
}
