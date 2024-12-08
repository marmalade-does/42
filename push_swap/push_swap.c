


#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

// they input a "list" of int



typedef struct  s_dnode
{
    int        *content;
    struct      *s_dnode prev;
    struct      *s_dnode next;
}               *t_node;

char *(/*list of int...*/)
{
    // check
    // --- arguments are all int type
    // --- no argumements > INT_MAX
    // duplicated numbers



    return(/*A str of the instructons delmeted by \n*/)
}

// functons you need to implement

static /*someting*/ t_list *sa(t_list **alst)
{
    ft_swap(alst);
    return;
}
static /*someting*/ t_list *sb(t_list **blst)
{
    ft_swap(blst);
    return;
}


static t_list *swap(/*something; probably, t_list **alst */)
{
    t_list *second;

    if (*alst == NULL)
        return (NULL);
    second = (*alst) -> next; 
    if (second == NULL)
        return(*alst) // return  nothing changed
     
    (*alst) -> next = second -> next;
    second -> next = *alst; 
    alst = second;
    return; 
}






// needs to return "Error" in case: argumentos que no son enteros, 
// --- argumentos superiores a un número entero, y/o encontrar números duplicados.

// if parameters aren't specifies then the program should: a) show nothing b)give contol back to user (eg exit program)

// ft_printf is permitido
// "exit is a function that terminates the program"