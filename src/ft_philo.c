/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:32 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/30 15:58:58 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_philo.h"
#include <stdio.h>

/*--------BORRAR----------*/
/*--------BORRAR----------*/
void	ft_print_ctr(t_control *control)
{
	printf ("Error = %d\n", control->error);
	printf ("philo_nb = %d\n", control->philo_nb);
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
	control->philo_nb = 0;
	control->time_to_die = 0;
	control->time_to_eat = 0;
	control->time_to_sleep = 0;
	control->eats_nb = 0;
}

void	ft_get_args(int argc, char **argv, t_control *control)
{
	control->philo_nb = ft_philo_atoi(argv[1]);
	control->time_to_die = ft_philo_atoi(argv[2]);
	control->time_to_eat = ft_philo_atoi(argv[3]);
	control->time_to_sleep = ft_philo_atoi(argv[4]);
	if (argc == 6)
		control->eats_nb = ft_philo_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_control	control;

	ft_init_ctr(&control);
	ft_checks(argc, argv, &control);
	ft_get_args(argc, argv, &control);
	ft_print_ctr(&control);
}
