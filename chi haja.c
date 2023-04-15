#include "push_swap.h"

int	ft_while(t_list *stack, int size, int count)
{
	int	t_sz;
	t_list	*tmp1;
	t_list	*tmp2;

	count = 1;
	t_sz = size;
	tmp1 = stack;
	tmp2 = stack->next;
	while (t_sz)
	{
		if (tmp1->content < tmp2->content)
		{
			tmp1 = tmp2;
			count++;
		}
		tmp2 = tmp2->next;
		t_sz--;
	}
	return (t_sz);
}

void	inddexing_flag(t_list **stack, t_list *ret, int full_size)
{
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
}

void	helpp(int h, t_list **stack, t_list *head, int count)
{
	t_list	*tmp;
	tmp = (*stack);
	while (h > 0)
	{
		if (head->content < tmp->content)
		{
			head = tmp;
			count++;
		}
		tmp = tmp->next;
		h--;
	}
}

t_list	*full_helper(t_list	*ret, t_list **stack, int size, int len)
{
	t_list	*head;
	int		tmp_size;
	int		h;
	int		count;

	tmp_size = size;
	head = (*stack);
	if (!head)
		return (NULL);
	while (size)
	{

		count = 1;
		h = ft_while(head, tmp_size, count);
		if (h)
			helpp(h, stack, head, count);
		if (count >= len)
		{
			len = count;
			ret = head;
		}
		head = head->next;
		size--;
	}
	return (ret);
}

t_list	*__return_help(int size, t_list **stack)
{
	int		len;
	t_list	*ret;
	int		tmp_size;

	len = 0;
	ret = NULL;
	tmp_size = size;
	return (full_helper(ret, stack, size, len));
}
