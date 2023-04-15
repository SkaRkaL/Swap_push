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

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (x);
}

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

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> content = content;
	new->indx = -1;
	new->flag = -1;
	new -> next = NULL;
	return (new);
}