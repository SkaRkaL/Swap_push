/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rvrse-rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:51 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/19 06:51:22 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	tmp = ft_beforelast((*stack));
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	indx_stack(stack_a);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	indx_stack(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	indx_stack(stack_a);
}
