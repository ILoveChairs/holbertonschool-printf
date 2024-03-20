#include "main.h"

/**
* printf_char -	Prints a single character from va_list and returns 1.
*
* @args:	va_list containing the character to print.
*
* Return:	1 if print was successful, -1 if not.
*/
int printf_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
* printf_str -	Prints a string from va_list and returns the len of output.
*
* @args:	va_list containing the string to print.
*
* Return:	Length of printed string.
*/
int printf_str(va_list args)
{
	int len;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	len = _puts(str);

	return (len);
}

/**
 * printf_reverse -	Prints the string from va_list reversed.
 *
 * @args:		va_list containing string.
 *
 * Return:		Length of printed string.
 */
int printf_reverse(va_list args)
{
	int len;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	_reverse_string(str);

	len = _puts(str);

	return (len);
}

/**
 * printf_rot13 -	Prints the string from va_list with a rotation of 13.
 *
 * @args:		va_list containing string.
 *
 * Return:		Length of printed string.
 */
int printf_rot13(va_list args)
{
	int len;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	_rot13(str);

	len = _puts(str);

	return (len);
}



