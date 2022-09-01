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

void	ft_init_ctr(t_control *control, t_thrd *th)
{
	control->error = 0;
	control->ph_nb = 0;
	control->time_to_die = 0;
	control->time_to_eat = 0;
	control->time_to_sleep = 0;
	control->eats_nb = 0;
	th->index = 0;
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

void	*ft_routine(void *th)
{
	int		aux;
	t_thrd	*thread;

	thread = (t_thrd *)th;
	pthread_mutex_lock(&thread->mutex[*thread->index]);
	aux = *thread->index;
	printf("Hilo %d\n", aux);
	free(thread->index);
	pthread_mutex_unlock(&thread->mutex[aux]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_control	ctr;
	t_thrd		th;
	int			i;
	int			j;

	ft_init_ctr(&ctr, &th);
	ft_checks(argc, argv, &ctr);
	ft_get_args(argc, argv, &ctr);
	ft_print_ctr(&ctr);
	i = ctr.ph_nb;
	th.threads = (pthread_t *)malloc(sizeof(pthread_t) * i);
	th.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * i);
	i = 0;
	while (i < ctr.ph_nb)
	{
		th.index = calloc(1, sizeof(int));
		*th.index = i;
		pthread_mutex_init(&th.mutex[i], NULL);
		pthread_create(&th.threads[i], NULL, &ft_routine, &th);
		//pthread_detach(th.threads[i]);
		i++;
	}
	j = 0;
	while (j < ctr.ph_nb)
	{
		pthread_join(th.threads[j], NULL);
		pthread_mutex_destroy(&th.mutex[j]);
		j++;
	}
	free (th.threads);
	free (th.mutex);
}
