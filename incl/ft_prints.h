/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:46:49 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/10 10:26:15 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTS_H
# define FT_PRINTS_H

# include "structs.h"
# include "ft_sleep.h"

/*----		ft_prints.c		----*/
void	ft_print_action(int mode, t_philo *philo);
void	ft_print_errors(t_control	*control);

#endif