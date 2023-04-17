/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:57 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/17 23:52:15 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	min;

	if (ft_lstsize(*stack_a) == 3)
	{
		if (max_min_element(*stack_a, &min) == 1)
		{
			min_3(stack_a, min);
		}
		else if (max_min_element(*stack_a, &min) == 2)
		{
			min_1(stack_a, min);
		}
		else if (max_min_element(*stack_a, &min) == 3)
		{
			min_2(stack_a, min);
		}
	}
	else
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, ft_lstsize(*stack_a));
	}
}
