#include "libft.h"

typedef struct      s_list
{
    void            *content;
    struct s_list   *next
}                   t_list;


void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *last;

    if(new == NULL)
        return;
    if(*alst == NULL)
    {
        *alst = new;  
    }
    else
    {
        last = ft_lstlast(*alst);
        last -> next = new;
    }
    new -> next = NULL;    
}