#include<stdio.h>
#include<pthread.h>
void *mythread(void *my_argv){
	printf("Hello World I am%s\n",(char *)my_argv);
	return NULL;
}
void main(){
	pthread_t tid;
	char *my_name = "Tai";
	pthread_create(&tid,NULL,mythread,my_name);
	pthread_join(tid,NULL);
}
