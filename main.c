#include "push_swap.h"

void aff(t_list *stack_a, t_list *stack_b, int size)
{
	printf("------Start-----\n");
	while (size)
	{
		if (stack_a)
		{
			printf("%d| %d\t", stack_a->content, stack_a->indx);
			stack_a = stack_a->next;
		}
		else
		{
			printf("  |   \t");
		}
		if (stack_b)
		{
			printf("%d| %d", stack_b->content, stack_b->movs);
			stack_b = stack_b->next;
		}
		size--;
		printf("\n");
	}
	printf("-\t-\na\tb\n");
	printf("------End-----\n");
}

// int max_min_element(t_list *stack, int *ret_min)
// {
// 	int max;
// 	int min;
// 	int ret_max;
// 	int pos = 1;

// 	ret_max = 1;
// 	*ret_min = 1;
// 	max = stack->content;
// 	min = stack->content;
// 	while (stack->next)
// 	{
// 		pos++;
// 		if (max < stack->next->content)
// 		{
// 			max = stack->next->content;
// 			ret_max = pos;
// 		}
// 		if (min > stack->next->content)
// 		{
// 			min = stack->next->content;
// 			*ret_min = pos;
// 		}
// 		stack = stack->next;
// 	}
// 	return (ret_max);
// }

void is_sorted(t_list *stack_a)
{
	t_list *tmp;

	tmp = stack_a->next;
	while (stack_a->next)
	{
		tmp = stack_a->next;

		while (tmp)
		{
			if (stack_a->content > tmp->content)
				return;
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	exit(write(1, "Already Sorted :)\n", 19) & 0);
}

void	__find_lis_head(t_list **stack, int full_size)
{
	int		len;
	t_list	*ret;

	len = 0;
	ret = __return_help(full_size, stack);
	inddexing_flag(stack, ret, full_size);
}

void indx_stack(t_list **stack)
{
	t_list *tompo;
	tompo = *stack;
	int i = 0;
	while (tompo)
	{
		tompo->indx = i;
		i++;
		tompo = tompo->next;
	}
}

void fack_swap(t_list **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

t_list *get_best_move(t_list *stack_b)
{
	stack_b->min_move = INT_MAX;
	t_list *tmp = stack_b;
	int i = ft_lstsize(stack_b);
	while (i--)
	{
		if (tmp->movs < stack_b->min_move)
			stack_b->min_move = tmp->movs;
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->movs == stack_b->min_move)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list *min_element(t_list *a)
{
	int min = a->content;
	t_list *tmp = a;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	while (a)
	{
		if (a->content == min)
			return (a);
		a = a->next;
	}
	return (NULL);
}

t_list *max_element(t_list *stack)
{
	int max = stack->content;
	t_list *tmp = stack;
	while (tmp->next)
	{
		if (max < tmp->next->content)
		{
			max = tmp->next->content;
		}
		tmp = tmp->next;
	}
	while (stack)
	{
		if (stack->content == max)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
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
					return (write(2, "Error !!", 9));
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
	int size;
	size = i;
	is_sorted(stack_a);
	t_list *tempe_head = ft_lstlast(stack_a);
	if (size <= 3)
	{
		sort_III(&stack_a);
	}
	if (size > 3)
	{
		if (tempe_head->next == NULL)
			tempe_head->next = stack_a;
		__find_lis_head(&stack_a, size);
		if (tempe_head->next == stack_a)
			tempe_head->next = NULL;
		indx_stack(&stack_a);
		push_flag0_b(&stack_a, &stack_b);
		i = ft_lstsize(stack_b);
		while (i--)
		{
			moves_indx(&stack_a, &stack_b);
			push_b_to_a(&stack_b, &stack_a, get_best_move(stack_b));
		}
		mn_te7t_lfo9(&stack_a, min_element(stack_a), fun(stack_a, min_element(stack_a)));
		aff(stack_a, stack_b, ft_lstsize(stack_a));
	}
	return (0);
}
