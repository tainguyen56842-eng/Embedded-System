#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    
    printf("Truoc khi swap: x = %d, y = %d\n", x, y);
    
    // Truyền địa chỉ của x và y vào hàm
    swap(&x, &y);
    
    printf("Sau khi swap: x = %d, y = %d\n", x, y);
    
    return 0;
}
