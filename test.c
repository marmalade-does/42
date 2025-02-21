#include <unistd.h>

int	main(void)
{
	char c = 'c';
	write(1, &c, 1);
	return (0);
}
