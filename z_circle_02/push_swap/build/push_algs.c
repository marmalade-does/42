


typedef struct      s_dnode
{
    int            *content;
    struct s_dnode  *prev;
    struct s_dnode  *next;
}                   *t_dnode;

// TODO: most of tehm should have void returns
// later -- think about how to differenciate between eg sa and sb, without just changing input name.

// swap firt two elements
static void t_dnode *sa(t_dnode **alst)
{
    if(*alst == NULL || ((*alst) -> next == NULL))
        return;
    t_dnode *p_min_1; 
    t_dnode *p_1;
    t_dnode *p_0;

    p_0 = (*alst);
    p_min_1 = (p_0 -> prev); 
    p_1 = (p_0 -> next);

    p_0 -> prev = p_0 -> next;
    p_0 -> next = (p_0 -> next) -> next;

    p_1 -> next = p_1 -> prev;
    p_1 -> prev = p_min_1;

    *alst = p_2;
    return (/**/);
}
static void t_dnode *sb(t_dnode **blst)
{
    if(*blst == NULL || ((*blst) -> next == NULL))
        return;
    t_dnode *p_min_1; 
    t_dnode *p_1;
    t_dnode *p_0;

    p_0 = (*blst);
    p_min_1 = (p_0 -> prev); 
    p_1 = (p_0 -> next);

    p_0 -> prev = p_0 -> next;
    p_0 -> next = (p_0 -> next) -> next;

    p_1 -> next = p_1 -> prev;
    p_1 -> prev = p_min_1;

    *blst = p_2;
    return (/**/);
}
// make a ss
static void t_dnode *ss(t_dnode **alst, t_dnode **blst)
{
    sa(alst);
    sb(blst);
}

// forward rotations
static void t_dnode *ra(t_dnode **alst)
{
    if(*alst == NULL || ((*alst) -> next == NULL))
        return;
    (*alst) = (*alst) -> next;
}
static void t_dnode *rb(t_dnode **blst)
{
    if(*blst == NULL || ((*blst) -> next == NULL))
        return;
    (*blst) = (*blst) -> next;
}
static void t_dnode *rr(t_dnode **alst, t_dnode **blst)
{
    if(*alst == NULL || ((*alst) -> next == NULL))
        return;
    if(*blst == NULL || ((*blst) -> next == NULL))
        return;
    (*alst) = (*alst) -> next;
    (*blst) = (*blst) -> next;

}

// backward rotations
static void t_dnode *rra(t_dnode **alst)
{
    if(*alst == NULL || ((*alst) -> next == NULL))
        return;
    (*alst) = (*alst) -> prev;
}
static void t_dnode *rrb(t_dnode **blst)
{
    if(*blst == NULL || ((*blst) -> next == NULL))
        return;
    (*blst) = (*blst) -> prev;
}
static void t_dnode *rrr(t_dnode **alst, t_dnode **blst)
{
    if(*alst == NULL || ((*alst) -> next == NULL))
        return;
    if(*blst == NULL || ((*blst) -> next == NULL))
        return;
    (*alst) = (*alst) -> prev;
    (*blst) = (*blst) -> prev;
}

static void t_dnode *pa(t_dnode **alst, t_dnode **blst)
{
    t_dnode *pa_0;
    t_dnode *pb_0;
    t_dnode *a_tail;
    t_dnode *b_tail;

    if (!*alst)
        return;
    pa_0 = *alst;
    pb_0 = *blst;
    if (pa_0->next == pa_0)
        *alst = NULL;
    else
    {
        a_tail = pa_0->prev;
        *alst = pa_0->next;
        pa_0->next->prev = a_tail;
        a_tail->next = pa_0->next;
    }
    if (!pb_0)
    {
        pa_0->next = pa_0;
        pa_0->prev = pa_0;
        *blst = pa_0;
    }
    else
    {
        b_tail = pb_0->prev;
        pa_0->next = pb_0;
        pa_0->prev = b_tail;
        pb_0->prev = pa_0;
        b_tail->next = pa_0;
        *blst = pa_0;
    }
}
static void t_dnode *pb(t_dnode **alst, t_dnode **blst)
{
    t_dnode *pa_0;
    t_dnode *pb_0;
    t_dnode *a_tail;
    t_dnode *b_tail;

    if (!*blst)
        return;
    pa_0 = *alst;
    pb_0 = *blst;
    if (pb_0->next == pb_0)
        *blst = NULL;
    else
    {
        b_tail = pb_0->prev;
        *blst = pb_0->next;
        (pb_0->next)->prev = b_tail;
        b_tail->next = pb_0->next;
    }
    if (!(pb_0))
    {
        pb_0->next = pb_0;
        pb_0->prev = pb_0;
        *alst = pb_0;
    }
    else
    {
        a_tail = pa_0->prev;
        pb_0->next = pa_0;
        pb_0->prev = a_tail;
        pa_0->prev = pb_0;
        a_tail->next = pb_0;
        *alst = pb_0;
    }
}










//////////////////////////////////////////////////////////
//                          OTHER THING THAT i WROTE /////
//////////////////////////////////////////////////////////
/*

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

char *(list of int...)
{
    // check
    // --- arguments are all int type
    // --- no argumements > INT_MAX
    // duplicated numbers



    return(A str of the instructons delmeted by \n)
}

// functons you need to implement

static someting t_list *sa(t_list **alst)
{
    ft_swap(alst);
    return;
}
static someting t_list *sb(t_list **blst)
{
    ft_swap(blst);
    return;
}


static t_list *ft_swap(something; probably, t_list **alst )
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

*/

// needs to return "Error" in case: argumentos que no son enteros, 
// --- argumentos superiores a un número entero, y/o encontrar números duplicados.

// if parameters aren't specifies then the program should: a) show nothing b)give contol back to user (eg exit program)

// ft_printf is permitido
// "exit is a function that terminates the program"