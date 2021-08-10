#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*b_elem;

	if (lst)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			b_elem = ft_lstlast(*(lst));
			b_elem->next = new;
		}
	}
}
