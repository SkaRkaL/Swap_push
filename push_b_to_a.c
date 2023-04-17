/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:29 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 21:12:30 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mymax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	it_is_two_up(t_list **stack_a, t_list **stack_b, t_list *bst_contnt)
{
	while ((*stack_a)->content != bst_contnt->place->content
		&& (*stack_b)->content != bst_contnt->content)
	{
		rr(stack_a, stack_b, 1);
	}
	while ((*stack_a)->content != bst_contnt->place->content)
		ra(stack_a, 1);
	while ((*stack_b)->content != bst_contnt->content)
		rb(stack_b, 1);
}

void	it_is_two_dwn(t_list **stack_a, t_list **stack_b, t_list *bst_contnt)
{
	while ((*stack_a)->content != bst_contnt->place->content
		&& (*stack_b)->content != bst_contnt->content)
	{
		rrr(stack_a, stack_b, 1);
	}
	while ((*stack_a)->content != bst_contnt->place->content)
		rra(stack_a, 1);
	while ((*stack_b)->content != bst_contnt->content)
		rrb(stack_b, 1);
}

void	it_is_up_dwn(t_list **stack_a, t_list **stack_b, t_list *bst_contnt)
{
	while ((*stack_a)->content != bst_contnt->place->content)
		ra(stack_a, 1);
	while ((*stack_b)->content != bst_contnt->content)
		rrb(stack_b, 1);
}

void	it_is_dwn_up(t_list **stack_a, t_list **stack_b, t_list *bst_contnt)
{
	while ((*stack_a)->content != bst_contnt->place->content)
		rra(stack_a, 1);
	while ((*stack_b)->content != bst_contnt->content)
		rb(stack_b, 1);
}
