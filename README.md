Printf is a c function that prints a string to stdout.

As argument it recieves a formatted string where it replaces the content
of the next variable that was passed when it sees a '%' char followed by
the variable type or the format of how you want it printed. Returns
length of output to stdout.

For example, if the passed parameters are ("Hello %s %i", "world!", 25),
it should print out:
Hello world! 25

It does not print an end of line at the end.

Formats are:
%c = char,
%s = string,
%S = formatted string,
%i, %d = int,
%u = unsigned int,
%b = binary,
%o = octal,
%x = hex,
%X = hex, capitalized,
%p = pointers

%% = literal '%'

If a '%' char is followed by an unrecognized format character it prints both chars.

Compiled with 'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format \*.c'

How it works?

printf.c holds \_printf() which prints each character normally
except when it encounters a %. When char is % checks if the next character is
recognized as a type of variable. If not it prints both the % and the next char.
If an empty % is at the end it stops and returns -1.

Each char is paired with a printing function. Printing functions rely on
"tool" functions of the same type. You can find these functions based on the
type of variable you want to print. "tool" functions are placed in "\_tools" files.
