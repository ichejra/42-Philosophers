/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:12:08 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/20 11:06:00 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	init_philos(t_state *state)
{
	int i;

	i = 0;
	while (i < state->num_of_philo)
	{
		state->philo[i].is_eating = 0;
		state->philo[i].position = i;
		state->philo[i].right_fork = (i + 1) % state->num_of_philo;
		state->philo[i].left_fork = i;
		state->philo[i].count_eat = 0;
		state->philo[i].state = state;
		pthread_mutex_init(&state->philo[i].mutex, NULL);
		i++;
	}
}

int			init_structs(t_state *state, int ac, char **av)
{
	int i;

	i = 0;
	state->num_of_philo = ft_atoi(av[1]);
	state->time_to_die = ft_atoi(av[2]);
	state->time_to_eat = ft_atoi(av[3]);
	state->time_to_sleep = ft_atoi(av[4]);
	state->must_eat_num = (ac == 6) ? ft_atoi(av[5]) : 0;
	state->fork_mutex = NULL;
	state->philo = NULL;
	pthread_mutex_init(&state->write_mutex, NULL);
	pthread_mutex_init(&state->death_mutex, NULL);
	if (!(state->philo =
		(t_philo*)malloc(sizeof(t_philo) * (state->num_of_philo + 1))))
		return (1);
	state->philo->done = 0;
	init_philos(state);
	pthread_mutex_lock(&state->death_mutex);
	if (!(state->fork_mutex = (pthread_mutex_t*)
		malloc(sizeof(*(state->fork_mutex)) * state->num_of_philo)))
		return (1);
	while (i < state->num_of_philo)
		pthread_mutex_init(&state->fork_mutex[i++], NULL);
	return (0);
}
