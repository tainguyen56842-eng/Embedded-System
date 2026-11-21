#include<stdio.h>
#include<pthread>
#include<unistd.h>

FILE *fp
struct my_struct {
	char *name;
	int age;
}
struct my_struct ms;
void *my_thread(void *my_argv){
	fwrite(fp,"hello world",sizeof("hello world"));
}
void main(){
	pthread_t tid;
	fp = fopen("data.txt",NULL,my_thread,NULL);
	pthread_create(&tid,NULL,my_thread,NULL);
	fwrite(fp,"hello world",sizeof("hello world"));
	pthread_join(tid,NULL);
	fclose(fp);
}
