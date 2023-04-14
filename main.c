#include "push_swap.h"

int ft_length(char **str, char *sep, int size)
{
	int i;
	int l;

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

char *ft_strcat(char *dest, char *src)
{
	int i;
	int count;

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

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *str;
	int i;

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

int ft_lstsize(t_list *lst)
{
	int size;
	int num;

	if (!lst)
		return (0);
	size = 0;
	num = lst->content;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
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

int max_min_element(t_list *stack, int *ret_min)
{
	int max;
	int min;
	int ret_max;

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

t_list *__find_lis_head(t_list **stack, int full_size)
{
	int len = 0;
	int size = full_size;
	t_list *head = (*stack);
	t_list *ret;
	if (!head)
		return NULL;
	int tmp_size = size;
	while (size)
	{
		int count = 1;

		int t_ze = tmp_size;
		t_list *head_tmp = head;

		t_list *tmp = head->next;
		while (t_ze)
		{
			if (head_tmp->content < tmp->content)
			{
				head_tmp = tmp;
				count++;
			}
			tmp = tmp->next;
			t_ze--;
		}
		int h = t_ze;
		if (h)
		{
			tmp = (*stack);
			while (h > 0)
			{
				if (head_tmp->content < tmp->content)
				{
					head_tmp = tmp;
					count++;
				}
				tmp = tmp->next;
				h--;
			}
		}

		if (count >= len)
		{
			len = count;
			ret = head;
		}
		head = head->next;
		size--;
	}
	t_list *indexing = *stack;
	int lenght = full_size;
	int tmp = full_size;
	while (lenght)
	{
		if (indexing->content == ret->content)
		{
			indexing->flag = 1;
			break;
		}
		indexing = indexing->next;
		lenght--;
	}
	int mark = indexing->content;
	while (tmp)
	{
		if (indexing->content >= mark)
		{
			indexing->flag = 1;
			mark = indexing->content;
		}
		else
			indexing->flag = 0;
		tmp--;
		indexing = indexing->next;
	}
	return (ret);
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
	else if (size <= 5)
	{
		sort_V(&stack_a, &stack_b);
	}
	else if (size > 5)
	{
		if (tempe_head->next == NULL)
			tempe_head->next = stack_a;
		__find_lis_head(&stack_a, size);
		if (tempe_head->next == stack_a)
			tempe_head->next = NULL;
		indx_stack(&stack_a);
		t_list *tempo = NULL;
		tempo = stack_a;
		int flag_size = 0;
		while (tempo)
		{
			if (tempo->flag == 0)
				flag_size++;
			tempo = tempo->next;
		}
		push_flag0_b(&stack_a, &stack_b);
		t_list *b = stack_b;
		i = ft_lstsize(b);
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
