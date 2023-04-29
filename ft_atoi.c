/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakarkal <sakarkal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:09:52 by sakarkal          #+#    #+#             */
/*   Updated: 2023/04/29 17:37:38 by sakarkal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
