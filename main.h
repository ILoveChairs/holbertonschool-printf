#ifndef PRINTF
#define PRINTF

#include <stdarg.h>

/**
 * struct func - Struct to use in printf.c for knowing which function to call.
 * @c:	Char that holds the type of variable to print.
 *	'c' = char, 's' = string,
 *	'i' or 'd' = int, 'u' = unsigned int,
 *	'f' = float, 'd' = double,
 *	'p' = pointer.
 * @f:	Function, takes only the va_list from printf as argument and prints it.
 *
 * Description:	Pairs a char (which means type of variable) with a function
 *		which takes the va_list from printf and prints it.
 */
typedef struct func
{
	char c;
	int (*f)(va_list);
} func;

/* from put_funcs.c */
int _putchar(char);
int _puts(char *);

/* functions for printing characters and strings */
int printf_char(va_list);
int printf_str(va_list);

/* haven't been made yet*/
char *_itoa(char *, int);
char *_ftoa(char *, float);
char *_dtoa(char *, double);

/* functions for printing integers */
int printf_int(va_list);
int printf_unsigned(va_list);

/* haven't been made yet */
int printf_float(va_list);
int printf_double(va_list);

/* haven't been made yet */
int printf_pointer(va_list);

/* Main function, printf.c */
int (*get_function(char))(va_list);
int _printf(const char *format, ...);

#endif
