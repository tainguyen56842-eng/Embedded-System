#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
	const char *name = "/my_shm";
	const size_t size= 4096;
	//(1) tạo hoặc mở share memory object
	int fd = shm_open(name,O_CREAT |O_RDWR,0666);
	if(fd == -1){
		perror("shm_open");
		return 1;
	}
	//(2) đặt kích thước (chỉ cần khi tạo mới);
	if(ftruncate(fd,size) ==-1){
		perror("ftuncate");
		return 1;
	}
	//(3) ánh xạ không gian địa chỉ 
	char *ptr = mmap(NULL,size,PROT_READ | PROT_WRITE,MAP_SHARE,fd,0);
	if(ptr == MAP_FAILED){
		perror("mmap");
		return 1;
	}
	strcpy(ptr,"hello from POSIX share memory");
	munmap(ptr,size);
	return 0;
}
