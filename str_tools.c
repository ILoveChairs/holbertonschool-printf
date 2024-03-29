#include "main.h"

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
 * _bufferize_hex -	Adds hex form of char a to buffer.
 *
 * @a:			Char to bufferize.
 *
 * @buffer:		Buffer.
 */
void _bufferize_hex(char a, buffer_t *buffer)
{
	int c;
	char heX[] = "0123456789ABCDEF";

	c = (a / 16) % 16;
	_buffer_add(heX[c], buffer);
	c = a % 16;
	_buffer_add(heX[c], buffer);
}

/**
 * _strcpy -	Copies src to dest.
 *
 * @src:	Source string.
 *
 * @dest:	Destiny string.
 *
 * Return:	(dest)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *src; src++)
	{
		*dest = *src;
		dest = dest + 1;
		i = i + 1;
	}

	*dest = *src;
	dest = dest - i;
	return (dest);
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

	for (i = 0; i <= len / 2; i++)
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
	char c;

	while (*str)
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
		{
			c = *str;
			if ((c >= 77 && c <= 90) || (c >= 110 && c <= 122))
				c -= 26;
			c += 13;
			*str = c;
		}
		str++;
	}

	return (str);
}




