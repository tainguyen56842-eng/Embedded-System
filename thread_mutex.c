#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4
#define ITERATIONS 100000

// Khởi tạo tĩnh mutex và biến tài nguyên chia sẻ
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
long long shared_counter = 0;

void *increment_thread(void *arg) {
    int thread_id = *(int *)arg;
    long long local_work = 0;

    // 1. Phần tính toán/xử lý cục bộ: KHÔNG cần khóa mutex
    for (int i = 0; i < ITERATIONS; i++) {
        local_work++;
    }

    // 2. Chỉ khóa mutex đúng lúc truy cập tài nguyên chia sẻ (critical section)
    pthread_mutex_lock(&lock);
    shared_counter += local_work;
    pthread_mutex_unlock(&lock);

    printf("Luồng %d đã cộng thêm %lld vào shared_counter\n", thread_id, local_work);
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, increment_thread, &thread_ids[i]) != 0) {
            perror("Lỗi tạo luồng");
            return 1;
        }
    }

    // Chờ tất cả luồng con chạy xong
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Giải phóng mutex sau khi không còn dùng tới
    pthread_mutex_destroy(&lock);

    long long expected = (long long)NUM_THREADS * ITERATIONS;
    printf("Giá trị thực tế shared_counter: %lld\n", shared_counter);
    printf("Giá trị kỳ vọng:               %lld\n", expected);

    return 0;
}
