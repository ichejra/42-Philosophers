/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:56:33 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/23 10:13:06 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			main(int ac, char **av)
{
	int		i;
	t_state *state;

	i = 0;
	if (valid_args(ac, av))
		return (1);
	state = (t_state *)malloc(sizeof(t_state));
	if (init_structs(state, ac, av))
		return (ft_free(state) && exit_error("Error: Failure\n"));
	if (start_processes(state))
		return (ft_free(state) && exit_error("Error: Failure\n"));
	while (i < state->num_of_philo)
		kill(state->philo[i++].pid, SIGKILL);
	ft_free(state);
	return (0);
}
