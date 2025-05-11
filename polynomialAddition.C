#include <stdio.h>
#include <stdlib.h>
typedef struct poly
{
    int coeff,exp;
    struct poly *link;
}node;
node* create(node *f);
void display(node *p);
node* addition(node *p,node*q);
int main()
{
    node *f=NULL,*s=NULL,*r=NULL;
    printf("Enter the first polynomial\n");
    f=create(f);
    printf("Enter the second polynomial\n");
    s=create(s);
    printf("The eqs before adding are : \n");
    display(f);
    printf("\n");
    display(s);
    printf("\nThe result of addition of 2 eqs is\n");
    r=addition(f,s);
    display(r);
    return 0;
}
node* create(node *f)
{
    node *ptr;
    char ch;
    do
    {
        node *p=NULL;
        p=(node*)malloc(sizeof(struct poly));
        p->link=NULL;
        printf("Enter the coeff of eqn\n");
        scanf("%d",&p->coeff);
        printf("Enter the exp of eqn\n");
        scanf("%d",&p->exp);
        if(f==NULL)
        {
            f=p;
            ptr=p;
        }
        else
        {
            ptr->link=p;
            ptr=p;
        }
        printf("want to enter another term (y/n)\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    return f;
}
void display(node *p)
{
    if(p==NULL)
    {
        printf("Task failed successfully(Result is NULL)\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%dX^%d",p->coeff,p->exp);
        p=p->link;
        if(p!=NULL)
        {
            printf(" + ");
        }
    }
}
node* addition(node *f, node *s)
{
    node *p=f,*q=s,*r=NULL,*t,*ptr;
    while(p!=NULL&&q!=NULL)
    {
        t=(node *)malloc(sizeof(node));
        if(p->exp==q->exp)
        {
            t->coeff=p->coeff+q->coeff;
            t->exp=p->exp;
            p=p->link;
            q=q->link;
        }
        else if(p->exp>q->exp)
        {
            t->coeff=p->coeff;
            t->exp=p->exp;
            p=p->link;
        }
        else
        {
            t->coeff=q->coeff;
            t->exp=q->exp;
            q=q->link;
        }
        if(r==NULL)
        {
            r=t;
            ptr=t;
        }
        else
        {
            ptr->link=t;
            ptr=t;
        }
    }
    if(p==NULL)
    {
        while(q!=NULL)
        {
            t=(node *)malloc(sizeof(node));
            t->coeff=q->coeff;
            t->exp=q->exp;
            ptr->link=t;
            ptr=t;
            q=q->link;
        }
    }
        while(p!=NULL)
        {
            t=(node *)malloc(sizeof(node));
            t->coeff=p->coeff;
            t->exp=p->exp;
            ptr->link=t;
            ptr=t;
            p=p->link;
        }
    ptr->link=NULL;
    return r;
}