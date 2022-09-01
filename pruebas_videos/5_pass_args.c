#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
pthread_mutex_t mutex;
typedef struct s_thrd
{
	int				*index;
	pthread_t		*threads;
	pthread_mutex_t	*mutex;
}					t_thrd;

void*	routine(void* arg)
{
	//sleep(1);
	pthread_mutex_lock(&mutex);
	int	index = *(int *)arg;
	printf("%d ", primes[index]);
	free(arg);
	pthread_mutex_unlock(&mutex);
	return (arg);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];
	int			i;
	t_thrd		thread;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 10; i++) {
		int* a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0) {
			perror("Failed to created thread");
		}
	}
	for (i = 0; i < 10; i++) {
		if (pthread_join(th[i], NULL) != 0) {
			perror("Failed to join thread");
		}
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
