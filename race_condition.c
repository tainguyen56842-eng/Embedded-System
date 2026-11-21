#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define ITERATIONS 2000
#define NUMBER_THREAD 5
long long share_count = 0;
void *mythread(void *arg){
	long long count_local = 0;
	for(int i=0;i<ITERATIONS;i++){
		count_local = count_local +1;
	}
	share_count = share_count + count_local;
	return NULL;
}
int main(void){
	pthread_t pid[NUMBER_THREAD];
	int thread_ids[NUMBER_THREAD];
	for(int i=0;i<NUMBER_THREAD;i++){
		thread_ids[i] = i+1;
		if(pthread_create(&pid[i],NULL,mythread,&thread_ids[i]) !=0){
			perror("faild");
			return 1;
		}
	}
	for(int i=0;i<NUMBER_THREAD;i++){
		pthread_join(pid[i],NULL);
	}
	printf("share_count = %lld\n", share_count);
	return 0;
}


