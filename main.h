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

/* Octal and hexadecimal conversion tools, from octahex_tools.c */
int _get_first_digit(unsigned int, int);
int _max_recursive(unsigned int, char *, int, int);
int _max_converter(unsigned int, char *);

/* Double manipulation tools, from --- */
char *_dtoa(char *, double);

/** PRINTING FUNCTIONS **/
/* String and char printing, from strings.c */
int printf_char(va_list);
int printf_str(va_list);

/* Int and unsigned int printing, from ints.c */
int printf_int(va_list);
int printf_unsigned(va_list);

/* Unsigned octal and hexadecimal, from octahex.c */
int printf_un_octal(va_list);
int printf_un_hex(va_list);
int printf_un_heX(va_list);
int printf_un_binary(va_list);

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
