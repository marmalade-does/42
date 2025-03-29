


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
