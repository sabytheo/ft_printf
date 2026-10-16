*This project has been created as part of the 42 curriculum by tsaby.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library `printf()`, built as part of the 42 curriculum.

```c
int	ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of characters printed, like the original. The project is an introduction to **variadic functions** in C (`va_start`, `va_arg`, `va_end`).

### Supported conversions

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` for a `NULL` pointer) |
| `%p` | a pointer address in hexadecimal (`0x...`, `(nil)` for `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned integer in lowercase / uppercase hexadecimal |
| `%%` | a percent sign |

## Instructions

```bash
make    # builds libftprintf.a
```

Compiled with `-Wall -Wextra -Werror`. To use it:

```c
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = ft_printf("%s is %d years old, %x in hex, at %p\n", "Marvin", 42, 42, &n);
	ft_printf("%d characters printed\n", n);
	return (0);
}
```

```bash
cc main.c -L. -lftprintf -o program
```

## Project structure

```
.
├── Makefile
├── ft_printf.h
└── src/
    ├── ft_printf.c / ft_printf_2.c     # format parsing and conversions
    └── ft_itoa.c / ft_uitoa.c / ft_itoahex.c / ft_strlen.c
```

## Resources

- `man 3 printf`, `man 3 stdarg`
- [printfTester](https://github.com/Tripouille/printfTester)
