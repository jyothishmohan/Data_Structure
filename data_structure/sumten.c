#include<stdio.h>
int main()
{
	int i=1;
	int n;
	int sum=0;
	printf("Enter number of terms : ");
	scanf("%d",&n);
	while(i<=n)
	{
	
		sum=sum+i;
		i=i+1;
	}
	printf("Sum = %d",sum);
	return(0);
}
