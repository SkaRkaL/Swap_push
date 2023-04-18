/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:06 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/18 03:05:47 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*yes;

	if (!lst)
		return ;
	while (*lst)
	{
		yes = (*lst)->next;
		free(*lst);
		*lst = yes;
	}
	*lst = NULL;
}

void	is_sorted(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->next;
	while (stack_a->next)
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
	exit(write(1, "Already sorted\n", 16) && 0);
}

void	move_while(t_list **stack_a, t_list **stack_b, t_elm *elm)
{
	while (elm->second_tmp)
	{
		if (elm->b_tmp->content > elm->first_tmp->content \
			&& elm->b_tmp->content < elm->second_tmp->content)
		{
			elm->b_tmp->movs = 1 + up_or_down(elm->second_tmp->indx, \
				elm->b_tmp->indx, *stack_a, *stack_b);
			elm->b_tmp->place = elm->second_tmp;
			break ;
		}
		if (elm->b_tmp->content < elm->first_tmp->content \
			&& elm->b_tmp->content > ft_lstlast(elm->first_tmp)->content)
		{
			elm->b_tmp->movs = 1 + up_or_down(elm->first_tmp->indx, \
				elm->b_tmp->indx, *stack_a, *stack_b);
			elm->b_tmp->place = elm->first_tmp;
			break ;
		}
		elm->second_tmp = elm->second_tmp->next;
		elm->first_tmp = elm->first_tmp->next;
	}
}
