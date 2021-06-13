#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = c - '0';
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
