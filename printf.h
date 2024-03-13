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
	char *c;
	void (*f)(va_list);
} func;

/* from put_funcs.c */
void _putchar(char);
void _puts(char *);

/* haven't been made yet */
void printf_char(va_list);
void printf_str(va_list);

/* haven't been made yet*/
char *_itoa(char *, int);
char *_ftoa(char *, float);
char *_dtoa(char *, double);

/* haven't been made yet */
void printf_int(va_list);
void printf_unsigned(va_list);

/* haven't been made yet */
void printf_float(va_list);
void printf_double(va_list);

/* haven't been made yet */
void printf_pointer(va_list);

/* haven't been made yet */
void _printf(char*, ...);

#endif
