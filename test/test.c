#include <stdio.h>
#include "push_swap.h"

int	ft_length(char **str, char *sep, int size)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += strlen(str[i]);
		i++;
	}
	l += strlen(sep) * (size - 1);
	return (l);
}

char	*ft_strcat(char *dest, char	*src)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (dest[count] != '\0')
		count++;
	while (src[i] != '\0')
	{
		dest[count + i] = src[i];
		i++;
	}
	dest[count + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (size <= 0)
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * ft_length(strs, sep, size) + 1);
	if (!str)
		return (str);
	str[i] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
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

int main(int ac, char **av)
{
	int j;
	int i = 0;
	char **c;

	if (ac > 1)
	{
		if (av[1][0] == '\0')
			return (write(2, "Error ! Empty String\n", 22));
		c = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
		while (c[i])
		{
			if (ft_isdigit(c[i]))
				return (write(2, "Error !", 8));
			i++;
		}
		i = 0;
		while (c[i])
		{
			j = i + 1;
			while (c[j])
			{
				if (!strcmp(c[i], c[j]))
					return(write(2, "Error !!", 9));
				j++;
			}
			i++;
		}
		i = 0;
		int k = 0;
		while (c[i])
		{
			k = atoi(c[i]);
			printf("%d ", k);
			i++;
		}

		

	}
	printf("\n");
}
