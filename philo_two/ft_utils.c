/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:37:57 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/20 10:37:58 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

uint64_t	time_in_milliseconds(void)
{
	struct timeval tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

int			ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	n;
	long long	sign;

	i = 0;
	n = 0;
	sign = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (n * 10 + (long long)str[i] - '0' < n)
			return (sign == 1 ? 0 : -1);
		n = (n * 10) + ((long long)str[i++] - '0');
	}
	if (sign == 1)
		return ((int)-n);
	return ((int)n);
}

int			ft_isdigit(int c)
{
	unsigned int	c1;

	c1 = (unsigned int)c;
	if (c1 >= 48 && c1 <= 57)
		return (1);
	return (0);
}
