#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int	i;

	if (!s)
		return (NULL);
	if (!len || start >= ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s) - start ;
	if (i > len)
	i = len;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, i + 1);
	return (str);
}