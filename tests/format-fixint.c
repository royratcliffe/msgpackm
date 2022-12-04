#include "msgpackm-test.h"

int format_fixint()
{
    for (int value = -32; value < 128; value++)
    {
        uint8_t data[100];
        struct msgpack_formatter formatter = {data, sizeof(data)};
        ASSERT(msgpack_format_int(&formatter, value) == 1);
        ASSERT(formatter.data == data + 1);
        ASSERT(formatter.size == 99);
    }
    return 0;
}
