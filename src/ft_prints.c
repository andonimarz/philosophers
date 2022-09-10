/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:46:26 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/10 10:53:02 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_prints.h"
#include "stdio.h"

void	ft_print_action(int mode, t_philo *philo)
{
	long	time;

	time = ft_get_time() - philo->start;
	pthread_mutex_lock(philo->mutex);
	if (mode == 0)
		printf("%ld %d has taken a fork\n", time, philo->index);
	else if (mode == 1)
		printf("%ld %d is eating\n", time, philo->index);
	else if (mode == 2)
		printf("%ld %d is sleeping\n", time, philo->index);
	else if (mode == 3)
		printf("%ld %d is thinking\n", time, philo->index);
	else if (mode == 4)
		printf("%ld %d died\n", time, philo->index);
	pthread_mutex_unlock(philo->mutex);
}

void	ft_print_errors(t_control	*control)
{
	if (control->error == 1)
		printf("Error\nInvalid arg number\n");
	else if (control->error == 2)
		printf("Error\nYou must write numeric args\n");
	else if (control->error == 3)
		printf("Error\nToo big / Negative num arg\n");
	else if (control->error == 4)
		printf("Error\nAt least one philosopher\n");
}
