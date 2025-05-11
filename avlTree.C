#include<stdio.h>
#include<stdlib.h>
typedef struct slist
{
int data;
struct slist *left,*right;
int ht;
}node;
node *root=NULL;
node * insert(node *T,int x);
int height(node *T);
node * rotateright(node *x);
node * rotateleft(node *x);
node * LL(node *T);
node * RR(node *T);
node * LR(node *T);
node * RL(node *T);
int BF(node *T);
void preorder(node *T);
void inorder(node *T);
void postorder(node *T);
node* insert(node *T,int x)
{
if(T==NULL)
{
T=(node *) malloc(sizeof(node));
T->data=x;
T->left=NULL;
T->right=NULL;
}
else if(x > T->data) // insert in right subtree
{
T->right=insert(T->right,x);
if(BF(T)==-2)
if(x>T->right->data)
T=RR(T);
else
T=RL(T);

}
else if(x<T->data)
{
T->left=insert(T->left,x);
if(BF(T)==2)
if(x < T->left->data)
T=LL(T);
else
T=LR(T);
}
T->ht=height(T);
return(T);
}
int height(node *T)
{
int lh,rh;
if(T==NULL)
return(0);

if(T->left==NULL)
lh=0;
else
lh=1+T->left->ht;
if(T->right==NULL)
rh=0;
else
rh=1+T->right->ht;
if(lh>rh)
return(lh);
return(rh);
}
node* rotateright(node *x)
{
node *y;
y=x->left;
x->left=y->right;
y->right=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}
node* rotateleft(node *x)
{
node *y;
y=x->right;
x->right=y->left;
y->left=x;
x->ht=height(x);
y->ht=height(y);
return(y);
}
node* RR(node *T)
{
T=rotateleft(T);
return(T);
}
node* LL(node *T)
{
T=rotateright(T);
return(T);
}
node* LR(node *T)
{
T->left=rotateleft(T->left);
T=rotateright(T);
return(T);
}
node* RL(node *T)
{
T->right=rotateright(T->right);
T=rotateleft(T);
return(T);
}
int BF(node *T)
{
int lh,rh;

if(T==NULL)
return(0);
if(T->left==NULL)
lh=0;
else
lh=1+T->left->ht;
if(T->right==NULL)
rh=0;
else
rh=1+T->right->ht;
return(lh-rh);
}
void preorder(node *T)
{
if(T!=NULL)
{
printf("%dBF=(%d) ",T->data,BF(T));
preorder(T->left);
preorder(T->right);
}
}
void inorder(node *T)
{
if(T!=NULL)
{
inorder(T->left);
printf("%dBF=(%d)",T->data,BF(T));
inorder(T->right);
}
}
void postorder(node *T)
{
if(T!=NULL)
{
postorder(T->left);
postorder(T->right);
printf("%dBF=(%d)",T->data,BF(T));
}
}
int main()
{
int x,n,i,op;
do
{
printf("\n1)Insert:\n2)Preorder:\n3)Inorder:\n4)Postorder:\n5)Quit:\n\nEnter Your

Choice:");

scanf("%d",&op);
switch(op)
{
case 1:printf("\nEnter a data:");

scanf("%d",&x);root=insert(root,x);break;

case 2: if(root)
{
printf("\nPreorder sequence:\n");
preorder(root);
}
else

printf("Tree is Empty:\n");
printf("\n");break;
case 3: if(root)
{
printf("\n\nInorder sequence:\n");
inorder(root);
}
else printf("Tree is Empty:\n");
printf("\n"); break;

case 4: if(root)
{
printf("\n\nPostorder sequence:\n");
postorder(root);
}
else printf("Tree is Empty:\n");
printf("\n");break;

}
}while(op<5);
return(0);
}