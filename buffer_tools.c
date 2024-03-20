#include "main.h"
#include <unistd.h>

/**
 * _write_buffer -	Writes buffer's content to stdout.
 *
 * @buffer:		Buffer to flush.
 */
void _buffer_write(buffer_t *buffer)
{
	write(1, buffer->content, buffer->len);
	buffer->len_total += buffer->len;
	buffer->len = 0;
}

/**
 * _check_buffer -	Checks if buffer reaches max capacity.
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
 * _buffer_add -	
 *
 * @c:			
 *
 * @buffer:		
 */
void _buffer_add(char c, buffer_t *buffer)
{
	buffer->content[buffer->len++] = c;
	_buffer_check(buffer);
}

/**
 * _puts -      Prints string as is.
 *              (without ending in end of line).
 *
 * @str:        Str to print, doesn't check if null.
 */
void _buffer_add_str(char *str, buffer_t *buffer)
{
        while (*str)
        {
                _buffer_add(*str++, buffer);
        }
}
