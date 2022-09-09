/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:32 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/09 18:58:01 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"
#include <stdio.h>
#include <unistd.h>

void	ft_eat(t_philo *philo)
{
	ft_print_action(1, philo);
	ft_sleep(philo->time_to_eat);
	philo->limit_time = ft_get_time() + philo->time_to_die;
	philo->eats++;
}

void	*ft_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	philo->limit_time = ft_get_time() + philo->time_to_die;
	if (philo->index % 2 == 1)
		usleep(philo->time_to_eat - 20);
	while (philo->eats < philo->eats_nb || philo->eats_nb == -1)
	{
		pthread_mutex_lock(philo->other_fork);
		ft_print_action(0, ph);
		pthread_mutex_lock(&philo->fork);
		ft_print_action(0, ph);
		ft_eat(ph);
		ft_print_action(2, ph);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->other_fork);
		ft_print_action(3, ph);
		ft_sleep(philo->time_to_sleep);
		ft_print_action(4, ph);
	}

	return (0);
}

int	main(int argc, char **argv)
{
	t_control		ctr;
	t_philo			*ph;
	pthread_mutex_t	mutex;
	int				i;

	ft_init_ctr(&ctr);
	ft_checks(argc, argv, &ctr);
	ft_get_args(argc, argv, &ctr);
	ph = ft_init_philo(ctr, mutex);
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < ctr.ph_nb)
	{
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_create(&ph[i].thread, NULL, &ft_routine, &ph[i]);
		pthread_detach(&ph[i].thread);
		i++;
	}
	if (ft_check_loop(ph, &mutex))
	{
		free(ph);
		exit(0);
	}
	i = 0;
	while (i < ctr.ph_nb)
	{
		pthread_join(ph[i].thread, NULL);
		pthread_mutex_destroy(&ph[i].fork);
		i++;
	}
	free (ph);
}
