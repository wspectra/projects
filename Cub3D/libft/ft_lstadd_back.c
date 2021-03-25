#include "libft.h"

void	ft_lstadd_back(t_list **lt, t_list *new)
{
	if (!lt || !new)
		return ;
	else if (!(*lt))
		*lt = new;
	else
		ft_lstlast(*lt)->next = new;
}
