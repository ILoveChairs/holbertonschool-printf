#include "main.h"
#include <unistd.h>

/**
 * _buffer_write -	Writes buffer's content to stdout.
 *
 * @buffer:		Buffer write on.
 */
void _buffer_write(buffer_t *buffer)
{
	write(1, buffer->content, buffer->len);
	buffer->len_total += buffer->len;
	buffer->len = 0;
}

/**
 * _buffer_check -	Checks if buffer reaches max capacity.
 *			Writes if it did.
 *
 * @buffer:		Buffer to check.
 */
void _buffer_check(buffer_t *buffer)
{
	if (buffer->len == 1024)
	{
		_buffer_write(buffer);
	}
}

/**
 * _buffer_add -	Adds character to buffer.
 *
 * @c:			Character.
 *
 * @buffer:		Buffer.
 */
void _buffer_add(char c, buffer_t *buffer)
{
	buffer->content[buffer->len++] = c;
	_buffer_check(buffer);
}

/**
 * _buffer_add_str -      Prints string as is.
 *              (without ending in end of line).
 *
 * @str:        Str to print, doesn't check if null.
 *
 * @buffer:	Buffer.
 */
void _buffer_add_str(char *str, buffer_t *buffer)
{
	while (*str)
	{
		_buffer_add(*str++, buffer);
	}
}


