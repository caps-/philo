/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:50:27 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/27 13:05:31 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* This code should be pretty clear. Just initializing all the philosophers. The
 * fork_left and fork_right variables are for the forks avaliable to them. */
void	init_philosophers(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philos)
	{
		args->philo[i].id = i + 1;
		args->philo[i].fork_left = i;
		args->philo[i].fork_right = (i + 1) % args->number_of_philos;
		args->philo[i].last_ate = 0;
		args->philo[i].meals_eaten = 0;
		args->philo[i].args = args;
		args->philo[i].is_done = 0;
	}
}

/* Init arguuments, should be pretty self explanatory. */
void	init_args(t_args *args, char **argv)
{
	args->number_of_philos = ft_atoi(argv[1]);
	args->tt_die = ft_atoi(argv[2]);
	args->tt_eat = ft_atoi(argv[3]);
	args->tt_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->meals_required = ft_atoi(argv[5]);
	else
		args->meals_required = -1;
	args->is_running = 1;
}

void	init_mutex(t_args *args)
{
	int	i;

	args->philo = malloc(sizeof(t_philo) * args->number_of_philos);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->number_of_philos);
	i = -1;
	while (++i < args->number_of_philos)
		pthread_mutex_init(&args->forks[i], NULL);
	pthread_mutex_init(&args->write, NULL);
}

void	init_threads(t_args *args)
{
	int			i;
	pthread_t	lifecycle_id;

	i = -1;
	while (++i < args->number_of_philos)
		pthread_create(&args->philo[i].thread_id, NULL,
			&lifecycle, &args->philo[i]);
	pthread_create(&lifecycle_id, NULL, &lifecycle_checker, args);
	pthread_join(lifecycle_id, NULL);
}
