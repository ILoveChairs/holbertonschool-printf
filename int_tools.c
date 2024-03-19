#include "main.h"

/**
 * _pow -	recursively raises a to the power of b and returns the rusult.
 *
 * @a:		Integer base.
 * @b:		Integer exponent.
 *
 * Return:	(a**b).
 */
int _pow(int a, int b)
{
	if (b < 0)
		return (-1);

	if (b == 0)
		return (1);

	return (a * _pow(a, b - 1));
}

/**
 * _intlen -	Returns length of the integer argument.
 *
 * @integer:	Integer to measure
 *
 * Return:	Length of integer.
 */
int _intlen(int integer)
{
	int len;

	if (integer == 0)
		return (1);

	for (len = 0; integer != 0; len++)
	{
		integer /= 10;
	}

	return (len);
}

/**
 * _itoa -	Converts integer to String.
 *		Does not check if String is NULL.
 *
 * @str:	Destination of integer.
 * @integer:	Integer to be converted.
 *
 * Return:	(str).
 */
char *_itoa(char *str, int integer)
{
	int len;

	for (len = _intlen(integer) - 1; len >= 0; len--)
	{
		str[len] = (integer % 10) + 48;
		integer /= 10;
	}

	return (str);
}

/**
 * _ito_print -	Instead of writing on a string, it prints each digit.
 *
 * @integer:	Integer to be printed.
 *
 * Description:	Compared to itoa, you have to go from left to right
 *		which is quite a hassle.
 *
 * Return:	Number of chars printed.
 */
int _ito_print(int integer)
{
	int int_len;
	int len;
	int digit_pos;
	int first_digit;

	if (integer > 0)
	{
		integer *= -1;
	}

	len = 0;
	int_len = _intlen(integer) - 1;
	digit_pos = _pow(10, int_len);

	while (int_len >= 0)
	{
		first_digit = integer / digit_pos;
		
		if (first_digit < 0)
			first_digit *= -1;
		len += _putchar(first_digit + 48);

		integer += first_digit * digit_pos;

		digit_pos /= 10;
		int_len--;
	}

	return (len);
}


