#include <stdio.h>

int graph[25][25]={0},status[25]={0};
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

int isempty()
{
	if(f>r)
	  return 0;
	else
	  return 1;  
}

int main()
{
	int index,d,a,b,h,i,j,p,n;
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
	enque(index);
	status[index]++;
	while(isempty())
	  {
			h=deque(); 	
			status[h]++;
			push(h);
			for(i=0;i<n;i++)
			  if(graph[h][i] && status[i]==0)
			    {
			      enque(i);
			      status[i]++;
			    }
	  }
	for(i=0;i<top;i++)  
	  {
	  	d=0;
	  	while(graph[stack[i-d]][stack[i+1]]==0)
	  	  d++;
  	  visit[stack[i-d]][stack[i+1]]=1;
  	  visit[stack[i+1]][stack[i-d]]=1;
		}
	for(i=0;i<n;i++)
	  {
	    for(j=0;j<n;j++)
		    printf("%d ",visit[i][j]);
		  printf("\n");		
		}
}
