#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x;
  struct node*link;
}*front=NULL,*temp,*nn,*rear=NULL;
struct node* create(struct node*f)
{ 
	printf("Enter -1 to stop\n");
  while(1)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      printf("Enter data  ");
      scanf("%d",&nn->x);
      if(nn->x==-1)
        break;
      if(f==NULL)
        {
          f=nn;
          temp=nn;
        }
      else
        {
          temp->link=nn;
          temp=nn;
        }
      temp->link=NULL;  
      rear=temp;
    }
  return f;  
}
int count(struct node*f)
{
  int cnt=0;
  for(temp=f;temp!=NULL;temp=temp->link)
    cnt++;
  return cnt; 
}
void display(struct node*f)
{
  for(temp=f;temp!=NULL;temp=temp->link)
    printf("%d ",temp->x);
}
struct node* deque(struct node*f)
{
  if(f==NULL)
    printf("LQ is empty\n");
  else 
    {
      temp=f;
      f=f->link;
      temp->link=NULL;
      printf("Deleted element is %d\n",temp->x);
      free(temp);
    }
  return f;  
}  
void enque(int k)
{
  nn=(struct node*)malloc(sizeof(struct node));
  nn->x=k;	
  nn->link=NULL;	
  if(front==NULL)
    {
      front=nn;
      rear=nn;
    }
  else
    {  
      rear->link=nn;
      rear=nn;
    }
}
int main()
{
  int k,choice;
  printf("1.create 2.delete 3.insert 4.display  ");
  do
    {
      scanf("%d",&choice);
      switch(choice)
        {
          case 1: front=create(front);break;
          case 2: front=deque(front);break;
          case 3: printf("Enter element to insert  ");
                  scanf("%d",&k);
                  enque(k);break;
          case 4: display(front);break;   
          case 5: printf("No.of elements = %d",count(front));break;
          default: printf("Wrong choice\n");        
        }
      printf("Continue 1/0  ");
      scanf("%d",&k);  
    }while(k==1);
}
