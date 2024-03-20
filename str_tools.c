#include <unistd.h>
#include <stdlib.h>

/**
 * _putchar -	Prints a char.
 *
 * @c:		Char to print.
 *
 * Return:	1 if printed, -1 if failed.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen -	Returns length of passed string.
 *
 * @str:	String to get the length of.
 *
 * Return:	Length of str.
 */
int _strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}

	return (len);
}

/**
 * _puts -	Prints string as is.
 *		(without ending in end of line).
 *
 * @str:	Str to print, doesn't check if null.
 *
 * Return:	Length of string printed.
 */
int _puts(char *str)
{
	int i;
	int len;
	char *buffer;

	len = 0;
	buffer = malloc(1024);
	while (*str)
	{
		for (i = 0; *str && i < 1024; i++)
			buffer[i] = *(str++);
		len += write(1, buffer, i);
	}

	free(buffer);
	return (len);
}

/**
 * _reverse_string -	Reverses given string.
 *
 * @str:		String to reverse.
 *
 * Return:		(str)
 */
char *_reverse_string(char *str)
{
	int i;
	char tmp;
	int len;

	len = _strlen(str);
	len--;

	for (i = 0; i < len / 2; i++)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
	}

	return (str);
}

/**
 * _rot13 -	Prints a string to stdout encrypted int rot13.
 *
 * @str:	String to print.
 *
 * Return:	(str)
 */
char *_rot13(char *str)
{
	int i;
	char c;

	for (i = 0; str[i]; i++)
	{
		c = str[i];
		if ((c >= 77 && c <= 90) || (c >= 110 && c <= 122))
			c -= 26;
		c += 13;
		str[i] = c;
	}

	return (str);
}




