#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = fork();
	bool comeout;
	if (pid <0){
		perror("faild");
	}else if(pid ==0){
		for(int i=1;i<=5;i++){
			printf(i);
		}
		comeout = true;
	}
	if(comeout == true){
		printf("successsfully");
	}
	return 0;
}
