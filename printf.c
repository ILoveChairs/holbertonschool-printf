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
void (*get_print(char c))(va_list, buffer_t *)
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
		{'r', printf_reverse},
		{'R', printf_rot13},
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
void _printf_porcentaje(char typer, va_list args, buffer_t *buffer)
{
	void (*fpointer)(va_list, buffer_t *);

	if (typer == '%')
	{
		_buffer_add('%', buffer);
	}
	else
	{
		fpointer = get_print(typer);

		if (fpointer)
		{
			fpointer(args, buffer);
		}
		else
		{
			_buffer_add('%', buffer);
			_buffer_add(typer, buffer);
		}
	}
}


/**
 * _printf_iteration -	Shortening _printf by dividing task into functions.
 *			this one iterates through format.
 *
 * @:			
 * @:			
 *
 * Return:		Length of output.
 */
int _printf_iteration(const char *format, va_list args, buffer_t *buffer)
{
	int porcentaje_flag;

	while (*format)
	{
		if (porcentaje_flag)
		{
			_printf_porcentaje(*format, args, buffer);
			porcentaje_flag = 0;
		}
		else if (*format == '%')
		{
			porcentaje_flag = 1;
		}
		else
		{
			_buffer_add('%', buffer);
		}

		format++;
	}

	if (buffer->len > 0)
	{
		_buffer_write(buffer);
	}

	if (porcentaje_flag)
	{
		return (-1);
	}

	return (0);
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
	int len;
	va_list args;
	buffer_t buffer;

	if (!format)
	{
		return (-1);
	}

	buffer.len = 0;
	buffer.len_total = 0;

	va_start(args, format);

	len = _printf_iteration(format, args, &buffer);

	va_end(args);

	if (len != -1)
	{
		len = buffer.len_total;
	}

	return (len);
}


