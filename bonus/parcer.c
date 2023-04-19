/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:17 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/18 16:28:46 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	help(char **c)
{
	int	i;
	int	j;

	i = 0;
	while (c[i])
	{
		j = i + 1;
		while (c[j])
		{
			if (!ft_strcmp((char *)c[i], (char *)c[j]))
				exit(write(2, "Error\n", 7));
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_esp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	ft_empty(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[i][0])
			return (0);
		if (!ft_check_esp(av[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**_parcer(int ac, char **av)
{
	int		i;
	char	**c;

	i = -1;
	if (ac > 1)
	{
		if (!ft_empty(av))
			exit(write(2, "Error\n", 7));
		if (av[1][0] == '\0')
			exit(write(2, "Error\n", 7));
		c = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
		while (c[++i])
			if (ft_isdigit(c[i]))
				exit(write(2, "Error\n", 7));
		if (help(c))
			return (NULL);
	}
	else
		exit(0);
	return (c);
}
