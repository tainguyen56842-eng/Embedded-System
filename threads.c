#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *thread_function(void *arg){
	char *message = (char *)arg;
	for (int i=0;i<5;i++){
		printf("luồng con : %s %d\n", message, i + 1);
		sleep(1);
	}
	return NULL;
}
int main(){
	pthread_t thread_id;//biến chưa ID của luồng 
	char *msg = "xin chào từ luồng";
	if(pthread_create(&thread_id,NULL,thread_function,(void *)msg)!=0){
		perror("không thể tạo luồng");
		return 1;
	}
	pthread_join(thread_id,NULL);
	printf("luồng chính :luồn con đã kết thúc .\n");
	return 0;
}


