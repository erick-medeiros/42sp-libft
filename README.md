# 42sp-libft
This project is about coding a C library.
It will contain a lot of general purpose functions your programs will rely upon.

## Final Score

<img height=150px src=https://github.com/erick-medeiros/guide42/blob/main/grade/grade_125_100.png alt="eandre-f score"/>

## Part 1

Implementation of original functions

- `ft_isalpha` checks for an alphabetic character
- `ft_isdigit` checks for an digit character
- `ft_isalnum` checks for an alphanumeric character
- `ft_isascii` checks for an ASCII character
- `ft_isprint` checks for an printable character
- `ft_strlen` calculate string length
- `ft_memset` fill memory
- `ft_bzero` set byte zero
- `ft_memcpy` memory area copy (not overlap)
- `ft_memmove` memory area copy (may overlap)
- `ft_strlcpy` string limited copy
- `ft_strlcat` string limited concatenation
- `ft_toupper` convert uppercase
- `ft_tolower` convert lowercase
- `ft_strchr` locate character in string (first occurrence)
- `ft_strrchr` locate character in string (last occurrence)
- `ft_strncmp` compare part of two strings
- `ft_memchr` locate character in memory (first occurrence)
- `ft_memcmp` compare memory areas
- `ft_strnstr` locate a substring in a string limited
- `ft_atoi` convert a string to an integer
- `ft_calloc` a memory allocator
- `ft_strdup` duplicate a string

## Part 2

Functions that are either not in the libc, or that are part of it but in a different form

- `ft_substr` create a substring
- `ft_strjoin` create a concatenated string
- `ft_strtrim` create a string trimmed
- `ft_split` split a string
- `ft_itoa` convert a integer to an string
- `ft_strmapi` create a new string applying a function
- `ft_striteri` apply a function to each string character
- `ft_putchar_fd` outputs the character
- `ft_putstr_fd` outputs the string
- `ft_putendl_fd` outputs the string followed by a newline
- `ft_putnbr_fd` outputs the integer

## Bonus

Functions that manipulating lists
- `ft_lstnew` create new node of list
- `ft_lstadd_front` adds the node to beginning of list
- `ft_lstsize` counts the number of nodes in a list
- `ft_lstlast` returns the last node of the list
- `ft_lstadd_back` adds the node to end of list
- `ft_lstdelone` frees node memory
- `ft_lstclear` frees list memory
- `ft_lstiter` applies the function on content of each node
- `ft_lstmap` creates a new list resulting of applying of the function

## Usage

Run tests
```
gcc -g libft.h ft_*.c tests.c -lbsd -o tests.out && ./tests.out
```
