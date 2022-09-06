/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:32 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/03 17:34:51 by amarzana         ###   ########.fr       */
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
	return (philo->time);
}

void	ft_print_action(int mode, t_philo *philo)
{
	//pthread_mutex_lock(philo->mutex);
	if (mode == 0)
		printf("%ld Philo %d has taken a fork\n", ft_time(philo), philo->index);
	else if (mode == 1)
		printf("%ld Philo %d started eating\n", ft_time(philo), philo->index);
	else if (mode == 2)
		printf("%ld Philo %d left both forks\n", ft_time(philo), philo->index);
	else if (mode == 3)
		printf("%ld Philo %d started sleeping\n", ft_time(philo), philo->index);
	else if (mode == 4)
		printf("%ld Philo %d is thinking\n", ft_time(philo), philo->index);
	//pthread_mutex_unlock(philo->mutex);
}

void	*ft_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->index % 2 == 1 )
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
	t_control	ctr;
	t_philo		*ph;
	int			i;

	ft_init_ctr(&ctr);
	ft_checks(argc, argv, &ctr);
	ft_get_args(argc, argv, &ctr);
	i = ctr.ph_nb;
	ph = ft_init_philo(ctr);
	i = 0;
	pthread_mutex_init(&ctr.mutex, NULL);
	while (i < ctr.ph_nb)
	{
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_create(&ph[i].thread, NULL, &ft_routine, &ph[i]);
		//pthread_detach(ph[i].thread);
		i++;
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
