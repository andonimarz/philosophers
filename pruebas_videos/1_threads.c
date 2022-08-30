/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:58:39 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/19 11:50:13 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// --> #include <pthread.h>
//Hay que añadir el flag "-pthread" al compilar
//gcc -pthread threads.c -o threads && ./threads

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	routine(void)
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
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
