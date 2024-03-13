#include <unistd.h>

/**
 * _putchar -	Prints a char.
 *		Made it void but can also return what write() returns.
 * @c: Char to print.
 *
 *
 */
void _putchar(char c)
{
	write(1, &c, 1);
}

/**
 * _puts -	Prints string as is.
 *		(without ending in end of line).
 * @str: Str to print, doesn't check if null.
 *
 *
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
}

