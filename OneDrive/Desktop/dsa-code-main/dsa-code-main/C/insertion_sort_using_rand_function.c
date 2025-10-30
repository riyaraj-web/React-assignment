#include<stdio.h>
#include<stdlib.h>

void generate(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
		a[i]=rand()%100;
}

void display(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void insertionsort(int a[], int n)
{
	int i, temp, j;
	for(i=1;i<=n-1;i++)
	{
		temp=a[i];
		j=i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
int main()
{
	int size, arr[10];
	printf("\nEnter How Many Elements You Want?\n");
	scanf("%d",&size);
	generate(arr, size);
	printf("\nGiven Array Before Sort\n");
	display(arr,size);
	insertionsort(arr,size);
	printf("\nGiven Array After Sort\n");
	display(arr,size);
	return(0);
}