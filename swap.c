/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:13:01 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 23:52:39 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	sa(t_list **stack, int index)
{
	swap(stack);
	if (index)
		write(1, "sa\n", 3);
	indx_stack(stack);
}

void	sb(t_list **stack, int index)
{
	swap(stack);
	if (index)
		write(1, "sb\n", 3);
	indx_stack(stack);
}

void	ss(t_list **stack_a, t_list **stack_b, int index)
{
	swap(stack_a);
	swap(stack_b);
	if (index)
		write(1, "ss\n", 3);
}
