// 
// IS_Program3.c
// ECE-399 Programming Paradigms 
// Professor Sable
// Created by Nishat Ahmed on 7/27
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//define a struct containing parameters of SellTickets function 
struct args{
		int agent;
		int *numTicketsp;
		sem_t *lockp;
};

//create SellTickets function
void * SellTickets(void *x){
	//cast argument to be struct args type
	struct args *y;
	y = (struct args *)x;
	while (true){
		sem_wait(y->lockp); 
		if(*(y->numTicketsp)==0){
			break;  
		}
		(*(y->numTicketsp))--;
		printf("Agent %d sold a ticket. %d remaining tickets.\n", y->agent, *(y->numTicketsp));
		sem_post(y->lockp); //signal semaphore to free count 
		sleep(rand()%3+1); //wait 1-3 seconds before passing control to another thread
	}
	sem_post(y->lockp); //unlock without being in the critical region
}

int main(){
	int numAgents = 10;
	int numTickets = 150;
	int pshared = 0;
	sem_t lock;
	int value = 1;
	sem_init(&lock, pshared, value);
	struct args array[numAgents]; //array of struct args to pass to the different threads
	pthread_t threads[numAgents];
	//create threads
	for(int agent=0; agent<numAgents; agent++){
		array[agent].agent = agent;
		array[agent].numTicketsp = &numTickets;
		array[agent].lockp = &lock;
		pthread_create(&threads[agent], NULL, SellTickets, (void *)&array[agent]);
	}
	//wait for each thread to finish being created and join all threads
	for(int agent=0; agent<numAgents; agent++){
		pthread_join(threads[agent], NULL);
	}
	pthread_exit(NULL);
	sem_destroy(&lock);
	return 0;
}

