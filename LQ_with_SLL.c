#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x;
  struct node*link;
}*first=NULL,*temp,*nn,*last=NULL;
struct node* create(struct node*f)
{ 
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
      last=temp;
    }
  return f;  
}
void display(struct node*f)
{
  for(temp=f;temp!=NULL;temp=temp->link)
    printf("%d ",temp->x);
}
struct node* del(struct node*f)
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
void ins(int k)
{
  nn=(struct node*)malloc(sizeof(struct node));
  if(first==NULL)
    {
      first=nn;
      nn->x=k;
      first->link=NULL;
      last=nn;
    }
  else
    {  
      last->link=nn;
      nn->x=k;
      last=nn;
      last->link=NULL;
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
          case 1: first=create(first);break;
          case 2: first=del(first);break;
          case 3: printf("Enter element to insert  ");
                  scanf("%d",&k);
                  ins(k);break;
          case 4: display(first);break;        
          default: printf("Wrong choice\n");        
        }
      printf("Continue 1/0  ");
      scanf("%d",&k);  
    }while(k==1);
}