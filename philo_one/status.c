/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:14:17 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/20 10:51:11 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = time_in_milliseconds();
	philo->limit_to_die = philo->last_eat + philo->state->time_to_die;
	set_msg(philo, EVENT_EAT);
	usleep(philo->state->time_to_eat * 1000);
	philo->count_eat++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
}

void		take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->fork_mutex[philo->left_fork]);
	set_msg(philo, EVENT_FORK);
	pthread_mutex_lock(&philo->state->fork_mutex[philo->right_fork]);
	set_msg(philo, EVENT_FORK);
}

void		put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->state->fork_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->state->fork_mutex[philo->right_fork]);
	set_msg(philo, EVENT_SLEEP);
	usleep(philo->state->time_to_sleep * 1000);
	set_msg(philo, EVENT_THINK);
}
