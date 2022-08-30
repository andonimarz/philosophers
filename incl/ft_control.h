/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:34 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/30 18:21:25 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTROL_H
# define FT_CONTROL_H

typedef struct s_control
{
	int	philo_nb;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eats_nb;
	int	error;
}					t_control;

/* typedef struct s_thrd
{
	pthread_t		*threads;
	pthread_mutex_t	mutex;
}					t_thrd; */

#endif