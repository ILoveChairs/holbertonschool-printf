#ifndef _PRINTF
#define _PRINTF

#include <stdarg.h>

/**
 * struct buffer_t -	Buffer that calls write each 1024 characters.
 *
 * @len:	Current length of used buffer.
 *
 * @len_total:	Length of all characters printed.
 *
 * @content:	Content of the buffer. Malloc'd.
 *
 * Description:	Functions add a char to content[len++] and check
 *		if it reached the limit.
 *		If it does it prints out content, resets len and adds
 *		to len_total.
 *		At the end of printf it checks if len > 0 to print if
 *		content was written but haven't reached limit.
 */
typedef struct buffer_t
{
	unsigned int len;
	unsigned int len_total;
	char content[1024];
} buffer_t;

/**
 * struct func_pair -	Struct to use in printf.c for knowing
 *			which function to call when encountering
 *			a % symbol.
 *
 * @c:	Char that holds the type of variable to print.
 *	'c' = char, 's' = string,
 *	'i' or 'd' = int, 'u' = unsigned int,
 *	'o' = unsigned octal,
 *	'x' = unsigned hexadecimal, 'X' = unsigned hexadecimal mayus,
 *	'f' = float, 'd' = double,
 *	'p' = pointer.
 *
 * @f:	Function, takes the va_list from printf as argument and prints it.
 *
 * Description:	Pairs a char with a function which takes the va_list
 *		from printf and prints it. The char has the va_list
 *		variable type information.
 */
typedef struct func_pair
{
	char c;
	void (*f)(va_list, buffer_t *);
} func;

/** TOOLS **/

/* Buffer manipulation, from buffer_tools.c */
void _buffer_write(buffer_t *);
void _buffer_check(buffer_t *);
void _buffer_add(char, buffer_t *);
void _buffer_add_str(char *, buffer_t *);

/* String manipulation, from str_tools.c */
int _strlen(char *);
void _bufferize_hex(char, buffer_t *);
char *_strcpy(char *, char *);
char *_reverse_string(char *);
char *_rot13(char *);

/* Int manipulation tools, from int_tools.c */
int _pow(int, int);
int _intlen(int);
char *_itoa(char *, int);
void _ito_print(int, buffer_t *);

/* Unsigned int manipulation tools, from unsigned_tools.c */
int _uintlen(unsigned int);
void _uto_print(unsigned int, buffer_t *);

/* Octal and hexadecimal conversion tools, from octahex_tools.c */
int _get_first_digit(unsigned int, int);
void _max_unrecursive(unsigned int, char *, int, char *);
void _max_converter(unsigned int, char *, buffer_t *);

/** PRINTING FUNCTIONS **/

/* String and char printing, from strings.c */
void printf_char(va_list, buffer_t *);
void printf_str(va_list, buffer_t *);
void printf_Str(va_list, buffer_t *);
void printf_reverse(va_list, buffer_t *);
void printf_rot13(va_list, buffer_t *);

/* Int and unsigned int printing, from ints.c */
void printf_int(va_list, buffer_t *);
void printf_unsigned(va_list, buffer_t *);

/* Unsigned octal and hexadecimal, from octahex.c */
void printf_un_octal(va_list, buffer_t *);
void printf_un_hex(va_list, buffer_t *);
void printf_un_heX(va_list, buffer_t *);
void printf_un_binary(va_list, buffer_t *);

/* Pointer printing, from pointer.c */
void printf_pointer(va_list, buffer_t *);

/** PRINTF **/

/* Main function, from printf.c */
void (*get_function(char))(va_list, buffer_t);
void _printf_porcentaje(char, va_list, buffer_t *);
int _printf_iteration(const char *format, va_list args, buffer_t *buffer);
int _printf(const char *format, ...);

#endif
