#include <stdint.h>

/*!
 * \brief Swaps two octets.
 * \details Performs a bit swap operation with indirection.
 */
void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped);
