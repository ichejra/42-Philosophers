/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:24:52 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/25 14:20:22 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void	*handle_death_event(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo*)v_philo;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && philo->done != 1 &&
			(time_in_milliseconds() > philo->limit_to_die))
		{
			set_msg(philo, EVENT_DIE);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->state->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
	return ((void*)0);
}

static void	*routine(void *v_philo)
{
	t_philo		*philo;
	pthread_t	thid;

	philo = (t_philo*)v_philo;
	philo->last_eat = time_in_milliseconds();
	philo->limit_to_die = philo->last_eat + philo->state->time_to_die;
	if (pthread_create(&thid, NULL, &handle_death_event, v_philo) != 0)
		return ((void*)1);
	pthread_detach(thid);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		if (philo->state->must_eat_num == philo->count_eat)
		{
			philo->done = 1;
			break ;
		}
	}
	return ((void*)0);
}

static void	*track_count(void *v_state)
{
	int		i;
	int		j;
	t_state *state;

	i = 0;
	j = 0;
	state = (t_state*)v_state;
	while (1)
	{
		if (state->philo[i].done)
		{
			i++;
			j++;
		}
		(i == state->num_of_philo) ? i = 0 : 0;
		if (j == state->num_of_philo)
			break ;
	}
	set_msg(state->philo, EVENT_OVER);
	pthread_mutex_unlock(&state->death_mutex);
	return ((void*)0);
}

static int	start_threads(t_state *state)
{
	int			i;
	pthread_t	thid;
	void		*philo;

	state->start = time_in_milliseconds();
	if (state->must_eat_num > 0)
	{
		if (pthread_create(&thid, NULL, &track_count, (void*)state) != 0)
			return (1);
		pthread_detach(thid);
	}
	i = 0;
	while (i < state->num_of_philo)
	{
		philo = (void*)(&state->philo[i]);
		if (pthread_create(&thid, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(thid);
		usleep(100);
		i++;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_state *state;

	if (valid_args(ac, av))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (init_structs(state, ac, av))
		return (ft_free(state) && exit_error("Error: Failure\n"));
	if (start_threads(state))
		return (ft_free(state) && exit_error("Error: Failure\n"));
	pthread_mutex_lock(&state->death_mutex);
	pthread_mutex_unlock(&state->death_mutex);
	ft_free(state);
	return (0);
}
