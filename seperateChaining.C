#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 10
int ch;
void menu()
{
 printf("Enter option: 1.search/insert 2.display 3.exit..");
  scanf("%d",&ch);
}
struct node
{
 int no;
 struct node *link;
};
void main()
{
  int i,loc,key;
  struct node *p,*ptr,*h[size];
  for(i=0;i<size;i++)
    h[i]=NULL;
  clrscr();
  menu();
  while(ch<3)
  {
  switch(ch)
  {
    case 1: printf("Enter key to search or insert");
	    scanf("%d",&key);
	    loc=key%size;
	    ptr=h[loc];
	    if(h[loc]==NULL)
	    {
	      struct node *p=(struct node *)malloc(sizeof(struct node));
	      p->no=key;
	      p->link=NULL;
	      h[loc]=p;
	    }
	    else
	    {
	      ptr=h[loc];
	      while(ptr!=NULL &&key!=ptr->no)
		ptr=ptr->link;
	      if(ptr==NULL)
	      {
		struct node *p=(struct node *)malloc(sizeof(struct node));
		printf("Key not found");
		p->no=key;
		p->link=h[loc];
		h[loc]=p;
	      }
	      else
	      {
	       printf("Number already exists ");
	      }
	    }
	      menu();
	      break;
	    case 2 : printf("Contents of table are:");
		     for(i=0;i<size;i++)
		      {
		       ptr=h[i];
		       printf("%d......>",i);
		       while(ptr!=NULL)
		       {
		       printf("%d ",ptr->no);
			ptr=ptr->link;

			}
			printf("\n");
		       }
		       menu();
		      break;
	    }
	    getch();
    }
}





































































































































































































































































































































































































































































































































































