/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:48:12 by pwhittin          #+#    #+#             */
/*   Updated: 2023/02/21 13:20:12 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char n)
{
	if (n >= '0' && n <= '9')
		return (0);
	else
		return (1);
}

int	string_is_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

int	args_are_numbers(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (string_is_numbers(argv[i]))
			;
		else
		{
			print_error(NOTNUMBERS);
			exit (1);
		}
	}
	return (0);
}

int	right_ammount_of_args(int argc)
{
	if (argc < 5)
	{
		print_error(ARG_TOOFEW);
		exit (1);
	}
	else if (argc > 6)
	{
		print_error(ARG_TOOMNY);
		exit (1);
	}
	else
		return (0);
}

int	args_are_valid(int argc, char **argv)
{
	if (right_ammount_of_args(argc) && args_are_numbers(argv))
		return (0);
	else
		return (1);
}
