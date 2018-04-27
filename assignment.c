#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a[1000];

void *sumfun(void *p)
{
	int i;
	int sum=0;
	for(i=(int)p;i<(p+100);i++)
	{
		sum=sum+a[i];
	}
	return (void*)sum;
}
int main()
{
	int i;
	void *sum[10];
	for(i=0;i<1000;i++)
	{
		a[i]=i;
	}
	pthread_t t[10];
	pthread_create(&t[0], NULL, sumfun, (void*)0);
	pthread_create(&t[1], NULL, sumfun, (void*)100);
	pthread_create(&t[2], NULL, sumfun, (void*)200);
	pthread_create(&t[3], NULL, sumfun, (void*)300);
	pthread_create(&t[4], NULL, sumfun, (void*)400);
	pthread_create(&t[5], NULL, sumfun, (void*)500);
	pthread_create(&t[6], NULL, sumfun, (void*)600);
	pthread_create(&t[7], NULL, sumfun, (void*)700);
	pthread_create(&t[8], NULL, sumfun, (void*)800);
	pthread_create(&t[9], NULL, sumfun, (void*)900);
	
	for(i=0;i<10;i++)
	{
		pthread_join(t[i], &sum[i]);
	}
	int total=0;
	
	for(i=0;i<10;i++)
	{
		total=total+(int)sum[i];
	}
	printf("Sum = %d",total);
}
