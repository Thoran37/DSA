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
int count(struct node*f)
{
  int cnt=0;
  for(temp=f;temp!=NULL;temp=temp->link)
    cnt++;
  return cnt;  
}
void display(struct node*f)
{
  int size=count(f);
  int i,a[size];
  for(temp=f,i=0;temp!=NULL;temp=temp->link,i++)
    a[i]=temp->x;
  for(int j=i-1;j>=0;j--)
    printf("%d ",a[j]);  
}
void pop(struct node*f)
{
  if(f==NULL)
    printf("LQ is empty\n");
  else 
    {
      for(temp=first;temp!=last;temp=temp->link);
      temp->link=NULL;
      printf("Deleted element is %d\n",temp->x);
      free(last);
      last=temp;
    }  
}  
void push(int k)
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
  printf("1.create 2.delete 3.insert 4.display 5.count  ");
  do
    {
      scanf("%d",&choice);
      switch(choice)
        {
          case 1: first=create(first);break;
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
