#include "main.h"


/**
 * _uintlen -	Returns length of the integer argument.
 *
 * @integer:	Integer to measure
 *
 * Return:	Length of integer.
 */
int _uintlen(unsigned int integer)
{
	unsigned int len;

	if (integer == 0)
		return (1);

	for (len = 0; integer != 0; len++)
	{
		integer /= 10;
	}

	return (len);
}

/**
 * _uto_print -	Instead of writing on a string, it prints each digit.
 *
 * @integer:	Unsigned integer to be printed.
 *
 * Description:	Compared to utoa, you have to go from left to right
 *		which is quite a hassle.
 *
 * @buffer:	Buffer.
 */
void _uto_print(unsigned int integer, buffer_t *buffer)
{
	int int_len;
	unsigned int digit_pos;
	unsigned int first_digit;

	int_len = _uintlen(integer) - 1;
	digit_pos = _pow(10, int_len);

	while (int_len >= 0)
	{
		first_digit = integer / digit_pos;

		_buffer_add(first_digit + 48, buffer);

		integer -= first_digit * digit_pos;

		digit_pos /= 10;
		int_len--;
	}
}


