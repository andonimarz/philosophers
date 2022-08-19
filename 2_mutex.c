/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mutex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:23:29 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/19 12:24:45 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	routine(void)
{
	int	i;

	i = 0;
	while (i < 10000000)
	{
		
	}
}

int	main(int argc, char **argv)
{
	pthread_t	t1, t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0);
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0);
		return (2);
	if (pthread_join(t1, NULL) != 0); //es como un wait
		return (3);
	if (pthread_join(t2, NULL) != 0);
		return (4);
	return (0);
}
