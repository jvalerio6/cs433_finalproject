/*
 * File name: m_threadsort.c
 * Date Implemented: May 4th, 2016
 * Course: CS 433
 * Created: May 4th, 2016 - JV
 */

/****************************************************************************
HOW TO COMPILE/RUN PROGRAM:
	 - Compile:  gcc -Wall -lpthread m_threadsort.c -o m_threadsort
 	 - Run: ./m_threadsort <integer_list>
****************************************************************************/


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sched.h>

pthread_t tid[2];
pthread_mutex_t s_thread0, s_thread1, m_thread;
int numItems = 0;
int * integerArray;

void *sortSublist(void *arg) {

	return NULL;
}

void *mergeLists(void *arg) {

	return NULL;
}


/** PURPOSE: Main process creates shared memory region, initializes mutex semaphores, and creates the producer and consumer threads.
 			 There must be 3 arguments in order to start the program. The first argument is the program name, the second is <memsize> which
 			 determines the size of memory region, and the third argument <ntimes> indicates the number of times producer/consumer reads/writes memory region.
*/
int main(int argc, char *argv[]) {
	int err;


	if (argc < 2) {
		printf("Error: %s\n", "Invalid num of arguments");
		exit(1);
	}

	else {

		if(pthread_mutex_init(&s_thread0, NULL) != 0) {
			printf("\n error creating mutex\n");
		}

		if(pthread_mutex_init(&s_thread1, NULL) != 0) {
			printf("\n error creating mutex\n");
		}

		if(pthread_mutex_init(&m_thread, NULL) != 0) {
			printf("\n error creating mutex\n");
		}

		err = pthread_create(&(tid[0]), NULL, &sortSublist, NULL);

		if(err != 0) {
			printf("\ncan't create thread 1 :[%s]", strerror(err));
		}

		pthread_join(tid[0], NULL);
		pthread_join(tid[1], NULL);

		return 0;
	}
}
