#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
	sigset_t all_sigs,old_sigs;
	if(sigfillset(&all_sigs)==-1){
		perror("sigfillset faild");
		return -1;
	}
	if(sigprocmask(SIG_BLOCK,&all_sigs,&old_sigs) ==-1){
		perror("sigprocmask faild");
		return -1;
	}
	printf("loadding systems....(5s)");
	sleep(5);
	printf("hết thời gian quan trọng ,mở lại signal...");
	sigprocmask(SIG_SETMASK,&old_sigs,NULL);
	printf("hoàn tất");
	return 0;
}
