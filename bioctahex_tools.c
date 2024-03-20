#include "main.h"
#include <stdlib.h>
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

	while (integer != 0)
	{
		digit++;
		integer /= format;
	}

	return (digit);
}

/**
 * _max_unrecursive -	Converts and puts in string each digit of integer
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
 * @str:		String to add each digit.
 */
void _max_unrecursive(unsigned int integer, char *numbers, int format,
		char *str)
{
	unsigned int to_print;
	int i;

	i = 0;
	while (integer != 0)
	{
		to_print = integer % format;

		str[i++] = numbers[to_print];

		integer /= format;
	}
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
 * @buffer:		Buffer.
 */
void _max_converter(unsigned int integer, char *numbers, buffer_t *buffer)
{
	int format;
	int digit;
	char *str;

	if (!numbers)
		return;

	if (integer == 0)
	{
		_buffer_add(numbers[0], buffer);
		return;
	}

	format = _strlen(numbers);
	digit = _get_first_digit(integer, format);

	str = malloc(digit + 1);
	if (!str)
		return;

	str[digit] = 0;

	_max_unrecursive(integer, numbers, format, str);

	_reverse_string(str);

	_buffer_add_str(str, buffer);

	free(str);
}


