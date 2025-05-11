#include<stdio.h>
int main() {
	int a[20], i, n, j, small, index;
	printf("Enter value of n : ");
	scanf("%d", &n);
	// Write the code to read an array elements
	int temp;
	for(i=0;i<n;i++)
	{
		printf("Enter element for a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	printf("Before sorting the elements in the array are\n");
	// Write the code to print the given array elements before sorting
	for(i=0;i<n;i++)
	{
		printf("Value of a[%d] = %d\n",i,a[i]);
	}
	// Write the code for selection sort smallest element method
	for(i=0;i<n;i++)
	{
		small=i;
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[small])
			{
				small=j;
			}
		}
		if(small!=i)
		{
		    temp=a[small];
	    	a[small]=a[index];
	    	a[index]=temp;
		}
	}
	printf("After sorting the elements in the array are\n");
	// Write the code to print the given array elements after sorting
	for(i=0;i<n;i++)
	{
		printf("Value of a[%d] = %d\n",i,a[i]);
	}
	return 0;
}