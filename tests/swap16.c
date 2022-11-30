#include <msgpackm.h>
#include <assert.h>

int swap16(int argc, char *argv[])
{
    uint8_t incoming[] = {0x11, 0x22}, outgoing[2];
    msgpack_swap16(incoming, outgoing);
    assert(outgoing[0] == 0x22);
    assert(outgoing[1] == 0x11);
    return 0;
}
