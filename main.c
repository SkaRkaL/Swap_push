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
			printf("%d", stack_a->content);
			// printf("------> %d",stack_a->flag);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			printf("\t%d", stack_b->content);
			// printf("------> %d",stack_b->flag);
			stack_b = stack_b->next;
		}
		size--;
		printf("\n");
	}
	printf("-\t-\na\tb\n");
	printf("------End-----\n");
}

// Check MAX & MIN f Stack
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
	// int cont[MAX_INT] = {0};

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
	printf("len -> %d\n", len);
	puts("----here-----");
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
	int ll = full_size;
	t_list *tmpe = *stack;
	while (ll)
	{
		if (tmpe->flag == 1)
			printf("from->  1        |%d|\n", tmpe->content);
		else
			printf("from-> 0 |%d|\n", tmpe->content);
		tmpe = tmpe->next;
		ll--;
	}
	return (ret);
}
// 9 21 8 32 20 49 40 60 70
// 1 1  0 1  0  1  0  1  1
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
	stack_a->size = i;
	t_list *tempe_head = ft_lstlast(stack_a);
	aff(stack_a, stack_b, stack_a->size);
	if (stack_a->size <= 3)
		sort_III(&stack_a);
	else if (stack_a->size <= 5)
		sort_V(&stack_a, &stack_b);
	else if (stack_a->size > 5)
	{
		if (tempe_head->next == NULL)
			tempe_head->next = stack_a;
		// make_head;
		t_list *head = __find_lis_head(&stack_a, stack_a->size);

		printf("\n\tMarkup Head -> |%d|\n\n", head->content);
		int tmp_size = stack_a->size;
		while (tmp_size)
		{
			if (head->flag == 1)
				printf(" |%d| . ", head->content);
			head = head->next;
			tmp_size--;
		}
		tmp_size = stack_a->size;
		puts("\n");
		// while (tmp_size)
		// {
		// 	tmp_size--;
		// }
		// for (i = 0; i < tmp_size; i++)
		// {
		// 	printf("%d :: %d \n", i, head->flag);
		// 	if (head->flag == 0)
		// 		pb(&stack_b, &stack_a, stack_a->size);
		// 	else if (head->flag == 1)
		// 		ra(&stack_a, stack_a->size);
		// 	printf("%d end\n", i);
		// 	aff(stack_a, stack_b, stack_a->size);
		// }
	}

	return 0;
}
