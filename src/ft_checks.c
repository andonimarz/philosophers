/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:23:14 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/09 19:21:02 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

void	ft_check_arg_int(char **argv, t_control *control)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				control->error = 2;
			j++;
		}
		i++;
	}
}

void	ft_check_max_int(char **argv, t_control *control)
{
	int		i;
	long	num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		num = ft_philo_atoi(argv[i]);
		if (num < 0 || num > INT_MAX)
			control->error = 3;
		if (i == 1 && num == 0)
			control->error = 4;
		i++;
	}
}

void	ft_checks(int argc, char **argv, t_control *control)
{
	if (argc < 5 || argc > 6)
		control->error = 1;
	ft_check_arg_int(argv, control);
	ft_check_max_int(argv, control);
	ft_print_errors(control);
}

int	ft_check_loop(t_philo *ph)
{
	int		i;
	int		ph_done;

	ph_done = 0;
	while (1)
	{
		i = -1;
		while (++i < ph[0].ph_nb)
		{
			if (ph[i].limit_time < ft_get_time())
			{
				if (ph[i].eats < ph[i].eats_nb || ph[i].eats_nb == -1)
				{
					ft_print_action(6, &ph[i]);
					return (1);
				}
				else
				{
					if (++ph_done == ph[0].ph_nb)
						return (0);
				}
			}
		}
	}
	return (0);
}
