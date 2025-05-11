#include<stdio.h>
#include<stdlib.h>
typedef struct dlist
{
	int no;
	struct dlist *lptr,*rptr;
}node;
node *left=NULL,*right=NULL;
void insertion()
{
	node *p,*ptr;
	p=(node *)malloc(sizeof(node));
	printf("Enter number: ");
	scanf("%d",&p->no);
	if(left==NULL)
	{
		left=right=p;
		p->lptr=p->rptr=NULL;
		return;
	}
	if(p->no<=left->no)
	{
		p->lptr=NULL;
		p->rptr=left;
		left->lptr=p;
		left=p;
        return;
	}
	if(p->no>=right->no)
	{
		p->rptr=NULL;
		p->lptr=right;
		right->rptr=p;
		right=p;
		return;
	}
	ptr=left->rptr;
	while(ptr!=right&&ptr->no<p->no)
		ptr=ptr->rptr;
	p->rptr=ptr;
	p->lptr=ptr->lptr;
	ptr->lptr->rptr=p;
	ptr->lptr=p;
}
void deletion()
{
	int rno;
	node *ptr;
	if(left==NULL)
	{
        printf("Underflow");
		return;
	}
	printf("Enter number to delete: ");
	scanf("%d",&rno);
	if(rno<left->no||rno>right->no)
	{
		printf("%d not found.\n",rno);
		return;
	}
	if(rno==left->no)
	{
		ptr=left;
		if(left==right)
		left=right=NULL;
		else
		{
			left=left->rptr;
			left->lptr=NULL;
		}
		free(ptr);
		return;
	}
	if(rno==right->no)
	{
        ptr=right;
		right=right->lptr;
		right->rptr=NULL;
		free(ptr);
		return;
	}
	ptr=left->rptr;
	while(ptr!=right&&ptr->no<rno)
	ptr=ptr->rptr;
	if(ptr==right||ptr->no>rno)
	{
		printf("%d not found.\n",rno);
		return;
	}
	ptr->lptr->rptr=ptr->rptr;
	ptr->rptr->lptr=ptr->lptr;
	free(ptr);
}
void display()
{
	node *ptr;
	if(left==NULL)
	{
		printf("List is empty");
		return;
        }
	ptr=left;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->no);
		ptr=ptr->rptr;
	}
	printf("\n");
}
int main()
{
	int ch;
	do
	{
		printf("Operations on doubly linked list\n");
		printf("1. Insert \n2. Remove\n3. Display\n0. Exit\n");
		printf("Enter Choice 0-4? : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insertion();break;
			case 2:deletion();break;
			case 3:display();break;
			case 0:exit(0);
		}
	}
	while(ch<4);
}