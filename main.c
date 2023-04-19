/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:10 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/19 07:09:13 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**c;
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
