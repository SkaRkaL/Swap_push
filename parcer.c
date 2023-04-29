/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:12:17 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/29 17:34:58 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	parc_int(char *str)
{
	long	a;
	int		x;

	x = 0;
	a = ft_atoi(str);
	while (str[x] == 48)
		x++;
	if (a > INT_MAX || a < INT_MIN)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	else if (ft_strlen(str + x) > ft_strlen("+2147483647"))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	check_dob(char **dob)
{
	int	a;	
	int	b;

	a = 0;
	while (dob[a])
	{
		b = a + 1;
		while (dob[b])
		{
			if (ft_atoi(dob[a]) == ft_atoi(dob[b]))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			b++;
		}
		a++;
	}
}

char	**_parcer(int ac, char **av)
{
	int		i;
	int		a;
	char	**c;

	i = -1;
	a = 0;
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
		while (c[a])
			parc_int(c[a++]);
		check_dob(c);
	}
	else
		exit(0);
	return (c);
}
