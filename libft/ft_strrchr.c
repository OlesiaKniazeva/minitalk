#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	char	*new;
	int		a;

	d = c - '0';
	a = ft_strlen(s);
	while (a >= 0)
	{
		if (*(s + a) == c)
		{
			new = (char *)(s + a);
			return (new);
		}
		a--;
	}
	new = 0;
	return (new);
}
