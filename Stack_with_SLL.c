#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x;
  struct node*link;
}*temp,*nn,*top=NULL;
int count()
{
  int cnt=0;
  for(temp=top;temp!=NULL;temp=temp->link)
    cnt++;
  return cnt;  
}
void display()
{
  for(temp=top;temp!=NULL;temp=temp->link)
    printf("%d ",temp->x);  
}
void pop()
{
  if(f==NULL)
    printf("Stack is empty\n");
  else 
    {
      temp=top;
      top=top->link;
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
      top=nn;
      top->link=NULL;
    }
  else
    {  
      nn->link=top;
      top=nn;
    }
	nn->x=k;
}
int main()
{
  int k,choice;
  printf("1.insert 2.delete 3.display 4.count  ");
  do
    {
      scanf("%d",&choice);
      switch(choice)
        {
          case 2: pop();break;
          case 1: printf("Enter element to insert  ");
                  scanf("%d",&k);
                  push(k);break;
          case 3: display();break;        
          case 4: printf("No.of elements = %d\n",count());break;
          default: printf("Wrong choice\n");        
        }
      printf("Continue 1/0  ");
      scanf("%d",&k);  
    }while(k==1);
}
