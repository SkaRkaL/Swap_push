/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:10 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/18 03:06:29 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__find_lis_head(t_list **stack, int full_size)
{
	int		len;
	t_list	*ret;

	len = 0;
	ret = __return_help(full_size, stack);
	inddexing_flag(stack, ret, full_size);
}

void	indx_stack(t_list **stack)
{
	int		i;
	t_list	*tompo;

	i = 0;
	tompo = *stack;
	while (tompo)
	{
		tompo->indx = i;
		i++;
		tompo = tompo->next;
	}
}

t_list	*get_best_move(t_list *stack_b)
{
	t_list	*tmp;
	int		i;

	tmp = stack_b;
	i = ft_lstsize(stack_b);
	stack_b->min_move = INT_MAX;
	while (i--)
	{
		if (tmp->movs < stack_b->min_move)
			stack_b->min_move = tmp->movs;
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->movs == stack_b->min_move)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	char	**c;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	c = _parcer(ac, av);
	if (c == NULL)
		return (check_isfree(c), write(2, "Error\n", 7));
	if (__main_help(&c, &stack_a, &i))
		return (write(2, "Error\n", 7));
	is_sorted(stack_a);
	if (i <= 3)
		sort_3(&stack_a);
	if (i > 3)
		sort_big(&stack_a, &stack_b, i);
	check_isfree(c);
	ft_lstclear(&stack_a);
	return (0);
}
