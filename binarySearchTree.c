#include<stdio.h>
#include<ctype.h>
#include <stdlib.h>
typedef struct btree{
int data;
struct btree *left,*right;
}node;
node* insert(node *root,int x){
if(root==NULL)
{
node *p=(node *)malloc(sizeof(node));
p->data=x;
p->left=p->right=NULL;
return p;
}
if(x<root->data)
root->left=insert(root->left,x);
else if(x>root->data)
root->right=insert(root->right,x);
return root;
}
void preorder(node *root){
if(root==NULL)
return;
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}
void inorder(node *root)
{  
if(root==NULL)  
return;
inorder(root->left);  
printf("%d ",root->data);  
inorder(root->right);  
}
void postorder(node *root)
{  
if(root==NULL)  
return;
postorder(root->left);
postorder(root->right);
printf("%d ",root->data);
}
int search(node* root, int se)
{
while(root)
{
if(se==root->data)
return 1;
else if(se<root->data)
root=root->left;
else
root=root->right;
}
return 0;
}
node * minvaluenode(node* root)
{

while (root && root->left != NULL)
root = root->left;

return root;
}
node* deletenode(node *root,int x){
if(root==NULL)
return NULL;
if(x<root->data)
root->left=deletenode(root->left,x);
else if(x>root->data)
root->right=deletenode(root->right,x);
else{
if(root->left==NULL){
node *temp=root->right;
free(root);
return temp;
}
else if(root->right==NULL){
node *temp=root->left;
free(root);
return temp;
}
else{
node *temp=minvaluenode(root->right);
root->data=temp->data;
root->right=deletenode(root->right,temp->data);
}
}
return root;
}
void main(){
node *root=NULL;
int x,ch,se,de;
printf("Operations on bst\n");
printf("1.insert\n2.preorder\n3.inorder\n4.postorder\n5.search\n6.delete\n7.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
do{
switch(ch){
case 1:printf("Enter a number\n");
       scanf("%d",&x);
       if(search(root,x)){
              printf("Item already exists\n");
              break;
       }
       root=insert(root,x);
       break;
case 2:printf("The elements in preorder are\n");
       if(root==NULL)
       printf("Binary tree is empty\n");
       preorder(root);
       break;
case 3:printf("The elements in inorder are\n");
       if(root==NULL)
       printf("Binary tree is empty\n");
       inorder(root);
       break;
case 4:printf("The elements in postorder are\n");
       if(root==NULL)
       printf("Binary tree is empty\n");
       postorder(root);
       break;
case 5:printf("Enter the searching element\n");
       scanf("%d",&se);
       if(search(root,se)){
           printf("Element %d found in bst\n",se);
       }
       else
       printf("Element %d not found in bst\n",se);
       break;
case 6:if(root==NULL){
       printf("BST is empty\n");
       break;
       }
       printf("Enter item to be deleted\n");
       scanf("%d",&de);
       deletenode(root,de);
       printf("Item deleted\n");
       break;
case 7:exit(0);
       break;
default:exit(0);
}
printf("\n1.insert\n2.preorder\n3.inorder\n4.postorder\n5.search\n6.delete\n7.exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
}while(ch>0&&ch<8);
}