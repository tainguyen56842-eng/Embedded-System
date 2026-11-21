#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    printf("Trước khi fork(), chỉ có 1 tiến trình (PID: %d)\n", getpid());

    // Gọi fork() để tạo tiến trình con
    pid = fork();

    // Kiểm tra kết quả trả về
    if (pid < 0) {
        // Lỗi
        perror("fork thất bại");
        return 1;
    } 
    else if (pid == 0) {
        // Đoạn code này CHỈ CHẠY ở tiến trình con
        printf("--> Đây là TIẾN TRÌNH CON. PID của tôi: %d, PID của cha tôi: %d\n", getpid(), getppid());
    } 
    else {
        // Đoạn code này CHỈ CHẠY ở tiến trình cha
        printf("--> Đây là TIẾN TRÌNH CHA. PID của tôi: %d, PID của con vừa tạo: %d\n", getpid(), pid);
    }

    // Cả cha và con đều chạy đến đây
    printf("Chương trình kết thúc tại PID: %d\n", getpid());

    return 0;
}

