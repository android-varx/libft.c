#include "libft.h"

void *ft_memset(void *s, int x, size_t n)
{
    size_t i = 0;
    unsigned char *m = (unsigned char *)s;

    while (i < n)
    {
        m[i] = (unsigned char)x;
        i++;
    }
    return s;
}
