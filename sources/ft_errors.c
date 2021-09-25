/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:17:27 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/25 12:11:41 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_print(void)
{
	write(2, "Error\n", 6);
	return (42);
}

static int	ft_checkint(char *nb)
{
	char	*int_extremum;
	int		i;

	i = 0;
	if (nb[0] == '-')
	{
		int_extremum = "-2147483648";
		i = 1;
	}
	else
		int_extremum = "2147483647";
	if (ft_strlen(nb) >= ft_strlen(int_extremum))
	{
		while (nb[i])
		{
			if (nb[i] > int_extremum[i] || !ft_isdigit(nb[i]))
				return (1);
			++i;
		}
		return (0);
	}
	else
		return (0);
}

static int	ft_in_lst(char *str, char **list)
{
	while (*list)
	{
		if (ft_atoi(str) == ft_atoi(*list))
			return (1);
		++list;
	}
	return (0);
}

int	ft_error(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		return (42);
	i = 0;
	while (++i < argc)
	{
		if (!ft_strncmp("-", argv[i], 2) || ft_strlen(argv[i]) < 1)
			return (ft_print());
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) && (argv[i][j] != '-' || j != 0))
				return (ft_print());
		}
		if (ft_checkint(argv[i]) || ft_in_lst(argv[i], argv + i + 1))
			return (ft_print());
	}
	return (0);
}
