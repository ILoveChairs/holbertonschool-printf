#include "main.h"

/**
* print_binary - Prints a binary number
* @arg: Argument list
* Return: Number of characters printed
*/
int print_binary(va_list arg)
{
	unsigned int u;
	char binary[100];
	int len = 0;
	int i = 0;

	u = va_arg(arg, unsigned int);

	if (u == 0)
	{
		_putchar('0');
		return (1);
	}

	while (u > 0)
	{
		binary[i++] = (u % 2) + '0';
		u = u / 2;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		_putchar(binary[j]);
		len++;
	}

	return (len);
}

/**
* print_octal - Prints an octal number
* @arg: Argument list
* Return: Number of characters printed
*/
int print_octal(va_list arg)
{
	unsigned int u;
	char octal[100];
	int len = 0;
	int i = 0;

	u = va_arg(arg, unsigned int);

	if (u == 0)
	{
		_putchar('0');
		return (1);
	}

	while (u > 0)
	{
		octal[i++] = (u % 8) + '0';
		u = u / 8;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		_putchar(octal[j]);
		len++;
	}

	return (len);
}
