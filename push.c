/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:22 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/29 16:26:41 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_b, t_list **stack_a, int indx_a)
{
	t_list	*tmp;

	if (!indx_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
	indx_stack(stack_b);
	indx_stack(stack_a);
}

void	pa(t_list **stack_a, t_list **stack_b, int indx_b)
{
	t_list	*tmp;

	if (!indx_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
	indx_stack(stack_a);
	indx_stack(stack_b);
}
