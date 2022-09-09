/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:57 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/09 19:22:01 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKS_H
# define FT_CHECKS_H

# include "structs.h"
# include "ft_prints.h"

/*----		ft_checks.c		----*/
void	ft_checks(int argc, char **argv, t_control *control);
int		ft_check_loop(t_philo *ph);

#endif
