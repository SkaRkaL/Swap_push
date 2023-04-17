/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:02 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 23:38:10 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_stack(int full_size, t_list *indexing)
{
	int	mark;
	int	tmp;

	tmp = full_size;
	mark = indexing->content;
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

void	inddexing_flag(t_list **stack, t_list *ret, int full_size)
{
	t_list	*indexing;
	int		lenght;

	indexing = *stack;
	lenght = full_size;
	while (lenght)
	{
		if (indexing->content == ret->content)
		{
			indexing->flag = 1;
			break ;
		}
		indexing = indexing->next;
		lenght--;
	}
	flag_stack(full_size, indexing);
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
