#include "push_swap.h"

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
