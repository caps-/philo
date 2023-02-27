/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:18:34 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/20 16:47:38 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* if it's fucked change return (0) to null. */
void	*lifecycle(void *l_args)
{
	t_philo	*philo;

	philo = (t_philo *)l_args;
	philo->last_ate = get_time();
	if (philo->id % 2 == 0)
	{
		philo_think(philo);
		usleep(philo->args->tt_eat * 0.25 * 1000);
	}
	while (philo->args->is_running)
	{
		take_forks(philo, get_time());
		philo_eat(philo, get_time());
		leave_forks(philo);
		philo_think(philo);
		if (philo->meals_eaten == philo->args->meals_required)
		{
			philo->is_done = 1;
			philo->args->done++;
			break ;
		}
		philo_sleep(philo);
	}
	return (0);
}

/* while(1) = an infiniate loop. */
void	*lifecycle_checker(void *lc_args)
{
	int			i;
	t_args		*args;
	uint64_t	timestamp;

	i = 0;
	args = (t_args *)lc_args;
	while (1)
	{
		if (args->done == args->number_of_philos)
			break ;
		if (i == args->number_of_philos)
			i = 0;
		usleep(1000);
		timestamp = get_time();
		if (!args->philo[i].is_done
			&& (int)(timestamp - args->philo[i].last_ate) > args->tt_die)
		{
			print_state(&args->philo[i], DIED, get_time());
			args->is_running = 0;
			break ;
		}
		i++;
	}
	return (0);
}
