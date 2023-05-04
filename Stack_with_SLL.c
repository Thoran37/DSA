#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x;
  struct node*link;
}*first=NULL,*temp,*nn,*last=NULL;
void create()
{ 
	printf("Enter -1 to stop\n");
  while(1)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      printf("Enter data  ");
      scanf("%d",&nn->x);
      if(nn->x==-1)
        break;
      if(first==NULL)
        {
        	first=nn;
          last=nn;
          last->link=NULL;
        }
      else
        {
          nn->link=last;
          last=nn;
        }
    }
}
int count(struct node*f)
{
  int cnt=0;
  for(temp=last;temp!=NULL;temp=temp->link)
    cnt++;
  return cnt;  
}
void display(struct node*f)
{
  for(temp=last;temp!=NULL;temp=temp->link)
    printf("%d ",temp->x);  
}
void pop(struct node*f)
{
  if(f==NULL)
    printf("LQ is empty\n");
  else 
    {
      temp=last;
      last=last->link;
      temp->link=NULL;
      printf("Deleted element is %d\n",temp->x);
      free(temp);
    }  
}  
void push(int k)
{
  nn=(struct node*)malloc(sizeof(struct node));
  if(first==NULL)
    {
      first=nn;
      last=nn;
      last->link=NULL;
    }
  else
    {  
      nn->link=last;
      nn->x=k;
      last=nn;
    }
}
int main()
{
  int k,choice;
  printf("1.create 2.delete 3.insert 4.display 5.count  ");
  do
    {
      scanf("%d",&choice);
      switch(choice)
        {
          case 1: create();break;
          case 2: pop(first);break;
          case 3: printf("Enter element to insert  ");
                  scanf("%d",&k);
                  push(k);break;
          case 4: display(first);break;        
          case 5: printf("No.of elements = %d\n",count(first));break;
          default: printf("Wrong choice\n");        
        }
      printf("Continue 1/0  ");
      scanf("%d",&k);  
    }while(k==1);
}
