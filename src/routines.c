/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:22:50 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/20 14:37:26 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, uint64_t timestamp)
{
	pthread_mutex_lock(&philo->args->forks[philo->fork_left]);
	print_state(philo, TOOK_FORK, timestamp);
	pthread_mutex_lock(&philo->args->forks[philo->fork_right]);
	print_state(philo, TOOK_FORK, timestamp);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->args->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->args->forks[philo->fork_right]);
}

void	philo_eat(t_philo *philo, uint64_t timestamp)
{
	print_state(philo, EATING, timestamp);
	philo->meals_eaten++;
	philo->last_ate = timestamp;
	usleep(philo->args->tt_eat * 1000);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, THINKING, get_time());
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, SLEEPING, get_time());
	usleep(philo->args->tt_sleep * 1000);
}
