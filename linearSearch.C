#include<stdio.h>
void read(int[],int);
void display(int[],int);
void search(int[],int,int);
int main()
{
	int a[50],se,n;
	char ch;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter array elements: ");
	read(a,n);
	printf("The elements of the array are: ");
	display(a,n);
	printf("\n");
	do
	{
		printf("Enter searching element:");
		scanf("%d",&se);
		search(a,n,se);
		printf("\nDo you want to search another element?y/n: ");
		scanf(" %c",&ch);
	
	}
	while(ch=='y');
	return 0;
}
void read(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void display(int a[],int n)
{
	int i;
}
void search(int a[],int n,int se)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(se==a[i])
		break;
	}
	if(i<n)
		printf("Element found at index %d",i);
	else
		printf("Element not found");
}