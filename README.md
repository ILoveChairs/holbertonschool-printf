Printf is a c function that prints a string.

As argument it recieves a formatted string where it replaces the next variable
that was passed when it sees a '%' char followed by the variable type or the format
of how you want it printed.

For example, if the passed parameters are ("Hello %s %i", "world!", 25),
it should print out:
Hello world! 25

It does not print an end of line at the end.

Formats are:
%c = char,
%s = string,
%i, %d = int
%u = unsigned int

%% = literal '%'

If a '%' char is followed by an unrecognized format character it prints both chars.

Compiled with 'gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c'
