/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:11:50 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/18 02:58:16 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nrml_sort(t_list **stack_a, t_list *test, int a)
{
	while (1)
	{
		if ((*stack_a)->content == test -> content)
			break ;
		if (a == 0)
			rra(stack_a, ft_lstsize(*stack_a));
		if (a == 1)
			ra(stack_a, ft_lstsize(*stack_a));
	}
}

void	nrml_sort_b(t_list **stack_b, t_list *test, int a)
{
	while (1)
	{
		if ((*stack_b)->content == test->content)
			break ;
		if (a == 0)
			rrb(stack_b, ft_lstsize(*stack_b));
		if (a == 1)
			rb(stack_b, ft_lstsize(*stack_b));
	}
}

void	fun1(t_list **stack_a, t_list **stack_b, t_list *test, int a)
{
	nrml_sort(stack_a, test, a);
	pb(stack_b, stack_a, ft_lstsize(*stack_a));
}

int	fun(t_list *stack, t_list *elem)
{
	int		kk;
	int		size;
	t_list	*test;

	test = stack;
	size = ft_lstsize(stack);
	kk = 0;
	while (1)
	{
		if (elem->content == test->content)
			break ;
		test = test->next;
		kk++;
	}
	if (kk > size / 2)
		return (0);
	return (1);
}
