/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:35:06 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/23 12:46:03 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static char	*get_msg(int event)
{
	if (event == EVENT_EAT)
		return (" is eating\n");
	else if (event == EVENT_SLEEP)
		return (" is sleeping\n");
	else if (event == EVENT_FORK)
		return (" has taken a fork\n");
	else if (event == EVENT_THINK)
		return (" is thinking\n");
	else if (event == EVENT_OVER)
		return ("must eat count reached\n");
	return (" died\n");
}

void		set_msg(t_philo *philo, int event)
{
	static int	done = 0;
	uint64_t	timestamp;

	timestamp = time_in_milliseconds() - philo->state->start;
	sem_wait(philo->state->write_sem);
	if (done == 0)
	{
		printf("%lld\t", timestamp);
		if (event != EVENT_OVER)
			printf("%d ", philo->position + 1);
		if (event == EVENT_OVER || event == EVENT_DIE)
			done = 1;
		printf("%s", get_msg(event));
	}
	// if (event != EVENT_DIE)
	sem_post(philo->state->write_sem);
}
