#include "main.h"
#include <stdio.h>


/**
 * _get_first_digit -	Gets first digit position of the desired format.
 *
 * @integer:		Number Which we want to convert.
 *
 * @format:		Desired format to output.
 *
 * Return:		(Digit).
 */
int _get_first_digit(unsigned int integer, int format)
{
	int digit;

	digit = 1;

	while (integer / _pow(format, digit) != 0)
	{
		digit++;
	}

	return (digit);
}

/**
 * _get_reminders -	
 *
 * @integer:		
 *
 * @format:		
 *
 * @digit:		
 *
 * Return:		
 */
int _get_reminders(unsigned int integer, int format, int digit)
{
	unsigned int tmp;

	digit--;

	if (digit == 0)
		return (0);

	tmp = (integer - _get_reminders(integer, format, digit)) % _pow(format, digit);

	return (tmp + _get_reminders(integer, format, digit));
}

/**
 * _max_recursive -	Converts and prints each digit of integer
 *			to the specified format, for example hexadecimal.
 *
 * @integer:		Number to be converted and printed.
 *
 * @numbers:		List of chars to be used for formatting. The index is
 *			used for conversion.
 *
 * @format:		16 for hexadecimal, 8 for octal, 2 for binary.
 *			Basically $numbers len.
 *
 * @digit:		First digit position of the formatted form of $integer.
 *			Decreases until 0.
 *
 * Return:		Length of output.
 */
int _max_recursive(unsigned int integer, char *numbers, int format, int digit)
{
	int len;
	int to_print;
	unsigned int t_integer;

	if (digit != 0)
	{
		t_integer = integer - _get_reminders(integer, format, digit);
		to_print = t_integer % _pow(format, digit);
		to_print /= _pow(format, digit - 1);
		len = _putchar(numbers[to_print]);

		len += _max_recursive(integer, numbers, format, digit - 1);
		return (len);
	}

	return (0);
}

/**
 * _max_converter -	Prints integer as hexadecimal.
 *
 * @integer:		Unsigned int to convert and print.
 *
 * @numbers:		List of characters to use. For example
 *			an hexadecimal list would be
 *			"0123456789abcdef"
 *
 * Return:		Length of output.
 */
int _max_converter(unsigned int integer, char *numbers)
{
	int format;
	int digit;
	int len;

	if (!numbers)
		return (0);

	if (integer == 0)
		return (_putchar(numbers[0]));

	format = _strlen(numbers);
	digit = _get_first_digit(integer, format);

	len = _max_recursive(integer, numbers, format, digit);

	return (len);
}


