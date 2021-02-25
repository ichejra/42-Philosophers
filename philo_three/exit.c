/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:03:41 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/22 15:19:54 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	close_semaphores(t_state *state)
{
	sem_post(state->fork_sem);
	sem_close(state->fork_sem);
	sem_unlink(FORK_SEM);
	sem_post(state->philo->eat_sem);
	sem_close(state->philo->eat_sem);
	sem_unlink(EAT_SEM);
	sem_post(state->write_sem);
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
