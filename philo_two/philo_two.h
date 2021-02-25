/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:27:54 by ichejra           #+#    #+#             */
/*   Updated: 2021/02/25 14:29:23 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>

# define EVENT_THINK	0
# define EVENT_SLEEP 	1
# define EVENT_FORK 	2
# define EVENT_EAT 		3
# define EVENT_DIE	 	4
# define EVENT_OVER 	5
# define FORK_SEM		"ForkSemaphore"
# define WRITE_SEM		"WriteSemaphore"
# define DEATH_SEM		"DeathSemaphore"
# define EAT_SEM		"EatSemaphore"

struct s_state;

typedef struct		s_philo
{
	int				position;
	int				is_eating;
	uint64_t		limit_to_die;
	uint64_t		last_eat;
	struct s_state	*state;
	sem_t			*semaphore;
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
	sem_t			*write_sem;
	sem_t			*death_sem;
	sem_t			*fork_sem;
}					t_state;

int					valid_args(int ac, char **av);
int					exit_error(char *str);
int					ft_free(t_state *state);
uint64_t			time_in_milliseconds(void);
int					ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					init_structs(t_state *state, int ac, char **av);
void				set_msg(t_philo *philo, int event);
void				put_forks(t_philo *philo);
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
char				*ft_itoa(int n);
#endif
