#include<stdio.h>
void insertion(int [ ]);
void deletion(int [ ]);
void display(int [ ]);
int n;
 void main()
{
 int a[50],i,ch;
 clrscr();
 printf("\nEnter the size of the array:");
 scanf("%d",&n);
 printf("Enter the elements of the array:");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 while(ch>0&&ch<5);
 {
  printf("\n1.insert   2.delete   3.dispaly   4.exit");
  printf("\nEnter your choice");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:insertion(a);break;
   case 2:deletion(a);break;
   case 3:display(a);break;
   case 4:exit(0);break;
   default:exit(0);
  }
 }
 exit(0);
}

void insertion(int a[])
{
 int i,loc,item;
 printf("\nEnter the position to insert the element:");
 scanf("%d",&loc);
 printf("\nEnter the element to insert:");
 scanf("%d",&item);
 for(i=n-1;i>=loc;i--)
  a[i+1]=a[i];
 a[loc]=item;
 n++;
 printf("\nElement inserted");
}

void deletion(int a[])
{
 int i,loc;
 printf("\nEnter the position to delete the element:");
 scanf("%d",&loc);
 for(i=loc;i<n-1;i++)
  a[i]=a[i+1];
 n--;
 printf("\nElement deleted");
}

void display(int a[])
{
 int i;
 for(i=0;i<n;i++)
  printf("%d ",a[i]);
}
