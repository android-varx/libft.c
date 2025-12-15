#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *p;
	size_t total_size;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	total_size = nmemb * size;
	p = malloc(total_size);
	if (!p)
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
