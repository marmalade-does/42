
#include <stdlib.h>
#include <stdio.h>


int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if(tab == NULL)
		return(NULL);
	i = 0;
	while (i < max - min)
	{
		tab[i] = min;
		i++;
	}
	return (tab);
}

/*
int main(void)
{
	int a = 10;
	int b = 20;
	int *arr;
	int i = 0;

	arr = ft_range(a, b);
	if(arr == NULL)
		return(0);
	while(arr[i] != b)
	{
		printf("%i ", arr[i]);
		i++;
	}
	return(0);
}
*/