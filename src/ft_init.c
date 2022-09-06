/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:43:54 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/03 17:35:01 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"

void	ft_init_ctr(t_control *control)
{
	control->error = 0;
	control->ph_nb = 0;
	control->time_to_die = 0;
	control->time_to_eat = 0;
	control->time_to_sleep = 0;
	control->eats_nb = 0;
	control->start = ft_get_time();
}

t_philo	*ft_init_philo(t_control ctr)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * ctr.ph_nb);
	while (i < ctr.ph_nb)
	{
		philos[i].index = i + 1;
		if (philos[i].index == 1)
			philos[i].other_fork = &philos[ctr.ph_nb - 1].fork;
		else
			philos[i].other_fork = &philos[i - 1].fork;
		philos[i].mutex = &ctr.mutex;
		philos[i].ph_nb = ctr.ph_nb;
		philos[i].time_to_die = ctr.time_to_die;
		philos[i].time_to_eat = ctr.time_to_eat;
		philos[i].time_to_sleep = ctr.time_to_sleep;
		philos[i].eats_nb = ctr.eats_nb;
		philos[i].start = ctr.start;
		i++;
	}
	return (philos);
}

void	ft_get_args(int argc, char **argv, t_control *control)
{
	control->ph_nb = ft_philo_atoi(argv[1]);
	control->time_to_die = ft_philo_atoi(argv[2]);
	control->time_to_eat = ft_philo_atoi(argv[3]);
	control->time_to_sleep = ft_philo_atoi(argv[4]);
	if (argc == 6)
		control->eats_nb = ft_philo_atoi(argv[5]);
	else
		control->eats_nb = -1;
}
