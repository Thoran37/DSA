#include <stdio.h>

int graph[25][25]={0},n,status[25]={0};
int queue[25],f=0,r=-1;
int visit[25][25]={0},stack[25],top=-1;

void enque(int k)
{
	queue[++r]=k;
}

int deque()
{
	return queue[f++];
}

void push(int k)
{
	stack[++top]=k;
}

int pop()
{
	return stack[top--];
}

int main()
{
	int index;
	printf("Enter no.of vertices  ");
	scanf("%d",&n);
//	printf("Enter matrix of input graph\n");
//	for(int i=0;i<n;i++)
//	  for(int j=0;j<n;j++)
//	    scanf("%d",&a[i][j]);
	printf("Enter -1 to stop\n");
	printf("Enter source and destination of the edge  ");
	do
	  {
			scanf("%d",&a);
			if(a==-1)
			  break;
			scanf("%d",&b);
			graph[a][b]=1;	  	
		}while(1);    
	printf("Enter starting vertex index  ");
	scanf("%d",&index);
	enque(index);
	status[index]++;
	while(isempty())
	  {
			h=deque(); 	
			status[h]++;
			push(h);
			for(int i=0;i<n;i++)
			  if(graph[h][i] && status[i]==0)
			    {
			      enque(i);
			      status[i]++;
			    }
	  }   
}
