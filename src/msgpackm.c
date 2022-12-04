#include <msgpackm.h>

static int msgpack_format(struct msgpack_formatter *formatter, uint8_t xx)
{
    if (formatter->size < 1) return 0;
    *formatter->data++ = xx;
    formatter->size--;
    return 1;
}

int msgpack_format_int(struct msgpack_formatter *formatter, int value)
{
    if (-32 <= value && value <= 127)
    {
        /*
         * The following expression demotes the incoming integer from signed to
         * unsigned throwing away all more-significant bits beyond the eight.
         */
        return msgpack_format(formatter, value);
    }
    return 0;
}

void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped)
{
    swapped[0] = swapping[1];
    swapped[1] = swapping[0];
}
