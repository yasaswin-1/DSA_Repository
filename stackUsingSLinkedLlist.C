#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
	int no;
	struct stack *link;
}node;
node *top=NULL;
void push(int no)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	if(top==NULL)
	{
		p->link=NULL;
		p->no=no;
		top=p;
		printf("Successfully pushed.\n");
		return;
	}
	p->link=top;
	p->no=no;
	top=p;
	printf("Successfully pushed.\n");
}
void pop()
{
	node *ptr;
	if(top==NULL)
	{
		printf("Stack is underflow.\n");
		return;
	}
	ptr=top;
	printf("Popped value = %d\n",ptr->no);
	top=top->link;
	free(ptr);
}
void display()
{
	node *ptr;
	if(top==NULL)
	{
		printf("Stack is empty.\n");
		return;
	}
	printf("Elements of the stack are : ");
	ptr=top;
	while((ptr!=NULL))
	{
		printf("%d ",ptr->no);
		ptr=ptr->link;
	}
	printf("\n");
}
void peek()
{
	if(top==NULL)
	printf("Stack is underflow.\n");
	else
	printf("Peek value = %d\n",top->no);
}
void isEmpty()
{
	if(top==NULL)
	printf("Stack is empty.\n");
	else
	printf("Stack is not empty.\n");
}
int main() {
	int op, x;
	while(1) {	
		printf("1.Push 2.Pop 3.Display 4.Is Empty 5.Peek 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1: 
				printf("Enter element : ");
				scanf("%d", &x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3: 
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				peek();
				break;
			case 6: 
				exit(0);
		}
	}
}