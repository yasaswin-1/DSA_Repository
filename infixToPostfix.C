#include <stdio.h>
char ch='y';
char q[50],p[50];
int top=-1;
char stk[50];
void push(char c)
{
stk[++top]=c;
}
char pop()
{
return(stk[top--]);
}
char s()
{
return(stk[top]);
}
void main()
{
int i,j,n;
clrscr();
while(ch=='y')
{
printf("Enter the infix expression with out blank spaces:");
scanf("%s",q);
push('(');

for(n=0;q[n]!='\0';n++);
q[n]=')';
i=j=0;
while(top>-1)
{
switch(q[i])
{
case '(':push(q[i]);break;
case '+':
case '-':while(s()=='+'||s()=='-'||s()=='*'||s()=='/'||s()=='^')
p[j++]=pop();
push(q[i]); break;
case '*':
case '/':while(s()=='*'||s()=='/'||s()=='^')
p[j++]=pop();
push(q[i]);break;
case '^':while(s()=='^')
p[j++]=pop();
push(q[i]);break;
case ')':while(s()!='(')
p[j++]=pop();
ch=pop();break;
default: p[j++]=q[i];
}
i++;
}
printf("The converted postfix expression is:");

for(i=0;i<n;i++)
printf("%c",p[i]);
printf("\n");
printf("Do you want to continue?y/n:");
scanf(" %c",&ch);
}
}