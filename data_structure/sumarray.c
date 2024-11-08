#include<stdio.h>
int main()
{
	int ary[10];
	int elements;
	int sum=0;
	int i;

	printf("enter size : ");
	scanf("%d",&elements);
	for(i=0; i<elements; i++)
	{
		printf("Element %d : ",i+1);
		scanf("%d", &ary[i]);
	}
	

	for(i=0; i<elements; i++)
	{
		sum=sum+ary[i];
		
	}
	printf("sum = %d",sum);
	return(0);
		
}
