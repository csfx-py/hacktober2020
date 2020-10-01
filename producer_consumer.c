#include<stdio.h>
#include<sys/types.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>
#define BUFFER_SIZE 6 

sem_t full,empty,mutex;
void *produce();
void *consume();

int in,out,buff[10];

int main()
{
	int ch;
	pthread_t tid1,tid2;
	in=out=0;
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	sem_init(&mutex,0,1);
	system("clear");
	do 
	{
		printf("\n1.Producer\n2.Consumer\n3.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:	
				pthread_create(&tid1,NULL,produce,NULL);
				pthread_join(tid1,NULL);
				break;
			case 2:
				pthread_create(&tid2,NULL,consume,NULL);
				pthread_join(tid2,NULL);
				break;
			case 3:
				exit(0);
		}
		
	}while(ch!=3);
}

void *produce()
{
	if((in+1)%BUFFER_SIZE==out)
	{
		printf("\n**** Buffer is FULL **** !\n");
		return 0;
	}
	sem_wait(&empty);
	sem_wait(&mutex);
	printf("\nProduce the Data :");
	scanf("%d",&buff[in]);
	
	in=(in+1)%BUFFER_SIZE;
	sem_post(&mutex);
	sem_post(&full);
}

void *consume()
{
	if(in==out)
	{
		printf("\n**** Buffer is EMPTY **** !\n");
		return 0;
	}
	sem_wait(&full);
	sem_wait(&mutex);
	printf("Consume Data is : %d",buff[out]);
	
	out=(out+1)%BUFFER_SIZE;
	sem_post(&mutex);
	sem_post(&empty);
}


//gcc pname.c -o pname -lpthread -lrt
// ./pname
