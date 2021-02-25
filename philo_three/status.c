/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:02:24 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/22 12:25:49 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		eat(t_philo *philo)
{
	sem_wait(philo->semaphore);
	philo->is_eating = 1;
	philo->last_eat = time_in_milliseconds();
	philo->limit_to_die = philo->last_eat + philo->state->time_to_die;
	set_msg(philo, EVENT_EAT);
	usleep(philo->state->time_to_eat * 1000);
	philo->count_eat++;
	philo->is_eating = 0;
	sem_post(philo->semaphore);
}

void		take_forks(t_philo *philo)
{
	sem_wait(philo->state->fork_sem);
	set_msg(philo, EVENT_FORK);
	sem_wait(philo->state->fork_sem);
	set_msg(philo, EVENT_FORK);
}

void		put_forks(t_philo *philo)
{
	sem_post(philo->state->fork_sem);
	sem_post(philo->state->fork_sem);
	set_msg(philo, EVENT_SLEEP);
	usleep(philo->state->time_to_sleep * 1000);
	set_msg(philo, EVENT_THINK);
}
