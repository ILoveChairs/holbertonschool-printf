#include "main.h"

/**
* printf_char -	Prints a single character from va_list and returns 1.
*
* @args:	va_list containing the character to print.
*
* @buffer:	Buffer.
*/
void printf_char(va_list args, buffer_t *buffer)
{
	_buffer_add(va_arg(args, int), buffer);
}

/**
* printf_str -	Prints a string from va_list and returns the len of output.
*
* @args:	va_list containing the string to print.
*
* @buffer:	Buffer.
*/
void printf_str(va_list args, buffer_t *buffer)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	_buffer_add_str(str, buffer);
}

/**
 * printf_reverse -	Prints the string from va_list reversed.
 *
 * @args:		va_list containing string.
 *
 * @buffer:		Buffer.
 */
void printf_reverse(va_list args, buffer_t *buffer)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	_reverse_string(str);

	_buffer_add_str(str, buffer);
}

/**
 * printf_rot13 -	Prints the string from va_list with a rotation of 13.
 *
 * @args:		va_list containing string.
 *
 * @buffer:		Buffer.
 */
void printf_rot13(va_list args, buffer_t *buffer)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	_rot13(str);

	_buffer_add_str(str, buffer);
}



