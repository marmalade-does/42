#include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_swap(char **p_1, char **p_2);
void 		ft_bubble_sort(char **arr, int n);


int			main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		return(0);
	i = 1;
	
	ft_bubble_sort(&argv[1], argc - 1);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

void ft_bubble_sort(char **arr, int n)
{
    int i;
	int j;

	i == 0;
	while(i < n - 1)
	{
		j = 0;
		while(j < n - i - 1)
		{
			if(ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				ft_swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}
void		ft_swap(char **p_1, char **p_2)
{
	char	*temp;

	temp = *p_2; 
	*p_2 = *p_1; 
	*p_1 = temp;
}




void		ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}




int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void ft_putchar(char h)
{
	write(1, &h, 1);
}