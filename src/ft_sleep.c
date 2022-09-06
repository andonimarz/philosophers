/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:35:08 by amarzana          #+#    #+#             */
/*   Updated: 2022/09/03 17:27:37 by amarzana         ###   ########.fr       */
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

/* int	main(void)
{
	int		repeats;
	int		sleep_time;
	long	start;

	repeats = 1000;
	sleep_time = 410;
	start = get_time();
	printf("Initial time:	%ld\n", start);
	while (repeats-- > 0)
	{
		ft_sleep(sleep_time);
		printf("After time:	%ld\n", (get_time() - start));
	}
	return (0);
} */
