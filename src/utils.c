/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:50:02 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/27 14:46:53 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Gets the current time. */
int	get_time(void)
{
	static struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * (uint64_t)1000)
		+ (current_time.tv_usec / 1000));
}

/* Reimplementation of atoi(). */
int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		i = i * 10 + *str++ - '0';
	return (i);
}

/* Function to print error messages. */
void	print_error(char *errtype)
{
	printf(GREY);
	printf("\n----------------------------------------");
	printf("----------------------------------------");
	printf(RED_B "\nError: " RESET_B RED "%s\n" RESET, errtype);
	printf(GRN "\nUsage:\n");
	printf(CYN_B "./philo " RESET_B);
	printf(CYN "[number of philosophers] [tt_die] [tt_eat] [tt_sleep] ");
	printf(YEL "[number of meals]\n" RESET);
	printf(GREY);
	printf("----------------------------------------");
	printf("----------------------------------------\n");
	printf(RESET);
}

void	print_state(t_philo *philo, char *state, uint64_t timestamp)
{
	if (!philo->args->is_running)
		return ;
	pthread_mutex_lock(&philo->args->write);
	printf("%llu %d %s\n", timestamp, philo->id, state);
	pthread_mutex_unlock(&philo->args->write);
}
