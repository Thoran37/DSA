#include <stdio.h>

int graph[25][25]={0},status[25]={0};
int queue[25];
int visit[25][25]={0},stack[25],top=-1;

void push(int k)
{
	stack[++top]=k;
}

int pop()
{
	return stack[top--];
}

int isempty()
{
	if(top==-1)
	  return 0;
	else
	  return 1;  
}

int main()
{
	int index,d,a,b,h,i,j,p,n,f=0;
	printf("Enter no.of vertices and edges  ");
	scanf("%d%d",&n,&p);
	printf("Enter source and destination of the edge  ");
	while(p--)
	  {
			scanf("%d%d",&a,&b);
			graph[a][b]=1;	  
			graph[b][a]=1;	
		}
	printf("Enter starting vertex index  ");
	scanf("%d",&index);
	push(index);
	status[index]++;
	while(isempty())
	  {
			h=pop(); 	
			status[h]++;
			queue[f++]=h;
			for(i=0;i<n;i++)
			  if(graph[h][i] && status[i]==0)
			    {
			      push(i);
			      status[i]++;
			    }
	  }	
	for(i=0;i<f-1;i++)  
	  {
	  	d=0;
	  	while(graph[queue[i-d]][queue[i+1]]==0)
	  	  d++;
  	  visit[queue[i-d]][queue[i+1]]=1;
  	  visit[queue[i+1]][queue[i-d]]=1;
		}
	for(i=0;i<n;i++)
	  {
	    for(j=0;j<n;j++)
		    printf("%d ",visit[i][j]);
		  printf("\n");		
		}
}
