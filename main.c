#include "push_swap.h"

int	ft_length(char **str, char *sep, int size)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += ft_strlen(str[i]);
		i++;
	}
	l += ft_strlen(sep) * (size - 1);
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

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
void aff(t_list *stack_a,t_list *stack_b)
{
	printf("------Start-----\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d",stack_a->content);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			printf("\t%d",stack_b->content);
			stack_b = stack_b->next;
		}
	printf("\n");
	}
	printf("-\t-\na\tb\n");
	printf("------End-----\n");
}
int main(int ac, char **av)
{
	int i = 0;
	int j;
	char **c;
	char *tmp;
	int k;

	int a = 0;
	if (ac > 1)
	{
		if (av[1][0] == '\0')
			return (write(2, "Error ! Empty String\n", 22));
		c = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
		while(c[i])
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
	}
	else 
		return (write(2, "Error Args !", 13));


	t_list *stack_a = NULL;
	t_list *stack_b = NULL;
	for (i = 0; c[i]; i++)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(c[i])));
	}


	aff(stack_a,stack_b);
	puts("Heeeere");
	sa(&stack_a, ft_lstsize(stack_a));
	aff(stack_a,stack_b);

	return 0;
}
