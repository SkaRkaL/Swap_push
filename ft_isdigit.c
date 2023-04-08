#include "push_swap.h"

int	ft_isdigit(char *c)
{
	int i=0;
	if (!c)
		return 1;
	if (c[0] == '-' && c[1] == '\0')
		return 1;
	if (c[0] == '-')
		i++;
	while (c[i])
	{
		if (c[i] < 48 || c[i] > 57)
			return 1;
		i++;
	}
	return (0);
}
