#include "main.h"
#include <string.h>

/**
* printf_char - Prints a single character.
*
* @args: va_list containing the character to print.
*
* Return: Always 1.
*/
int printf_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}

/**
* printf_str - Prints a string.
*
* @args: va_list containing the string to print.
*
* Return: Length of printed string.
*/
int printf_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(nil)";
	}

	return (_puts(str));
}
