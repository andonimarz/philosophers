/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:34 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/30 14:23:05 by amarzana         ###   ########.fr       */
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

#endif