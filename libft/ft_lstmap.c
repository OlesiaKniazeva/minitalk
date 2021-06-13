#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*pointer;		

	if (!lst)
		return (NULL);
	temp = NULL;
	pointer = temp;
	ft_lstiter(lst, *(*f)(void *));
	while (lst)
	{
		new = ft_lstnew(lst->content);
		if (!new)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		pointer = ft_lstadd_back(&pointer, new);
		lst = lst->next;
	}
	return (pointer);
}
