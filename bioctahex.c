#include "main.h"

/**
 * printf_un_octal -	Prints unsigned int from va_list as octal.
 *
 * @args:		va_list to take unsigned int.
 *
 * Return:		Number of characters printed.
 */
int printf_un_octal(va_list args)
{
	int len;

	char oct[] = "01234567";

	len = _max_converter(va_arg(args, unsigned int), oct);

	return (len);
}

/**
 * printf_un_hex -	Prints unsigned int from va_list as hexadecimal.
 *			Letters are not capitalized.
 *
 * @args:		va_list to take unsigned int.
 *
 * Return:		Number of characters printed.
 */
int printf_un_hex(va_list args)
{
	int len;

	char hex[] = "0123456789abcdef";

	len = _max_converter(va_arg(args, unsigned int), hex);

	return (len);
}

/**
 * printf_un_heX -	Prints unsigned int from va_list as hexadecimal.
 *			Letters are capitalized.
 *
 * @args:		va_list to take unsigned int.
 *
 * Return:		Number of characters printed.
 */
int printf_un_heX(va_list args)
{
	int len;

	char heX[] = "0123456789ABCDEF";

	len = _max_converter(va_arg(args, unsigned int), heX);

	return (len);
}

/**
 * printf_un_binary -	Prints unsigned int from va_list as binary.
 *
 * @args:		va_list to take unsigned int.
 *
 * Return:		Number of characters printed.
 */
int printf_un_binary(va_list args)
{
	int len;

	char binary[] = "01";

	len = _max_converter(va_arg(args, unsigned int), binary);

	return (len);
}
