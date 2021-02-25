/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:10:33 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/23 12:49:31 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static sem_t	*ft_init_sem(const char *name, unsigned int value)
{
	sem_t *ret;

	sem_unlink(name);
	ret = sem_open(name, O_CREAT, 0666, value);
	return (ret);
}

static void		init_philos(t_state *state)
{
	int		i;
	char	*sem_name;

	i = 0;
	sem_name = NULL;
	while (i < state->num_of_philo)
	{
		state->philo[i].is_eating = 0;
		state->philo[i].position = i;
		state->philo[i].count_eat = 0;
		state->philo[i].state = state;
		sem_name = ft_itoa(i + 1);
		state->philo[i].semaphore = ft_init_sem(sem_name, 1);
		free(sem_name);
		i++;
	}
}

int				init_structs(t_state *state, int ac, char **av)
{
	state->num_of_philo = ft_atoi(av[1]);
	state->time_to_die = ft_atoi(av[2]);
	state->time_to_eat = ft_atoi(av[3]);
	state->time_to_sleep = ft_atoi(av[4]);
	state->must_eat_num = (ac == 6) ? ft_atoi(av[5]) : 0;
	state->fork_sem = NULL;
	state->philo = NULL;
	if (!(state->philo =
		(t_philo*)malloc(sizeof(t_philo) * (state->num_of_philo + 1))))
		return (1);
	state->philo->done = 0;
	init_philos(state);
	if ((state->fork_sem = ft_init_sem(FORK_SEM, state->num_of_philo)) < 0)
		return (1);
	if ((state->write_sem = ft_init_sem(WRITE_SEM, 1)) < 0)
		return (1);
	if ((state->death_sem = ft_init_sem(DEATH_SEM, 1)) < 0)
		return (1);
	return (0);
}
