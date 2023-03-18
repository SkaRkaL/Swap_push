#include "push_swap.h"

int	ft_isdigit(char *c)
{
	int i = -1;
	while (c[++i])
		if (c[i] < 48 || c[i] > 57)
			return 1;
	return (0);
}
// int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	return (0);
// }