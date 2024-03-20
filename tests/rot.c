#include "main.h"
#include <stdio.h>

int main(void)
{
	char str[]= "abcdefghijklmnopqrstuvwxyz";
	int a, b;

	a = _printf("%s\n", str);

        b = _printf("%R\n", str);

	_printf("%i, %i\n", a, b);
	return (0);
}
