/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:47:29 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/19 07:15:17 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd(t_list **a, t_list **b, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b);
}

void	__check_op(char *op)
{
	if (ft_strcmp(op, "sa\n") && ft_strcmp(op, "sb\n")
		&& ft_strcmp(op, "ss\n") && ft_strcmp(op, "pa\n")
		&& ft_strcmp(op, "pb\n") && ft_strcmp(op, "ra\n")
		&& ft_strcmp(op, "rb\n") && ft_strcmp(op, "rr\n")
		&& ft_strcmp(op, "rra\n") && ft_strcmp(op, "rrb\n")
		&& ft_strcmp(op, "rrr\n"))
	{
		exit(write(1, "Error\n", 7));
	}
}

int	is_sorted(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->next;
	while (stack_a->next)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;
	char	**c;
	char	*buff;
	int		i;

	if (ac == 1)
		exit(0);
	c = _parcer(ac, av);
	if (c == NULL)
		return (check_isfree(c), write(2, "Error\n", 7));
	if (__main_help(&c, &a, &i))
		return (write(2, "Error\n", 7));
	buff = get_next_line(0);
	while (buff)
	{
		__check_op(buff);
		execute_cmd(&a, &b, buff);
		buff = get_next_line(0);
	}
	if (is_sorted(a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_lstclear(&a), 0);
}
