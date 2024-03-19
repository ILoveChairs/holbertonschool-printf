#include "main.h"

/**
* printf_int - Prints an integer.
*
* @args: Integer to print.
*
* Return: Number of characters printed.
*/
int printf_int(va_list args)
{
	int n;
	int len;

	n = va_arg(args, int);

	len = 0;

	if (n < 0)
		len += _putchar('-');

	len += _ito_print(n);

	return (len);
}

/**
* printf_unsigned - Prints an unsigned integer.
*
* @args: Unsigned integer to print.
*
* Return: Number of characters printed.
*/
int printf_unsigned(va_list args)
{
	unsigned int n;
	int len;

	n = va_arg(args, unsigned int);

	len = _uto_print(n);

	return (len);
}
