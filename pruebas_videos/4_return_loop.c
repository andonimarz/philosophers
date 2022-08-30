/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_return_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:05:09 by amarzana          #+#    #+#             */
/*   Updated: 2022/08/22 17:18:29 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice()
{
	int	value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));

	*result = value;
	// printf("%d\n", value);
	printf("Thread result: %p\n", result);
	return ((void *) result);
}

int	main(int argc, char **argv)
{
	int			*res;
	pthread_t	th;

	srand(time(NULL));
	if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
		return (1);
	if (pthread_join(th, (void **) &res) != 0)
		return (2);
	printf("Main res: %p\n", res);
	printf("Result: %d\n", *res);
	free(res);
	return (0);
}