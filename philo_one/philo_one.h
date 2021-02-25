/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:28:21 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/22 15:28:06 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define EVENT_THINK	0
# define EVENT_SLEEP 	1
# define EVENT_FORK 	2
# define EVENT_EAT 		3
# define EVENT_DIE	 	4
# define EVENT_OVER 	5

struct s_state;

typedef struct		s_philo
{
	int				position;
	int				is_eating;
	uint64_t		limit_to_die;
	uint64_t		last_eat;
	int				left_fork;
	int				right_fork;
	struct s_state	*state;
	pthread_mutex_t	mutex;
	int				count_eat;
	int				done;
}					t_philo;

typedef struct		s_state
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	t_philo			*philo;
	uint64_t		start;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*fork_mutex;

}					t_state;

int					exit_error(char *str);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
int					ft_strlen(const char *s);
void				set_msg(t_philo *philo, int event);
uint64_t			time_in_milliseconds(void);
int					init_structs(t_state *state, int ac, char **av);
void				eat(t_philo *philo);
void				take_forks(t_philo *philo);
void				put_forks(t_philo *philo);
int					ft_free(t_state *state);
int					valid_args(int ac, char **av);

#endif
