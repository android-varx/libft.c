#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);

void *ft_memset(void *s, int x, size_t n);

size_t ft_strlen(const char *s);

int ft_tolower(int c);
int ft_toupper(int c);


#endif
