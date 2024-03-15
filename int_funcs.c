#include "printf.h"

/**
* printf_int - Print an integer
* @args: Argument to print
* Return: Number of characters printed
*/
void printf_int(va_list args)
{
	long int n = va_arg(args, int);
	long int num;
	int len = 0, digit = 1, divalue;

	if (n < 0)
	{
		_putchar('-');
		n *= -1;
		len++;
	}
	num = n;
	while (num >= 10)
	{
		digit *= 10;
		num /= 10;
	}
	num = n;
	while (digit >= 1)
	{
		divalue = num / digit;
		_putchar(divalue + '0');
		num -= divalue * digit;
		digit /= 10;
		len++;
	}
}

/**
* printf_unsigned - Prints an unsigned integer
* @args: Argument to print
* Return: Number of characters printed
*/
void printf_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int num;
	int len = 0, digit = 1, divalue;

	num = n;
	while (num >= 10)
	{
		digit *= 10;
		num /= 10;
	}
	num = n;
	while (digit >= 1)
	{
		divalue = num / digit;
		_putchar(unit + '0');
		num -= divalue * digit;
		digit /= 10;
		len++;
	}
}
