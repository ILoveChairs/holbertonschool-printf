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
	char *buffer;

	buffer = malloc(1024);
	while (*str)
	{
		for (i = 0; *str && i < 1024; i++)
			buffer[i] = *(str++);
		write(1, buffer, i + 1);
		if (i == 1024)
			str += 1024;
	}

	free(buffer);
	return (i);
}
