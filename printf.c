#include "main.h"
#include <stdarg.h>
#include <stddef.h>

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
		{'u', printf_unsigned},
		{'o', printf_un_octal},
		{'x', printf_un_hex},
		{'X', printf_un_heX},
		{'b', printf_un_binary},
		{'%', printf_char}
	};

	for (i = 0; funcs[i].c != '%'; i++)
	{
		if (funcs[i].c == c)
			return (funcs[i].f);
	}
	return (NULL);
}

/**
 * _printf_porcentaje -	Checks if the character after % corresponds to a var
 *			type or %. If neither print both % and char. Originally
 *			inside _printf but code got too long.
 *
 * @typer:		Char right after %.
 *
 * @args:		va_list, passed to be pass along to
 *			the function it gets.
 *
 * Return:		Length of all characters printed.
 */
int _printf_porcentaje(char typer, va_list args)
{
	int len;
	int (*fpointer)(va_list);

	len = 0;

	if (typer == '%')
	{
		len += _putchar('%');
	}
	else
	{
		fpointer = get_print(typer);

		if (fpointer)
		{
			len += fpointer(args);
		}
		else
		{
			len += _putchar('%');
			len += _putchar(typer);
		}
	}

	return (len);
}

/**
 * _printf -	Prints str, and where a %* lies, the variable
 *		passed as argument of the same type as * is printed.
 *
 * @format:	Formatted string to be printed.
 *
 * Return:	Number of chars printed.
 */
int _printf(const char *format, ...)
{
	int i;
	int porcentaje_flag;
	int len;
	va_list args;

	len = 0;
	if (!format)
		return (-1);

	va_start(args, format);

	porcentaje_flag = 0;
	for (i = 0; format[i]; i++)
	{
		if (porcentaje_flag)
		{
			len += _printf_porcentaje(format[i], args);
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

	if (porcentaje_flag)
		return (-1);
	va_end(args);
	return (len);
}
