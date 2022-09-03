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

/*--------BORRAR----------*/
/*Borrar todo al terminar */
/*--------BORRAR----------*/
void	ft_print_ctr(t_control *control)
{
	printf ("Error = %d\n", control->error);
	printf ("ph_nb = %d\n", control->ph_nb);
	printf ("time_to_die = %d\n", control->time_to_die);
	printf ("time_to_eat = %d\n", control->time_to_eat);
	printf ("time_to_sleep = %d\n", control->time_to_sleep);
	printf ("eats_nb = %d\n", control->eats_nb);
}
/*--------BORRAR----------*/
/*--------BORRAR----------*/

void	*ft_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(philo->other_fork);
	printf("Philo %d has taken a fork\n", philo->index);
	pthread_mutex_lock(&philo->fork);
	printf("Philo %d has taken a fork\n", philo->index);
	printf("Philo %d job starts\n", philo->index);
	printf("start = %ld\n", philo->start);
	printf("Philo %d has left both forks\n", philo->index);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->other_fork);
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
	ft_print_ctr(&ctr);
	i = ctr.ph_nb;
	ph = ft_init_philo(ctr);
	i = 0;
	while (i < ctr.ph_nb)
	{
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_create(&ph[i].thread, NULL, &ft_routine, &ph[i]);
		pthread_detach(ph[i].thread);
		i++;
	}
	while (1)
	{
		i++;
	}
	free (ph);
}
