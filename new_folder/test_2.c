#include <stdio.h>
#include <stdlib.h>

void	secondary_function(int i)
{
	if (i)
	{
		printf("thig will exit");
		exit(3);
	}
	printf("This is the secondary function.\n");
}
