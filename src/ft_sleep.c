/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:35:08 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/10 10:48:10 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_sleep.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(int ms)
{
	long	start_time;

	start_time = ft_get_time();
	while (ft_get_time() - start_time < ms)
		usleep(100);
}
