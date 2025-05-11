#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int no;
	char name [50];
	struct list *link;
}node;
node *first=NULL;
void insertion()
{
	node *p,*save,*ptr;
	p=(node*)malloc(sizeof(node));
	printf("Enter roll no and name of the student:");
	scanf("%d%s",&p->no,&p->name);
	if(first==NULL)
	{
		p->link=NULL;
		first=p;
		printf("Number Inserted\n");
		return;
	}
	if(p->no<=first->no)
	{
		p->link=first;
		first=p;
		printf("Number Inserted\n");
		return;
	}
	else
	{
		save=first;
		ptr=first->link;
		while(ptr!=NULL&&ptr->no<p->no)
		{
			save=ptr;
			ptr=ptr->link;
		}
		save->link=p;
		p->link=ptr;
		printf("Number Inserted\n");
	}
}
void deletion()
{
	int rno;
	node *save,*ptr;
	if(first==NULL)
	{
		printf("Underflow\n");
        return;
	}
	printf("Enter roll no to be deleted");
	scanf("%d",&rno);
	if(rno<first->no)
	{
		printf("Number not found\n");
		return;
	}
	if(rno==first->no)
	{
		ptr=first;
		first=first->link;
		free(ptr);
		printf("Number deleted\n");
		return;
	}
    save=first;
	ptr=first->link;
	while(ptr!=NULL && ptr->no<rno)
	{
		save=ptr;
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("Number not found\n");
		return;
	}
	save->link=ptr->link;
	free(ptr);
	printf("Number deleted\n");
}
void display()
{
	node *ptr;
	if(first==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=first;
	while(ptr!=NULL)
	{
		printf("%d %s\n",ptr->no,ptr->name);
		ptr=ptr->link;
	}
}
int main()
{
	int ch;
	do
	{
		printf("1.Insert 2.Delete 3.Display 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertion();break;
			case 2: deletion();break;
			case 3: display();
		}
	}
	while(ch<4);
	return 0;
}