#include <msgpackm.h>
#include "msgpackm-test.h"

int swap16(int argc, char *argv[])
{
    uint8_t incoming[] = {0x11, 0x22}, outgoing[2];
    msgpack_swap16(incoming, outgoing);
    ASSERT(outgoing[0] == 0x22);
    ASSERT(outgoing[1] == 0x11);
    return 0;
}
