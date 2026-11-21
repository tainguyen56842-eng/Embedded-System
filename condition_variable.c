#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define TOTAL_ITEMS 10

int buffer[BUFFER_SIZE];
int count  = 0;
int in_idx = 0;
int out_idx= 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond_not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t  cond_not_full  = PTHREAD_COND_INITIALIZER;
void *producer(void *arg){
	for(int item =1;item<= TOTAL_TIEMS;item++){
		usleep(150000);
		pthread_mutex_lock(&mutex);
		while(count == BUFFER_SIZE){
			printf(
