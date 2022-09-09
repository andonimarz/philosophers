/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:23:14 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:37 by amarzana         ###   ########.fr       */
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

/* void	ft_check_philo(t_philo *ph)
{
	long	time;

	if (ph->ph_nb == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("\033[31m" "%d 1 died\n", ph->time_to_die + 1);
	}
	if (ph->limit_time < ft_get_time())
	{
		if (ph->eats < ph->eats_nb || ph->eats_nb == -1)
		{
			time = ft_get_time() - ph->start;
			printf("\033[31m" "%ld %d died\n" "\033[0m", \
					time, ph->index);
			free (ph);
			exit(0);
		}
	}
} */

int	ft_check_loop(t_philo *ph, pthread_mutex_t *mutex)
{
	int		i;
	long	time;
	int		ph_done;

	ph_done = 0;
	while (1)
	{
		i = 0;
		while (i < ph[0].ph_nb)
		{
			if (ph[i].limit_time < ft_get_time())
			{
				if (ph[i].eats < ph[i].eats_nb || ph[i].eats_nb == -1)
				{
					pthread_mutex_lock(mutex);
					time = ft_get_time() - ph[i].start;
					printf("\033[31m" "%ld %d died %d\n" "\033[0m", \
							time, ph[i].index, ph[i].eats + 1);
					return (1);
				}
				else
				{
					if (++ph_done == ph[0].ph_nb)
					{
						pthread_mutex_lock(mutex);
						printf("All philos finished eating!\n");
						return (0);
					}
				}
			}
			i++;
		}
	}
	return (0);
}
