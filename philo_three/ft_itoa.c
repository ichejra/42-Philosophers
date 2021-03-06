/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:06:22 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/22 10:06:34 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static int		ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int		ft_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (nb == 0)
		return (0);
	return (nb * ft_power(nb, power - 1));
}

static int		ft_isnega(int *n, char *str, int *len)
{
	int		i;

	i = 0;
	if (*n == -2147483648)
	{
		str[i++] = '-';
		str[i++] = '2';
		*n = 147483648;
		*len = 8;
	}
	else if (*n < 0)
	{
		*n = *n * -1;
		str[i++] = '-';
		*len -= 1;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		len;
	int		p;
	int		res;

	i = 0;
	len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len--;
	i = ft_isnega(&n, str, &len);
	p = ft_power(10, len);
	while (p >= 1)
	{
		res = n / p;
		str[i] = res + 48;
		n = n - (res * p);
		p = p / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
