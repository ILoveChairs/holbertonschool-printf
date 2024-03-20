#include "main.h"

/**
* printf_char -	Prints a single character from va_list and returns 1.
*
* @args:	va_list containing the character to print.
*
* Return:	1 if print was successful, -1 if not.
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
* Return:	Length of printed string.
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
 * Return:		Length of printed string.
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
 * Return:		Length of printed string.
 */
void printf_rot13(va_list args, buffer_t *buffer)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	_rot13(str);

	_buffer_add_str(str, buffer);
}



