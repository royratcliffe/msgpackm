/**
 * \file
 * \brief MessagePack for Microcontrollers.
*/
#include <stddef.h>
#include <stdint.h>

struct msgpack_formatter
{
    uint8_t *data;
    size_t size;
};

int msgpack_format_int(struct msgpack_formatter *formatter, int value);

/*!
 * \brief Swaps two octets.
 * \details Performs a bit swap operation with indirection.
 */
void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped);
