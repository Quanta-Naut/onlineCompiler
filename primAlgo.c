#include<stdio.h>
#define INFINITY 999
intprim(int cost[10][10],intsource,int n)
{
​inti,j,sum=0,visited[10];
​int distance[10],vertex[10];
​intmin,u,v;
       for(i=1;i<=n;i++)
      {
​vertex[i]=source;
​visited[i]=0;
​distance[i]=cost[source][i];
      }​
      visited[source]=1;
      for(i=1;i<n;i++)
     {
​min=INFINITY;
​ for(j=1;j<=n;j++)
​{
​​​ if(!visited[j]&&distance[j]<min)
​​​{
​​​​ min=distance[j];
​​​​ u=j;
​​​ }
​        }
​  visited[u]=1;
​  sum=sum+distance[u];
​printf("\n%d->%d",vertex[u],u);
​  for(v=1;v<=n;v++)
​​ {
​​​if(!visited[v]&&cost[u][v]<distance[v])
​​​{
​​​​distance[v]=cost[u][v];
​​​​vertex[v]=u;
​​​}
​}
   }
   return sum;
}
void main()
{
inta[10][10],n,i,j,m,source;
printf("\n enter the  number of vertices:\n");
scanf("%d",&n);
printf("\nenter the cost matrix:\n 0-self loop and 999-no edge:\n");
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
scanf("%d",&a[i][j]);
printf("\n enter the source:\n");
scanf("%d",&source);
 m=prim(a,source,n);
printf("\n the cost of spanning tree=%d",m);
 }