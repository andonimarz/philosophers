/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:25:43 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/30 14:31:16 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include "ft_control.h"
# include "libft.h"
//# include "ft_sleep.h"

void	ft_print_ctr(t_control *control);

void	ft_checks(int argc, char **argv, t_control *control);

#endif