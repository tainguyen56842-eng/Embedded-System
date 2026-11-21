#include <stdio.h>
#include <signal.h>
void signal_handler(int signum){
	if(2==signum){
		printf("hello_world");
	}
}

int main(){
	signal(2,signal_handler);
	while(1){
	}
	return 0;
}
