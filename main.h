#ifndef PRINTF
#define PRINTF

#include <stdarg.h>

/**
 * struct func_pair -	Struct to use in printf.c for knowing
 *			which function to call when encountering
 *			a % symbol.
 *
 * @c:	Char that holds the type of variable to print.
 *	'c' = char, 's' = string,
 *	'i' or 'd' = int, 'u' = unsigned int,
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
	int (*f)(va_list);
} func;

/** TOOLS **/
/* Base printing functions, also strlen, from str_tools.c */
int _strlen(char *);
int _putchar(char);
int _puts(char *);

/* Int manipulation tools, from int_tools.c */
int _pow(int, int);
int _intlen(int);
char *_itoa(char *, int);
int _ito_print(int);

/* Double manipulation tools, from --- */
char *_dtoa(char *, double);

/** PRINTING FUNCTIONS **/
/* String and char printing, from strings.c */
int printf_char(va_list);
int printf_str(va_list);

/* Int and unsigned int printing, from ints.c */
int printf_int(va_list);
int printf_unsigned(va_list);

/* Float and double printing, from --- */
int printf_float(va_list);
int printf_double(va_list);

/* Pointer printing, from --- */
int printf_pointer(va_list);

/** PRINTF **/
/* Main function, from printf.c */
int (*get_function(char))(va_list);
int _printf(const char *format, ...);

#endif
