
#include<stdio.h>
#include<stdlib.h>
void generate(int *a, int n)
{
	int i;
	for (i=0; i<n; i++)
		a[i]=rand()%100;
}
void display(int *a, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void linear_search(int *a, int n, int key)
{
	int i, flag=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nSearch is success! and %d is found at %d position\n",key,i+1);
	}
	else
	{
		printf("%d is not found!\n",key);
	}
}
int main()
{
	int size, arr[10], key;
	printf("\nHow Many Elements You Want?\n");
	scanf("%d",&size);
	generate(arr, size);
	printf("\nGiven Array Is::\n");
	display(arr, size);
	printf("\nEnter The Element To Search!\n");
	scanf("%d",&key);
	linear_search(arr, size, key);
	return(0);
}