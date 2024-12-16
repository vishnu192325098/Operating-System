#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char* message1 = "Hello from Thread 1!";
    char* message2 = "Hello from Thread 2!";

    pthread_create(&thread1, NULL, threadFunction, (void*)message1);
    pthread_create(&thread2, NULL, threadFunction, (void*)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

