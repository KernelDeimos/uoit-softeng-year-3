/*
	Implementation of example form L4 Slide 26
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> // Missing from example; defines atoi()

int sum;

void *runner(void *param);

int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	
	if (argc != 2) {
		printf("You did it wrong.\n");
		return -1;
	}
	
	int max_no = atoi(argv[1]);
	if (max_no < 0) {
		printf("Nice try!\n");
		return -1;
	}

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, runner, &max_no);

	pthread_join(tid, NULL);
	printf("sum = %d\n", sum);
}

void *runner(void *param)
{
	int i, upper = *((int *)param);
	sum = 0;
	for(i=1; i <= upper; i++)
		sum += i;
	pthread_exit(0);
}

