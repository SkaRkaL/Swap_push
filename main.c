#include "push_swap.h"

int main(int ac, char **av)
{
	int i = 0;
	char **c = ft_split(av[1], ' ');
	if (ac > 1)
	{
		if (av[1])
		{
			c = ft_split(av[1], ' ');
			while (av[1][i])
			{
				printf("%s", c);
				i++;
			}
			
		}
	}
	return 0;
}
