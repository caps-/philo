/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:31:12 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/27 12:52:28 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Includes */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* Colours to use for printf */
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define CYN  "\x1B[36m"

/* Bold colours for printf */
# define RED_B "\033[31;1m"
# define GREY "\033[30;1m"
# define CYN_B "\033[36;1m"

/* Reset colours */
# define RESET  "\x1B[0m"
# define RESET_B "\033[0m"

/* Error Messages */
# define ARG_TOOFEW "too few arguments."
# define ARG_TOOMNY	"too many arguments."
# define NOTNUMBERS "only use numbers please, no characters."

/* State messages */
# define TOOK_FORK "has taken a fork"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define DIED "died"

typedef struct s_args	t_args;

/* Philosophers */
typedef struct t_philo
{
	int			id;
	int			fork_left;
	int			fork_right;
	int			meals_eaten;
	int			is_done;
	uint64_t	last_ate;
	t_args		*args;
	pthread_t	thread_id;
}	t_philo;

/* Arguments that will be passed to the program. Forks = number of forks
 * on the table. */
typedef struct s_args
{
	int				number_of_philos;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals_required;
	int				is_running;
	int				done;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}	t_args;

/* Utils */
int		ft_atoi(const char *str);
int		get_time(void);
void	ft_useleep(long long time_to_sleep);
void	print_error(char *errtype);
void	print_state(t_philo *philo, char *state, uint64_t timestamp);

/* Argument checks */
int		args_are_valid(int argc, char **argv);
int		args_are_numbers(char **argv);

/* Initialize stuff */
void	init_args(t_args *args, char **argv);
void	init_philosophers(t_args *args);
void	init_mutex(t_args *args);
void	init_threads(t_args *args);

/* Thread stuff */
void	*lifecycle(void *l_args);
void	*lifecycle_checker(void *lc_args);

/* Routine stuff */
void	take_forks(t_philo *philo, uint64_t timestamp);
void	leave_forks(t_philo *philo);
void	philo_eat(t_philo *philo, uint64_t timestamp);
void	philo_think(t_philo *philo);
void	philo_sleep(t_philo *philo);

/* */
void	destroy_and_exit(t_args *args);

#endif
