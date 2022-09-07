/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:32 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/07 17:55:50 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"
#include <stdio.h>
#include <unistd.h>

/*--------BORRAR----------*/
/*Borrar todo al terminar */
//
//	ft_check_deaths en ft_sleep o en el bucle del main
//	
//	ft_eat y ft_sleep
//
//	philo.mutex no funciona
//
/*--------BORRAR----------*/
/* void	ft_print_ctr(t_control *control)
{
	printf ("Error = %d\n", control->error);
	printf ("ph_nb = %d\n", control->ph_nb);
	printf ("time_to_die = %d\n", control->time_to_die);
	printf ("time_to_eat = %d\n", control->time_to_eat);
	printf ("time_to_sleep = %d\n", control->time_to_sleep);
	printf ("eats_nb = %d\n", control->eats_nb);
} */
/*--------BORRAR----------*/
/*--------BORRAR----------*/

long	ft_time(t_philo *philo)
{
	philo->time = ft_get_time() - philo->start;
	philo->limit_time = ft_get_time() + philo->time_to_die;
	return (philo->time);
}

void	ft_print_action(int mode, t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	if (mode == 0)
		printf("%ld %d has taken a fork\n", philo->time, philo->index);
	else if (mode == 1)
		printf("%ld %d is eating\n", philo->time, philo->index);
	else if (mode == 2)
		printf("%ld %d left both forks\n", philo->time, philo->index);
	else if (mode == 3)
		printf("%ld %d is sleeping\n", philo->time, philo->index);
	else if (mode == 4)
		printf("%ld %d is thinking\n", philo->time, philo->index);
	else if (mode == 5)
		printf("%ld %d died\n", philo->time, philo->index);
	pthread_mutex_unlock(philo->mutex);
}

void	*ft_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	ft_time(philo);
	if (philo->index % 2 == 1)
		usleep(philo->time_to_eat - 20);
	while (1)
	{
		pthread_mutex_lock(philo->other_fork);
		ft_print_action(0, ph);
		pthread_mutex_lock(&philo->fork);
		ft_print_action(0, ph);
		ft_print_action(1, ph);
		ft_sleep(philo->time_to_eat);
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
		i++;
	}
	ft_check_loop(ph, &mutex);
	i = 0;
	while (i < ctr.ph_nb)
	{
		pthread_join(ph[i].thread, NULL);
		pthread_mutex_destroy(&ph[i].fork);
		i++;
	}
	free (ph);
}
