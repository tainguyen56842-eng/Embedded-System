#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Khong thể mở file!\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
    return 0;
}
