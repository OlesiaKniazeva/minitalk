#include "libft.h"
#include <stdlib.h>

static int	ft_amount(const char *first, const char *second)
{
	int	amount;

	amount = 0;
	while (*first)
	{
		amount++;
		first++;
	}
	while (*second)
	{
		amount++;
		second++;
	}
	return (amount);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	char		*new;

	newstr = malloc(sizeof(char) * (ft_amount(s1, s2) + 1));
	if (newstr == NULL)
		return (NULL);
	new = newstr;
	while (*s1)
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	while (*s2)
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = '\0';
	return (new);
}
