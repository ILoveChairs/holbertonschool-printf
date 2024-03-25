# Printf Function in C

The `printf` function in C is used to print a string to the standard output.

As arguments, it receives a formatted string where it replaces the content of the next variable when it encounters a '%' character followed by the variable type or the format of how you want it printed. It returns the length of the output to stdout.

For example, if the passed parameters are `("Hello %s %i", "world!", 25)`, it should print out: `Hello world! 25`

It does not print an end-of-line character at the end.

## Supported Formats

- `%c`: character
- `%s`: string
- `%S`: formatted string
- `%i`, `%d`: integer
- `%u`: unsigned integer
- `%b`: binary
- `%o`: octal
- `%x`: hexadecimal
- `%X`: hexadecimal (capitalized)
- `%p`: pointers
- `%%`: literal '%'

If a '%' character is followed by an unrecognized format character, it prints both characters.

## How it works?

This is our Printf Flowchart to show how it works:

![PRINTF FLOWCHART](https://github.com/ILoveChairs/holbertonschool-printf/assets/135678248/73c97f71-e15d-4af6-8740-5184d41ab8c8)

Printf.c holds \_printf() which prints each character normally
except when it encounters a %. When char is % checks if the next character is
recognized as a type of variable. If not it prints both the % and the next char.
If an empty % is at the end it stops and returns -1.

Each char is paired with a printing function. Printing functions rely on
"tool" functions of the same type. You can find these functions based on the
type of variable you want to print. "tool" functions are placed in "\_tools" files.

## Compilation

Compiled with:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`

## Authors

`Matias Davezac`

`Hernán Alegresa`
