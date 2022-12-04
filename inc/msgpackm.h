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

/*!
 * \brief Formats an integer.
 * \details Encoded integers have five \e full forms: one through five octets
 * plus nine octets when supporting 64-bit forms.
 *
 * values        | type
 * ------------- | ------
 * 00 through 7F | fixed integer (fixint) positive
 * E0 through FF | fixed integer (fixint) negative
 *
 * Note that \c int can be any bit-width ranging from 8 through 64, or even
 * possibly more, depending on architecture.
 */
int msgpack_format_int(struct msgpack_formatter *formatter, int value);

/*!
 * \brief Swaps two octets.
 * \details Performs a bit swap operation with indirection.
 */
void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped);
