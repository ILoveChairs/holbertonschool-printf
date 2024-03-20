#include "main.h"
#include <stdio.h>

int main(void)
{
	char str[8564];
	int i;
	int a, b;

	for (i = 0; i < 8564; i++)
		str[i] = 48;

	a = printf("%s\n\n", str);
	b = _printf("%s\n\n", str);

	printf("%d, %d\n", a, b);

	return (0);
}
