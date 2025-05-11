#include<stdio.h>
int f=-1,r=-1,q[25];
void ins(int v);
int del();
void ins(int n)
{
 if(r==-1)
   f=r=0;
 else
 r++;
 q[r]=n;
}
int del()
{
 if(f==-1)
  return(-1);
 else
 {
  int t=q[f];
  if(f==r)
   f=r=-1;
  else
   f++;
  return t;
  }
}
void main()
{
 int cost[25][2],nv,v,ne,visit[25],i,j,k,flag=1;
 printf("\nEnter the number of vertices...");
 scanf("%d",&nv);
 for(i=1;i<=nv;i++)
  for(j=1;j<=nv;j++)
   cost[i][j]=0;
 for(i=1;i<=nv;i++)
  visit[i]=0;
 printf("Enter the number of edges...");
 scanf("%d",&ne);
 printf("Enter the edges(i,j).../n");
 for(k=1;k<=ne;k++)
 {
  scanf("%d %d",&i,&j);
  cost[i][j]=1;
 }
 printf("Enter the sorce vertex..");
 scanf("%d",&v);
 printf("According BFS,the visiting sequences of the vertices are.../n");
 printf("%d ",v);
 visit[v]=1;
 while(flag==1)
 {
  for(j=1;j<=nv;j++)
  {
   if(cost[v][j]!=0&&visit[j]==0)
   {
    visit[j]=1;
    printf("%d ",j);
    ins(j);
   }
  }
  v=del();
  if(v==-1) flag=0;
 }
}