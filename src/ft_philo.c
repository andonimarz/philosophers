/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:32 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/10 10:52:06 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"
#include <stdio.h>
#include <unistd.h>

void	ft_eat(t_philo *philo)
{
	ft_print_action(1, philo);
	philo->limit_time = ft_get_time() + philo->time_to_die;
	philo->eats++;
	ft_sleep(philo->time_to_eat);
}

void	*ft_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	philo->limit_time = ft_get_time() + philo->time_to_die;
	if (philo->index % 2 == 0)
		usleep(philo->time_to_eat - 20);
	while (philo->eats < philo->eats_nb || philo->eats_nb == -1)
	{
		pthread_mutex_lock(philo->other_fork);
		ft_print_action(0, ph);
		pthread_mutex_lock(&philo->fork);
		ft_print_action(0, ph);
		ft_eat(ph);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->other_fork);
		ft_print_action(2, ph);
		ft_sleep(philo->time_to_sleep);
		ft_print_action(3, ph);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_control		ctr;
	t_philo			*ph;
	pthread_mutex_t	mutex;
	int				i;

	pthread_mutex_init(&mutex, NULL);
	ft_init_ctr(&ctr);
	ft_checks(argc, argv, &ctr);
	if (ctr.error == 0)
	{
		ft_get_args(argc, argv, &ctr);
		ph = ft_init_philo(ctr, mutex);
		i = 0;
		while (i < ctr.ph_nb)
		{
			pthread_mutex_init(&ph[i].fork, NULL);
			pthread_create(&ph[i].thread, NULL, &ft_routine, &ph[i]);
			pthread_detach(ph[i].thread);
			i++;
		}
		ft_check_loop(ph);
		free (ph);
	}
	return (0);
}
