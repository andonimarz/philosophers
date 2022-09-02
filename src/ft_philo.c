/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:32 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/01 17:29:15 by amarzana         ###   ########.fr       */
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

void	ft_init_ctr(t_control *control)
{
	control->error = 0;
	control->ph_nb = 0;
	control->time_to_die = 0;
	control->time_to_eat = 0;
	control->time_to_sleep = 0;
	control->eats_nb = 0;
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
		control->eats_nb = 0;
}

void	*ft_routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(&philo->mutex);
	printf("Hilo %d\n", philo->index);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_control	ctr;
	t_philo		*ph;
	int			i;
	int			j;

	ft_init_ctr(&ctr);
	ft_checks(argc, argv, &ctr);
	ft_get_args(argc, argv, &ctr);
	ft_print_ctr(&ctr);
	i = ctr.ph_nb;
	ph = (t_philo *)malloc(sizeof(t_philo) * i);
	i = 0;
	while (i < ctr.ph_nb)
	{
		ph[i].index = i;
		pthread_mutex_init(&ph[i].mutex, NULL);
		pthread_create(&ph[i].thread, NULL, &ft_routine, &ph[i]);
		i++;
	}
	j = 0;
	while (j < ctr.ph_nb)
	{
		//pthread_detach(ph.threads[i]);
		pthread_join(ph[j].thread, NULL);
		pthread_mutex_destroy(&ph[j].mutex);
		j++;
	}
	free (ph);
}
