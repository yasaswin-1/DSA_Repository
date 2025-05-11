#include <stdio.h>
void swap(int *p,int *q)
{
    int t=*p;
    *p=*q;
    *q=t;
}
maxheapify(int a[],int n,int i)
{
    int largest=i;
    int l=(2*i+1);
    int r=(2*i+2);
    while(l<n&&a[l]>a[largest])
    {
        largest=l;
    }
    while(r<n&&a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        maxheapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    maxheapify(a,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        maxheapify(a,i,0);
        printf("pass %d: ",n-i);
        printarray(a,n);
    }    
}
void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
}
void main()
{
    int n=10,a[]={4,1,3,2,16,9,10,14,8,7};
    printf("original array\n");
    printarray(a,n);
    printf("passes are:\n");
    heapsort(a,n);
    printf("sorted array\n");
    printarray(a,n);
}