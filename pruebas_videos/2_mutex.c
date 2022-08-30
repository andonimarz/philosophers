/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_mutex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:23:29 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/22 12:52:40 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void*	routine()
{
	int		i;
	void	*q;

	i = 0;
	while (i++ < 10000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (q);
}

int	main(int argc, char **argv)
{
	pthread_t	p1;
	pthread_t	p2;
	pthread_t	p3;
	pthread_t	p4;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return (2);
	if (pthread_create(&p3, NULL, &routine, NULL) != 0)
		return (3);
	if (pthread_create(&p4, NULL, &routine, NULL) != 0)
		return (4);
	if (pthread_join(p1, NULL) != 0)
		return (5);
	if (pthread_join(p2, NULL) != 0)
		return (6);
	if (pthread_join(p3, NULL) != 0)
		return (7);
	if (pthread_join(p4, NULL) != 0)
		return (8);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
