/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:54 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 21:12:55 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_3(t_list **stack_a, int min)
{
	if (min == 3)
	{
		sa(stack_a, ft_lstsize(*stack_a));
		rra(stack_a, ft_lstsize(*stack_a));
	}
	else
	{
		ra(stack_a, ft_lstsize(*stack_a));
	}
}

void	min_1(t_list **stack_a, int min)
{
	if (min == 1)
	{
		sa(stack_a, ft_lstsize(*stack_a));
		ra(stack_a, ft_lstsize(*stack_a));
	}
	else
		rra(stack_a, ft_lstsize(*stack_a));
}

void	min_2(t_list **stack_a, int min)
{
	if (min == 2)
		sa(stack_a, ft_lstsize(*stack_a));
}
