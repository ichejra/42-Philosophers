/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:03:03 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/22 10:03:16 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int	loop(char *av)
{
	int j;

	j = 0;
	while (av[j])
	{
		if (!ft_isdigit(av[j]))
		{
			printf("error: arguments value must be numbers only\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int			valid_args(int ac, char **av)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	if (ac < 5 || ac > 6)
	{
		printf("error: number of arguments is not valid\n");
		return (1);
	}
	while (++i < ac)
	{
		ret = loop(av[i]);
		if (ret == 1)
			return (1);
	}
	if (ft_atoi(av[1]) <= 1 || ft_atoi(av[1]) > 200 || ft_atoi(av[2]) <= 60 ||
		ft_atoi(av[3]) <= 60 || ft_atoi(av[4]) <= 60 || (ac == 6 &&
			ft_atoi(av[5]) <= 0))
	{
		printf("error: value of arguments is not valid\n");
		return (1);
	}
	return (0);
}
