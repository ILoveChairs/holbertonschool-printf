#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * get_print -	Gets the function that corresponds to the given char.
 *
 * @c: Char that corresponds to the var type to be printed.
 *
 * Return:	If c doesn't correspond to anything it returns NULL.
 *		Else function that corresponds to c.
 */
int (*get_print(char c))(va_list)
{
	int i;
	func funcs[] = {
		{'c', printf_char},
		{'s', printf_str},
		{'i', printf_int},
		{'d', printf_int},
		{'u', printf_unsigned}
	};

	for (i = 0; i < 5; i++)
	{
		if (funcs[i].c == c)
		{
			return (funcs->f);
		}
	}
	return (NULL);
}

/**
 * _printf -	Prints str, and where a %* lies, the variable
 *		passed as argument of the same type as * is printed.
 *
 * @str:	Formatted string to be printed.
 *
 * Return:	Number of chars printed.
 */
int _printf(const char *format, ...)
{
	int i;
	int porcentaje_flag;
	int len;
	int (*fpointer)(va_list);
	va_list args;

	if (!format)
		return (-1);
	va_start(args, format);
	porcentaje_flag = 0;
	for (i = 0; format[i]; i++)
	{
		if (porcentaje_flag)
		{
			if (format[i] == '%')
			{
				len += _putchar('%');
			}
			else
			{
				fpointer = get_print(format[i]);
				if (fpointer)
					len += fpointer(args);
			}
			porcentaje_flag = 0;
		}
		else if (format[i] == '%')
		{
			 porcentaje_flag = 1;
		}
		else
		{
			len += _putchar(format[i]);
		}
	}
	va_end(args);
	return (len);
}
