#include "libft.h"

static int count_words(char const *s, char c)
{
	int count;
	int in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char *dup_word(const char *s, int start, int end)
{
	char *word;
	int i;

	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void free_split(char **split, int words)
{
	int i;

	i = 0;
	while (i < words)
		free(split[i++]);
	free(split);
}

char **ft_split(char const *s, char c)
{
	char **split;
	int i;
	int j;
	int start;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start >= 0)
		{
			split[j++] = dup_word(s, start, i);
			if (!split[j - 1])
			{
				free_split(split, j - 1);
				return (NULL);
			}
			start = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
