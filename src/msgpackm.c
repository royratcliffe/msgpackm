#include <msgpackm.h>
#include <stdarg.h>

/*!
 * \brief Writes octets to formatter if space available.
 *
 * Expression \c va_arg(args, uint8_t) gives a warning about integer promotion,
 * command-line option \c -Wvarargs on GCC.
 *
 * \param formatter Destination for span of octets.
 * \param size Number of octets to write.
 * \param ... Octets to write.
 *
 * \return Answers the number of octet \e spans completely formatted; zero or
 * one. Returns zero for none written, or one for all written.
 */
inline static int format(struct msgpack_formatter *formatter, size_t size, ...)
{
    if (formatter->size < size) return 0;
    va_list args;
    va_start(args, size);
    while (size--)
    {
        *formatter->data++ = va_arg(args, int);
        formatter->size--;
    }
    va_end(args);
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
        return format(formatter, 1, value);
    }
    if (-128 <= value && value <= 127)
    {
        return format(formatter, 2, 0xcc, value);
    }
    return 0;
}

void msgpack_swap16(const uint8_t *restrict swapping, uint8_t *restrict swapped)
{
    swapped[0] = swapping[1];
    swapped[1] = swapping[0];
}
