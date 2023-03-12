#include "push_swap.h"

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*p;

	len = ft_strlen(s1);
	i = 0;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[len] = '\0';
	return (p);
}
