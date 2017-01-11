
#include <pthread.h>
#include <stdio.h>


int i=0; 

void* some_func1(void* arg) {
	int j;
	for(j=0; j < 1000000; j++){
		i++;
	}
	return NULL; 
}

void* some_func2(void* arg) {
	int m;
	for(m=0; m < 1000000; m++){
		i--;
	}
	return NULL; 
}

int main() {
	pthread_t pth;
	pthread_t pth1;

	pthread_create(&pth, NULL, some_func1, NULL);
	pthread_create(&pth1, NULL, some_func2, NULL);

	pthread_join(pth, NULL);
	pthread_join(pth1, NULL);



	printf("After the threads: %d",i);
	return 0;
}