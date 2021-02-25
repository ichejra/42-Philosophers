/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:56:19 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/25 14:20:01 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	*handle_death_event(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo*)v_philo;
	while (1)
	{
		if (sem_wait(philo->semaphore) < 0)
			break ;
		if (!philo->is_eating && philo->done != 1 &&
			(time_in_milliseconds() > philo->limit_to_die))
		{
			set_msg(philo, EVENT_DIE);
			sem_post(philo->semaphore);
			sem_post(philo->state->death_sem);
			break ;
		}
		if (sem_post(philo->semaphore))
			break ;
		usleep(1000);
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
		sem_wait(state->philo[j].eat_sem);
		j++;
		if (j == state->num_of_philo)
			break ;
	}
	set_msg(state->philo, EVENT_OVER);
	sem_post(state->death_sem);
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
			sem_post(philo->eat_sem);
			philo->done = 1;
			break ;
		}
	}
	return ((void*)0);
}

static int	create_count_thread(t_state *state)
{
	pthread_t	thid;

	if (state->must_eat_num > 0)
	{
		if (pthread_create(&thid, NULL, &track_count, (void*)state) != 0)
			return (1);
		pthread_detach(thid);
	}
	return (0);
}

int			start_processes(t_state *state)
{
	int			i;
	void		*philo;

	i = 0;
	if (create_count_thread(state))
		return (1);
	sem_wait(state->death_sem);
	state->start = time_in_milliseconds();
	while (i < state->num_of_philo)
	{
		philo = (void*)(&state->philo[i]);
		state->philo[i].pid = fork();
		if (state->philo[i].pid < 0)
			return (1);
		else if (state->philo[i].pid == 0)
		{
			routine(&state->philo[i]);
			exit(0);
		}
		usleep(100);
		i++;
	}
	sem_wait(state->death_sem);
	sem_post(state->death_sem);
	return (0);
}
