# ft_printf

## Description
The **ft_printf** project consists of recoding the famous `printf` function from the standard C library (`libc`).
The function `ft_printf()` mimics the behavior of the original `printf()` function without implementing buffer management.
It is a great opportunity to learn about handling a variable number of arguments (variadic functions in C).

## Instructions
To use this library:

1. Clone this repository.
2. Compile the library by typing the `make` command.
3. This will create the `libftprintf.a` file.
4. Include the header `#include "ft_printf.h"` in your `.c` files.
5. Compile your program with `gcc your_program.c libftprintf.a -o your_program`.

**Compilation commands:**
- `make`: Compiles the library (`libftprintf.a`).
- `make clean`: Removes the temporary object files (`.o`).
- `make fclean`: Removes the object files and the library.
- `make re`: Recompiles everything from scratch.

## Algorithm and Design Choices
**Algorithm Structure:**
The algorithm for this project is based on parsing the format string character by character.
When a character is not a `%`, I simply print it. When a `%` is encountered, I read the next character to determine the conversion type (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, or `%`) and extract the corresponding argument using the macros from the `va_list` family (variadic functionality from `<stdarg.h>`).

**Technical Choices:**

- Variadic arguments are handled using `va_start`, `va_arg`, `va_copy`, and `va_end`.

- Output is managed using the `write` system call.

- The project uses a modular structure to keep the code maintainable and extensible.

## What does my function do?
It handles the following conversions, with exactly the same behavior as the original `printf` (excluding the original's long buffer management):
- `%c`: Prints a single character.
- `%s`: Prints a string of characters.
- `%p`: Prints a pointer address (hexadecimal format).
- `%d` or `%i`: Prints an integer (base 10).
- `%u`: Prints an unsigned integer (base 10).
- `%x`: Prints a number in lowercase hexadecimal (base 16).
- `%X`: Prints a number in uppercase hexadecimal (base 16).
- `%%`: Prints a percent sign `%`.
