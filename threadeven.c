#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* PrintEvenNos(void*);
void* PrintOddNos(void*);

int main()
{
	pthread_t t1,t2;
	int max;
	printf("enter the max value \n");
	scanf("%d",&max);
	pthread_create(&t1,NULL,&PrintEvenNos,&max);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,&PrintOddNos,&max);
	pthread_join(t2,NULL);
}

void* PrintEvenNos(void* max)
{
	int i;
	printf("Even numbers\n");
	for(i=1;i<=*(int *)max;i++)
	{
		if(i%2==0)
		{
			printf("%d   ",i);
		}
	}
	printf("\n");
}

void* PrintOddNos(void* max)
{
	int i;
	printf("Odd numbers\n");
	for(i=0;i<=*(int *)max;i++)
	{
		if(i%2!=0)
		{
			printf("%d   ",i);
		}
	}
	printf("\n");
}
