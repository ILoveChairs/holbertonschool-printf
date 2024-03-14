#include "printf.h"
#include <string.h>

/**
* printf_char - prints a single character.
* @args: va_list containing the character to print.
*/
void printf_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
}

/**
* printf_str - prints a string.
* @args: va_list containing the string to print.
*/
void printf_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_puts("(nil)");
	}
	else
	{
		_puts(str);
	}
}
