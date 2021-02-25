/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:27:53 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/23 10:22:33 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_free(t_state *state)
{
	int j;

	j = 0;
	if (state->fork_mutex)
	{
		while (j < state->num_of_philo)
			pthread_mutex_destroy(&state->fork_mutex[j++]);
		free(state->fork_mutex);
	}
	if (state->philo && state->num_of_philo)
	{
		j = 0;
		while (j < state->num_of_philo)
		{
			pthread_mutex_destroy(&state->philo[j].mutex);
			j++;
		}
		free(state->philo);
	}
	pthread_mutex_destroy(&state->write_mutex);
	pthread_mutex_destroy(&state->death_mutex);
	free(state);
	return (1);
}

int	exit_error(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
