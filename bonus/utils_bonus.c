/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:00:19 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/29 17:31:41 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__main_help(char ***c, t_list **stack_a, int *i)
{
	long	i_atoi;

	i_atoi = 0;
	*i = 0;
	while ((*c)[*i])
	{
		i_atoi = ft_atoi((*c)[(*i)++]);
		if (i_atoi > INT_MAX || i_atoi < INT_MIN)
		{
			check_isfree(*c);
			return (1);
		}
		ft_lstadd_back(stack_a, ft_lstnew(i_atoi));
	}
	return (0);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*yes;

	if (!lst)
		return ;
	while (*lst)
	{
		yes = (*lst)->next;
		free(*lst);
		*lst = yes;
	}
	*lst = NULL;
}

long	ft_atoi(const char *str)
{
	int		i;
	long	signe;
	long	resu;

	i = 0;
	signe = 1;
	resu = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resu = resu * 10 + (str[i] - 48);
		i++;
	}
	return (resu * signe);
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (1);
	if (c[0] == '-' && c[1] == '\0')
		return (1);
	if (c[0] == '+' && c[1] == '\0')
		return (1);
	if (c[0] == '-' || c[0] == '+')
		i++;
	while (c[i])
	{
		if (c[i] < 48 || c[i] > 57)
			return (1);
		i++;
	}
	return (0);
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
