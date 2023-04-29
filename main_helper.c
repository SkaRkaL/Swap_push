/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:50:28 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/29 16:10:54 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max_element(t_list *stack)
{
	int		max;
	t_list	*tmp;

	max = stack->content;
	tmp = stack;
	while (tmp->next)
	{
		if (max < tmp->next->content)
		{
			max = tmp->next->content;
		}
		tmp = tmp->next;
	}
	while (stack)
	{
		if (stack->content == max)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_list	*min_elmt(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	min = a->content;
	while (tmp)
	{
		if (min > tmp->content)
		{
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	while (a)
	{
		if (a->content == min)
			return (a);
		a = a->next;
	}
	return (NULL);
}

int	__main_help(char ***c, t_list **stack_a, int *i)
{
	long	i_atoi;

	i_atoi = 0;
	while ((*c)[*i])
	{
		i_atoi = ft_atoi((*c)[(*i)++]);
		ft_lstadd_back(stack_a, ft_lstnew(i_atoi));
	}
	return (0);
}

void	sort_big(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	t_list	*tempe_head;

	*stack_b = NULL;
	tempe_head = ft_lstlast(*stack_a);
	if (tempe_head->next == NULL)
		tempe_head->next = *stack_a;
	__find_lis_head(stack_a, size);
	if (tempe_head->next == *stack_a)
		tempe_head->next = NULL;
	indx_stack(stack_a);
	push_flag0_b(stack_a, stack_b);
	i = ft_lstsize(*stack_b);
	while (i--)
	{
		moves_indx(stack_a, stack_b);
		push_b_to_a(stack_b, stack_a, get_best_move(*stack_b));
	}
	nrml_sort(stack_a, min_elmt(*stack_a), fun(*stack_a, min_elmt(*stack_a)));
}
