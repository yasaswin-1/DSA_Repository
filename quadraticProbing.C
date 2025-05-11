#include<stdio.h>
#include<stdlib.h>
#define size 10
int h[size]={ NULL };
void insert()
{
  int key,i,index,hkey;
  printf("\nEnter a value to insert into hash table\n");
  scanf("%d",&key);
  hkey=key%size;
  for(i=0;i<size;i++)
  {
   index=(hkey+i*i)%size;
   if(h[index]==NULL)
   {
    h[index]=key;
    break;
   }
  }
  if(i==size)
   printf("\n Element cannot be inserted\n");
}
void search()
{
 int key,index,i,hkey;
 printf("Enter search element");
 scanf("%d",&key);
 hkey=key%size;
 for(i=0;i<size;i++)
 {
  index=(hkey+i*i)%size;
  if(h[index]==key)
  {
     printf("value is found at index %d",index);
     break;
  }
 }
 if(i==size)
  printf("value is not found");
}
void display()
{
 int i;
 printf("Elements in hash table are\n");
 for(i=0;i<size;i++)
    printf("\n at index %d \t value=%d",i,h[i]);
}
main()
{
 int opt,i;
 while(1)
 {
   printf("press 1.insert 2.Display 3.search 4.Exit");
	   scanf("%d",&opt);
	    switch(opt)
	   {
	      case 1: insert();
		      break;
	      case 2: display();
		      break;
	      case 3: search();
		      break;
	      case 4: exit(0);
	      }
	}
   }




#include<stdio.h>
#include<stdlib.h>
#define size 10
int h[size]={ NULL };
int key,i,index,hkey,opt;
main()
{
 while(1)
 {
   printf("press 1.insert 2.Display 3.search 4.Exit");
	   scanf("%d",&opt);
	    switch(opt)
	   {
	      case 1: //insert
              printf("\nEnter a value to insert into hash table\n");
              scanf("%d",&key);
              hkey=key%size;
              for(i=0;i<size;i++)
              {
               index=(hkey+i*i)%size;
               if(h[index]==NULL)
               {
                h[index]=key;
                break;
               }
              }
              if(i==size)
               printf("\n Element cannot be inserted\n");
		      break;
	      case 2: //display
              printf("Elements in hash table are\n");
              for(i=0;i<size;i++)
                printf("\n at index %d \t value=%d",i,h[i]);
		      break;
	      case 3: //search
              printf("Enter search element");
              scanf("%d",&key);
              hkey=key%size;
              for(i=0;i<size;i++)
              {
              index=(hkey+i*i)%size;
              if(h[index]==key)
              {
                 printf("value is found at index %d",index);
                 break;
              }
             }
             if(i==size)
              printf("value is not found");
		      break;
	      case 4: exit(0);
	      }
	}
}
