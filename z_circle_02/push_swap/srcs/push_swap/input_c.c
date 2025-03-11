
// this file is to check if the input is well done or not hehe


typedef struct      s_dnode
{
    int            *content;
    struct s_dnode  *prev;
    struct s_dnode  *next;
}                   *t_dnode;

int     int_check(char *str); // Checks is the word passed is int || '-'  || '+',
int    extract_int(s_dnode **alst, char *str); // Takes out the the ints
int    dup_check(char **alst); // Checks that there are no duplicates

int main(int argc, char *argv[])
{
    // transfer them all to your doubly linked list.
    s_dnode **alst;
    s_dnode **blst;
    int i; 

    i = 1;
    if(argc < 2)   
    {
        ft_printf("Not enough arguments");
        return(1); // need to change the exit phrase later
    }
    while(i < argc)
    {
        if(!(int_check(argv[i])))
        {
            write(2, "Error\n", 6);
            return;
        }
        if(extract_int(alst, argv[i]))
            return;
        if(dup_check(alst))
        {
            write(2, "Error\n", 6);
            return;
        }
    }
    return (0);
}


// Need to double check some of the safety checks --- write a lot of pseudo-code 
int extract_int(s_dnode **alst, char *str)
{
    char **elems;
    int i;
    int flag;

    i = 0;
    flag = 0;
    elems == NULL;
    while(str[i] != '\0')
    {
        if(isspace(str[i]))
            flag = 1;
        if(flag && !(isspace(str[i])))
        {
            elems = ft_split(str);
            break;
        }
        i++;
    }
    if(elems != NULL)
    {
        i = 0;
        while(elems[i] != NULL)
        {
            if(!(extract_int(alst, elems[i])))
                return(1);
            i++;
        }
    }
    else //just extract the single number from the *str
    {
        // jest extract one word
    }
    if(!(int_check(str))
        return();
}

s_dnode *dnode_new(int num)
{
    s_dnode *new;

    new = malloc(sizeof(s_dnode));
    if(!new)
        return (NULL);
    new -> content = malloc(sizeof(int));
    if(!(new -> content))
    {
        free(new);
        return (NULL);
    }
    new -> prev = NULL
    new -> next = NULL
    *(new -> content) = num;
    return(new);
}

void addnode_front(s_dnode **alst, s_dnode *elem)
{
    s_dnode *p_0;
   
    if(elem == NULL)
        return;
    if(*alst == NULL)
    {
        elem -> next = elem;
        elem -> prev = elem;
    }
    else
    {
        p_0 = *alst;
        elem -> next = p_0;
        elem -> prev = p_0 -> prev;
        (elem -> prev) -> next = elem;
        (elem -> next) -> prev = elem;
    }
    (*alst) = elem;
}


int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}







