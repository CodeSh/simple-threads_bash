#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void *commands(char *command) {
	system(command);
}

int main(int argc, char *argv[]) {
	int i;
	pthread_t tid;
	for (i=1; i<argc; i++) {
		pthread_create(&tid, NULL, (void * (*)(void*))commands, argv[i]);
	}
	pthread_exit(NULL);
	return 0;
}
