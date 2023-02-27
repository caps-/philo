/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:46:22 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/21 13:01:39 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (args_are_valid(argc, argv))
	{
		init_args(&args, argv);
		init_mutex(&args);
		init_philosophers(&args);
		init_threads(&args);
		destroy_and_exit(&args);
	}
}
