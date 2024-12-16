#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024
int main() {
    key_t key = ftok("shmfile", 65); 
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    char *shmaddr = (char*)shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        perror("shmat");
        exit(1);
    }
    strcpy(shmaddr, "Hello, Shared Memory!");
    shmdt(shmaddr);
    shmaddr = (char*)shmat(shmid, NULL, 0);
    printf("Data read from shared memory: %s\n", shmaddr);
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

