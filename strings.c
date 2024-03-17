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
