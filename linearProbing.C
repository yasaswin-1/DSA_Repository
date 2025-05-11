#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 10
 int ch;
 void menu()
 { printf("Enter the option 1.search/insert 2.Display 3.Exit...");
   scanf(" %d",&ch);
   };
 void main()
 {  int h[size],n,i,j,loc,key,flag;
    for(i=0;i<size;i++)
     h[i]=-1;
     clrscr();
     menu();
     while(ch<3)
    { switch(ch)
      {  case 1: printf("Enter a key to search: ");
		 scanf("%d",&key);
		  loc=key%size;
		  if(h[loc]==-1)
		  { printf("key is not found and done insertion\n");
		    h[loc]=key;
		    }
		  else
		    if(h[loc]==key)
		    {
		      printf("key is already in the table\n");
		     }
		  else
		  {
		     flag=1;i=0;
		     while(flag==1)
		     {  i=i+1;
			j =(loc + i) % size;
			if(h[j]== -1)
			{  printf("key is not found and done insertion\n");
			   h[j]=key;
			   flag=0;
			 }
			else
			  if(h[j]==key) {
				printf("key is found in the table\n");
			    flag=0;
			   }
			else
			  if(j==loc) {
				printf("Table is full\n");
				flag=0;
		     }
		 }
    }
    menu(); break;
 case 2: printf("Contents of hash table are: \n");
	   for(i=0;i<size;i++)
	     printf("%d---->%d\n",i,h[i]);
	     menu(); break;
     }
   }
   getch();
 }