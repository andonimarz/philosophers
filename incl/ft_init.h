/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:44:55 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/07 16:51:21 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INIT_H
# define FT_INIT_H

# include "ft_control.h"

/*----		ft_init.c		----*/
t_philo	*ft_init_philo(t_control ctr, pthread_mutex_t mutex);
void	ft_init_ctr(t_control *control);
void	ft_get_args(int argc, char **argv, t_control *control);

#endif