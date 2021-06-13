#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	size_t	a;
	char	*new;

	a = 0;
	if (!s)
		return (NULL);
	length = ft_strlen(s);
	new = malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	while (length)
	{
		new[a] = f(a, s[a]);
		a++;
		length--;
	}
	new[a] = '\0';
	return (new);
}
