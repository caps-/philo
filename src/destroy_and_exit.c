/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:55:05 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/20 15:00:16 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_threads(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->number_of_philos)
		pthread_detach(args->philo[i].thread_id);
}

void	destroy_and_exit(t_args *args)
{
	int	i;

	i = -1;
	destroy_threads(args);
	while (++i < args->number_of_philos)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->write);
	free(args->philo);
	free(args->forks);
}
