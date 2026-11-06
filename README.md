*This project has been created as part of the 42 curriculum by oumouzgu.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build, from scratch, your own C static library (`libft.a`) that reimplements a set of standard C library functions, together with additional utility functions and functions to manipulate linked lists.

This library is designed to be reused in future projects of the curriculum. It helps develop an understanding of how standard functions work internally, how memory is managed (allocation, copying, overlapping memory, and freeing), and how to write clean, norm-compliant, and well-structured C code.

### Overview of the Library

The library is divided into three parts.

#### Part 1 - Libc Functions

Reimplementations of functions from the standard C library, using the `ft_` prefix.

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

#### Part 2 - Additional Functions

Functions that extend the standard C library with useful string manipulation and output utilities.

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring from a string. |
| `ft_strjoin` | Allocates and returns the concatenation of two strings. |
| `ft_strtrim` | Allocates and returns a copy of a string with the specified characters removed from the beginning and end. |
| `ft_split` | Allocates and returns an array of strings obtained by splitting a string using a delimiter character. The array is terminated by a `NULL` pointer. |
| `ft_itoa` | Allocates and returns a string representing an integer. |
| `ft_strmapi` | Applies a function to each character of a string, using its index, and returns a newly allocated string containing the results. |
| `ft_striteri` | Applies a function to each character of a string, using its index, and passes the character's address so it can be modified in place. |
| `ft_putchar_fd` | Writes a character to the given file descriptor. |
| `ft_putstr_fd` | Writes a string to the given file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to the given file descriptor. |
| `ft_putnbr_fd` | Writes an integer to the given file descriptor. |

#### Part 3 - Linked List Functions

Functions for creating and manipulating linked lists, using the following structure defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees the content of a node using a given function, then frees the node itself. |
| `ft_lstclear` | Deletes and frees a node and all subsequent nodes. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Applies a function to the content of each node and creates a new list containing the results. If an allocation fails, the newly created list is cleared. |

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- `ar`

### Compilation

The library is compiled using the flags `-Wall -Wextra -Werror`.

From the root of the repository, run:

```sh
make
```

This produces the static library `libft.a` at the root of the repository.

The following rules are available in the `Makefile`:

| Rule | Description |
|---|---|
| `make` / `make all` | Compiles the source files and creates `libft.a`. |
| `make clean` | Removes the object files (`.o`). |
| `make fclean` | Removes the object files and `libft.a`. |
| `make re` | Runs `fclean`, then `all`. |

### Usage

Include the header `libft.h` in your source files:

```c
#include "libft.h"
```

Then compile your program together with the library:

```sh
cc -Wall -Wextra -Werror main.c libft.a
```

Run the resulting executable:

```sh
./a.out
```

Example:

```c
#include "libft.h"
#include <stdlib.h>

int main(void)
{
    char    *str;

    str = ft_strjoin("Hello, ", "42!");
    if (!str)
        return (1);
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

## Resources

### References

- [Linux manual pages](https://man7.org/linux/man-pages/)
- [`atoi(3)`](https://man7.org/linux/man-pages/man3/atoi.3.html)
- [`strlen(3)`](https://man7.org/linux/man-pages/man3/strlen.3.html)
- [`strlcpy(3)`](https://man7.org/linux/man-pages/man3/strlcpy.3.html)
- [`strchr(3)`](https://man7.org/linux/man-pages/man3/strchr.3.html)
- [`strncmp(3)`](https://man7.org/linux/man-pages/man3/strncmp.3.html)
- [`strdup(3)`](https://man7.org/linux/man-pages/man3/strdup.3.html)
- [`memset(3)`](https://man7.org/linux/man-pages/man3/memset.3.html)
- [`memcpy(3)`](https://man7.org/linux/man-pages/man3/memcpy.3.html)
- [`memmove(3)`](https://man7.org/linux/man-pages/man3/memmove.3.html)
- [`calloc(3)`](https://man7.org/linux/man-pages/man3/calloc.3.html)
- [`toupper(3)`](https://man7.org/linux/man-pages/man3/toupper.3.html)
- [`isalpha(3)`](https://man7.org/linux/man-pages/man3/isalpha.3.html)

### Use of AI

AI was used only for the `README.md` file, specifically for structuring and proofreading its content. It was not used to write any part of the library's code.

The project was developed by researching questions on Google and learning through peer discussions, which helped me understand the subject and solve implementation problems.

All the code in the library was written, tested, and understood by oumouzgu.