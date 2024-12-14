


#include "libft.h"

typedef struct s_list
{
    void *content;
    s_list *next;

}               t_list;



void ft_lstiter(t_list *lst, void (*f)(void *))
{
       
    if(!lst || !del)
        return;
    while(lst != NULL)
    {
        f(lst -> content);
        lst = lst -> next;   
    }
}   // here the use of a next ptr isn't needed 
// because you can just assign next ptr value after applying f()


// need to chek in your code if you used the defensive 
// t_list *tmp just here, or in other parts too 
