#include "libft.h"
#include <stdlib.h>

static int	ft_amount(const char *t)
{
	int	a;

	a = 0;
	while (*t)
	{
		a++;
		t++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	char	*pointer;
	int		a;

	a = 0;
	pointer = malloc(sizeof(char) * (ft_amount(s1) + 1));
	if (pointer == NULL)
		return (NULL);
	temp = pointer;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (pointer);
}
