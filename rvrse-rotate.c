/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rvrse-rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:51 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 23:50:22 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = ft_beforelast((*stack));
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
}

void	rra(t_list **stack_a, int index)
{
	reverse_rotate(stack_a);
	if (index)
		write(1, "rra\n", 4);
	indx_stack(stack_a);
}

void	rrb(t_list **stack_b, int index)
{
	reverse_rotate(stack_b);
	if (index)
		write(1, "rrb\n", 4);
	indx_stack(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b, int index)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (index)
		write(1, "rrr\n", 4);
	indx_stack(stack_a);
}
