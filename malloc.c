#include <stdlib.h>

int is_charset(char c, char *charset)
{
	int i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return 1;
		i++;
	}
	return 0;
}

int count_words(char *str, char *charset)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset) && (i == 0 || is_charset(str[i - 1], charset) == 1))
			count++;
		i++;
	}
	return count;
}

char *ft_strndup(char *src, int n)
{
	int i;
	char *dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return NULL;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char **ft_split(char *str, char *charset)
{
	char **res;
	int words;
	int i;
	int len;

	words = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
			str++;
		else
		{
			len = 0;
			while (str[len] && !is_charset(str[len], charset))
				len++;
			res[i] = ft_strndup(str, len);
			if (!res[i])
				return (NULL);
			str += len;
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
#include <stdio.h>

int main(void)
{
	char *str = "Hello,42,Tokyo";
	char *charset = ",";
	char **result = ft_split(str, charset);
	int i = 0;

	if (!result)
		return (1);
	while (result[i] != NULL)
	{
		printf("word[%d]: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}