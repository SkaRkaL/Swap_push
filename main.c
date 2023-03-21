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

// Check MAX & MIN f Stack 
int	max_min_element(t_list *stack, int *ret_min)
{
	int max;
	int min;
	int	ret_max;

	ret_max = 1;
	*ret_min = 1;
	max = stack->content;
	min = stack->content;
	int pos = 1;
	while (stack->next)
	{
		pos++;
		if (max < stack->next->content)
		{
			max = stack->next->content;
			ret_max = pos;
		}
		if (min > stack->next->content)
		{
			min = stack->next->content;
			*ret_min = pos;
		}
		stack = stack->next;
	}
	return (ret_max);
}

void	is_sorted(t_list *stack_a)
{
	t_list	*tmp;
	// int cont[MAX_INT] = {0};

	tmp = stack_a->next;
	while(stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->content > tmp->content)
				return ;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	exit(write(1, "Already Sorted :)\n", 19) & 0);
}

int main(int ac, char **av)
{
	int i = 0;
	int j;
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
	}
	else 
		return (write(2, "Error Args !", 13));


	t_list *stack_a = NULL;
	t_list *stack_b = NULL;

	for (i = 0; c[i]; i++)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(atoi(c[i])));
	}
	is_sorted(stack_a);
	// aff(stack_a, stack_b);

	// Sort 5
	sort_V(&stack_a, &stack_b);
	
	// Sort 3
	sort_III(&stack_a);



	// aff(stack_a, stack_b);


	return 0;
}


