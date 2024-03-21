#include "main.h"
#include <stdlib.h>

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
 * printf_Str -		Prints non printable characters.
 *
 * @args:		va_list containing string.
 *
 * @buffer:		Buffer.
 */
void printf_Str(va_list args, buffer_t *buffer)
{
	char *str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			_buffer_add('\\', buffer);
			_buffer_add('x', buffer);
			_bufferize_hex(*str, buffer);
		}
		else
		{
			_buffer_add(*str, buffer);
		}
		str++;
	}
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
	char *passed_str;
	char *copied_str;

	passed_str = va_arg(args, char *);
	if (!passed_str)
		passed_str = "(null)";

	copied_str = malloc(_strlen(passed_str));
	if (!copied_str)
		return;

	_strcpy(copied_str, passed_str);

	_reverse_string(copied_str);

	_buffer_add_str(copied_str, buffer);

	free(copied_str);
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
	char *passed_str;
	char *copied_str;

	passed_str = va_arg(args, char *);
	if (!passed_str)
		passed_str = "(null)";

	copied_str = malloc(_strlen(passed_str));
	if (!copied_str)
		return;

	_strcpy(copied_str, passed_str);

	_rot13(copied_str);

	_buffer_add_str(copied_str, buffer);

	free(copied_str);
}



