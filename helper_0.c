/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 03:12:14 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/18 03:16:18 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__find_lis_head(t_list **stack, int full_size)
{
	int		len;
	t_list	*ret;

	len = 0;
	ret = __return_help(full_size, stack);
	inddexing_flag(stack, ret, full_size);
}

void	indx_stack(t_list **stack)
{
	int		i;
	t_list	*tompo;

	i = 0;
	tompo = *stack;
	while (tompo)
	{
		tompo->indx = i;
		i++;
		tompo = tompo->next;
	}
}

t_list	*get_best_move(t_list *stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = stack_b;
	i = ft_lstsize(stack_b);
	stack_b->min_move = INT_MAX;
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
