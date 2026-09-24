# Libft - Your Very First Own Library

_This project has been created as part of the 42 curriculum by sywee._

## Description

Libft is a personal C library that implements a set of functions commonly used in C programming. The goal of this project is to reimplement a variety of standard library functions, as well as some additional utility functions, in order to understand their inner workings and improve your understanding of memory management.

This library will be essential for future assignments and is meant to be used as a base for your other projects.

---

## 🛠️ Instructions

### Compilation

To compile the library, you will need to run the following commands in your terminal:

1. **all**: Compiles the library into a static library (`libft.a`).
    ```bash
    make all
    ```

2. **clean**: Removes object files generated during compilation.
    ```bash
    make clean
    ```

3. **fclean**: Removes both object files and the compiled library (`libft.a`).
    ```bash
    make fclean
    ```

4. **re**: Recompiles the library from scratch.
    ```bash
    make re
    ```

5. **bonus**: Compiles the bonus part of the project (linked list functions).
    ```bash
    make bonus
    ```

---

## 📚 Library Overview

### Part 1: Libc Functions
These functions reimplement standard C library functions with the `ft_` prefix.

| Type        | Functions                                                                                                   |
|-------------|-------------------------------------------------------------------------------------------------------------|
| **Memory**  | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`                                |
| **Strings** | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| **Is-Type** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`                                        |
| **Conversions** | `ft_toupper`, `ft_tolower`, `ft_atoi`, `ft_calloc`                                                      |

### Part 2: Additional Functions
Utility functions for string and number manipulation.

| Function Name   | Description                                                          |
|-----------------|----------------------------------------------------------------------|
| `ft_substr`     | Extracts a substring from a string.                                  |
| `ft_strjoin`    | Concatenates two strings.                                            |
| `ft_strtrim`    | Trims characters from both ends of a string.                         |
| `ft_split`      | Splits a string into an array of strings using a delimiter.          |
| `ft_itoa`       | Converts an integer to a string.                                     |
| `ft_strmapi`    | Applies a function to each character of a string.                    |
| `ft_striteri`   | Applies a function to each character of a string, passing the index. |
| `ft_putchar_fd` | Outputs a character to a file descriptor.                            |
| `ft_putstr_fd`  | Outputs a string to a file descriptor.                               |
| `ft_putendl_fd` | Outputs a string followed by a newline to a file descriptor.         |
| `ft_putnbr_fd`  | Outputs an integer to a file descriptor.                             |

### Part 3: Linked Lists
This part includes functions for manipulating singly linked lists.

| Function Name    | Description                                                       |
|------------------|-------------------------------------------------------------------|
| `ft_lstnew`      | Creates a new node.                                               |
| `ft_lstadd_front`| Adds a node to the front of the list.                             |
| `ft_lstadd_back` | Adds a node to the back of the list.                              |
| `ft_lstsize`     | Returns the size of the list.                                     |
| `ft_lstlast`     | Returns the last node in the list.                                |
| `ft_lstdelone`   | Deletes a node.                                                   |
| `ft_lstclear`    | Deletes and frees all nodes in the list.                          |
| `ft_lstiter`     | Applies a function to each node in the list.                      |
| `ft_lstmap`      | Creates a new list by applying a function to each node.           |

---

## 🧑‍💻 Usage

To use this library, include `libft.h` in your project and link the compiled `libft.a` file when compiling your code.

Example:

```c
#include "libft.h"

int main(void) {
    char *str = ft_itoa(1234);
    ft_putstr_fd(str, 1);
    free(str);
    return 0;
}

