/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:46 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 23:49:43 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_list **stack_a, int index)
{
	rotate(stack_a);
	if (index)
		write(1, "ra\n", 3);
	indx_stack(stack_a);
}

void	rb(t_list **stack_b, int index)
{
	rotate(stack_b);
	if (index)
		write(1, "rb\n", 3);
	indx_stack(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b, int index)
{
	rotate(stack_a);
	rotate(stack_b);
	if (index)
		write(1, "rr\n", 3);
	indx_stack(stack_a);
}
