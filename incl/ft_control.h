/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:34 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/03 17:26:34 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTROL_H
# define FT_CONTROL_H

# include <pthread.h>
# include <stdlib.h>

typedef struct s_control
{
	pthread_mutex_t	mutex;
	int				ph_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eats_nb;
	int				error;
	long			start;
}					t_control;

typedef struct s_philo
{
	int				index;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*other_fork;
	pthread_mutex_t	*mutex;
	int				ph_nb;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eats_nb;
	long			start;
	long			time;
}					t_philo;

#endif