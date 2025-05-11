#include <stdlib.h>
#include <stdio.h>
int main();
typedef struct no
{
	int x;
	struct no *link;
}node;
node *first=NULL,*last=NULL;
void enqueue(int x)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->x=x;
	printf("Successfully inserted.\n");
	if(first==NULL)
	{
		first=last=p;
		p->link=NULL;
	}
	else
	{
		last->link=p;
		last=p;
		last->link=NULL;
	}
}
void dequeue()
{
	node *ptr;
	if(first==NULL)
	{
	    printf("Queue is underflow.\n");
	    return;
	}
	printf("Deleted value = %d\n",first->x);
	ptr=first;
	first=first->link;
	free(ptr);
	if(first==NULL)
	last=first;
}
void isEmpty()
{
	if(first==NULL)
	{
     	printf("Queue is empty.\n");
     	main();
	}
	else
	{
		printf("Queue is not empty.\n");
		return;
	}
}
void display()
{
	if(first==NULL){
		isEmpty();
	}
	node *ptr;
	ptr=first;
	printf("Elements in the queue : ");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->x);
		ptr=ptr->link;
	}
	printf("\n");
}
void size()
{
	node *ptr;
	int n=0;
	ptr=first;
	while(ptr!=NULL)
	{
		n++;
		ptr=ptr->link;
	}
	printf("Queue size : %d\n",n);
}
int main() {
	int op, x;
	while(1) {	
		printf("1.Enqueue 2.Dequeue 3.Display 4.Is Empty 5.Size 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d",&op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				size();
				break;
			case 6: exit(0);
		}
	}
    return 0;
}