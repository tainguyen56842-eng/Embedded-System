#include "mymath.h"
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        printf("Lỗi: Không thể chia cho 0!\n");
        return 0.0f; // Trả về 0 hoặc giá trị báo lỗi tùy chọn
    }
    return (float)a / b;
}

long long factorial(int n) {
    if (n < 0) {
        printf("Lỗi: Không tính được giai thừa của số âm!\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}
