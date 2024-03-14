
/**
 * int_len -	Returns length of the integer argument.
 *
 * @integer:	Integer to measure
 *
 * Return:	Length of integer.
 */
int int_len(int integer)
{
	int len;

	for (len = 0; integer != 0; len++)
	{
		integer /= 10;
	}

	return (len);
}

/**
 * itoa -	Converts integer to String.
 *		Does not check if String is NULL.
 *
 * @str:	Destination of integer.
 * @integer:	Integer to be converted.
 *
 * Return:	(str).
 */
char *itoa(char *str, int integer)
{
	int i;
	int len;

	len = int_len(integer);

	for (i = len - 1; i >= 0; i--)
	{
		str[i] = (integer % 10) + 48;
		integer /= 10;
	}

	return (str);
}
