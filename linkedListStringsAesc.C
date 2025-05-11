#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertion(int i);
void display();
void deletion();
typedef struct words
{
    char a[30];
    struct words *link;
}node;
node *first=NULL;
void main()
{
    int i=0,ch=0;
    printf("Operations on strings in linked list");
 do
 {
  printf("\n1.Insert   2.Delete   3.Display   4.Exit");
  printf("\nEnter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:insertion(i++);break;
   case 2:deletion();break;
   case 3:display();break;
   default:exit(0);
  }
 }
 while(ch>0&&ch<4);
}
void insertion(int i)
{
    node *p,*ptr,*save;
    p=(node *)malloc(sizeof(node));
    printf("Enter the word %d : ",i+1);
    scanf("%s",p->a);
    if(first==NULL)
    {
        p->link=NULL;
        first=p;
        return;
    }
    if(strcmp(p->a,first->a)<0)
    {
        p->link=first;
        first=p;
        return;
    }
    save=first;
    ptr=first->link;
    while(ptr!=NULL&&strcmp(ptr->a,p->a)<0)
    {
        save=ptr;
        ptr=ptr->link;
    }
    save->link=p;
    p->link=ptr;
}
void display()
{
 node *ptr;
 if(first==NULL)
 {
  printf("\nList is empty");
  return;
 }
 printf("The words in the list are : \n");
 ptr=first;
 while(ptr!=NULL)
 {
  puts(ptr->a);
  ptr=ptr->link;
 }
}
void deletion()
{
 char a[30];
 node *save,*ptr;
 if(first==NULL)
 {
  printf("\nUnder flow");
  return;
 }
 printf("\nEnter the word to be deleted : ");
 scanf("%s",a);
 if(strcmp(a,first->a)<0)
 {
  printf("\nWord not found");
  return;
 }
 if(strcmp(a,first->a)==0)
 {
  ptr=first;
  first=first->link;
  free(ptr);
  printf("Word deleted successfully\n");
  return;
 }
 save=first;
 ptr=first->link;
 while(ptr!=NULL &&strcmp(ptr->a,a))
 {
  save=ptr;
  ptr=ptr->link;
 }
 if(ptr==NULL||strcmp(ptr->a,a)>0)
 {
  printf("\nWord not found");
  return;
 }
 save->link=ptr->link;
 printf("Word deleted successfully\n");
 free(ptr);
}
