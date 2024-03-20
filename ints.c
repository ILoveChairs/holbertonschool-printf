#include "main.h"

/**
* printf_int -	Prints an integer.
*
* @args:	Integer to print.
*
* @buffer:	Buffer.
*/
void printf_int(va_list args, buffer_t *buffer)
{
	int n;

	n = va_arg(args, int);

	if (n < 0)
		_buffer_add('-', buffer);

	_ito_print(n, buffer);
}

/**
* printf_unsigned -	Prints an unsigned integer.
*
* @args:		Unsigned integer to print.
*
* @buffer:		Buffer.
*/
void printf_unsigned(va_list args, buffer_t *buffer)
{
	unsigned int n;

	n = va_arg(args, unsigned int);

	_uto_print(n, buffer);
}
