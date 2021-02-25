/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:41:07 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/23 12:48:27 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void	close_semaphores(t_state *state)
{
	sem_close(state->write_sem);
	sem_unlink(WRITE_SEM);
	sem_close(state->death_sem);
	sem_unlink(DEATH_SEM);
}

int			ft_free(t_state *state)
{
	int		j;
	char	*sem_name;

	sem_name = NULL;
	sem_post(state->fork_sem);
	sem_close(state->fork_sem);
	sem_unlink(FORK_SEM);
	if (state->philo)
	{
		j = 0;
		while (j < state->num_of_philo)
		{
			sem_name = ft_itoa(j + 1);
			sem_post(state->philo[j].semaphore);
			sem_close(state->philo[j].semaphore);
			sem_unlink(sem_name);
			free(sem_name);
			j++;
		}
		close_semaphores(state);
		free(state->philo);
	}
	free(state);
	return (1);
}

int			exit_error(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
