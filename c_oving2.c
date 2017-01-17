


#include <pthread.h>
#include <stdio.h>


int i=0; 


pthread_mutex_t lock; // Vet egentlig ikke hva dette er, men den trengs for pthread_mutex_(un)lock


void* some_func1(void* arg) {
	int j;
	for(j=0; j < 1000000; j++){
		pthread_mutex_lock(&lock);
		i++;
		pthread_mutex_unlock(&lock); 
	}
	return NULL; 
}

void* some_func2(void* arg) {
	int m;
	for(m=0; m < 999999; m++){
		pthread_mutex_lock(&lock);
		i--;
		pthread_mutex_unlock(&lock); 
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