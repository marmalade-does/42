#include "libft.h"

typedef struct s_list
{
    void *content;
    s_list *next;

}               t_list;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	current = new_list;
	lst = lst->next;
	while (lst)
	{
		new_obj = ft_lstnew(f(lst->content));
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		current->next = new_obj;
		current = new_obj;
		lst = lst->next;
	}
	return (new_list);
}

// this implementation has a head node WITH data, see if that's correct







