#include "push_swap.h"

char	*ft_strdup(char *s1)
{
	int		len;
	int		j;
	char	*p;

	len = ft_strlen(s1);
	j = 0;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	while (j < len)
	{
		p[j] = s1[j];
		j++;
	}
	p[len] = '\0';
	return (p);
}
