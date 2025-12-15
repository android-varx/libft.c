#include "libft.h"

static int get_len(int n)
{
	int len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *str;
	int len;
	long n_long;

	n_long = n;
	len = get_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n_long == 0)
		str[0] = '0';
	if (n_long < 0)
	{
		str[0] = '-';
		n_long = -n_long;
	}
	while (n_long != 0)
	{
		str[--len] = (n_long % 10) + '0';
		n_long /= 10;
	}
	return (str);
}
