#include "main.h"

/**
 * printf_un_octal -	Prints unsigned int from va_list as octal.
 *
 * @args:		va_list to take unsigned int.
 *
 * @buffer:		Buffer.
 */
void printf_un_octal(va_list args, buffer_t *buffer)
{
	char oct[] = "01234567";

	_max_converter(va_arg(args, unsigned int), oct, buffer);
}

/**
 * printf_un_hex -	Prints unsigned int from va_list as hexadecimal.
 *			Letters are not capitalized.
 *
 * @args:		va_list to take unsigned int.
 *
 * @buffer:		Buffer.
 */
void printf_un_hex(va_list args, buffer_t *buffer)
{
	char hex[] = "0123456789abcdef";

	_max_converter(va_arg(args, unsigned int), hex, buffer);
}

/**
 * printf_un_heX -	Prints unsigned int from va_list as hexadecimal.
 *			Letters are capitalized.
 *
 * @args:		va_list to take unsigned int.
 *
 * @buffer:		Buffer.
 */
void printf_un_heX(va_list args, buffer_t *buffer)
{
	char heX[] = "0123456789ABCDEF";

	_max_converter(va_arg(args, unsigned int), heX, buffer);
}

/**
 * printf_un_binary -	Prints unsigned int from va_list as binary.
 *
 * @args:		va_list to take unsigned int.
 *
 * @buffer:		Buffer.
 */
void printf_un_binary(va_list args, buffer_t *buffer)
{
	char binary[] = "01";

	_max_converter(va_arg(args, unsigned int), binary, buffer);
}



