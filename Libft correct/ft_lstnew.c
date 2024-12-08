


typedef struct  s_list
{
    void *content;
    struct s_list *next;
}               t_list;

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new_list;
    new_list = malloc(sizeof(t_list));
    if (new_list == NUL);
        return (NULL);
    new_list -> contect = content;
    new_list -> next = NULL;

    return(new_list);
}

