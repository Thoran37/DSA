#include <stdio.h>
#include <stdlib.h>
#define size 100
struct node
  {
    int x;
    struct node *l,*r;
  }*root=NULL,*temp,*nn,*stack[size];
int top=-1;
void insert()
{
  int k,flag;
  struct node *ptr;
  do
    {
      printf("Enter number to insert  ");
      nn=(struct node*)malloc(sizeof(struct node));
      nn->l=NULL;
      nn->r=NULL;
      scanf("%d",&nn->x);
      if(root==NULL)
        root=nn;
      else
        {
          temp=root;
          while(temp!=NULL)
            {
              if(nn->x>temp->x)
                {
                  ptr=temp;
                  temp=temp->r;
                  flag=1;
                }
              else
                {
                  ptr=temp;
                  temp=temp->l;
                  flag=2;
                }  
            }
          if(flag==1)
            ptr->r=nn;
          else
            ptr->l=nn;  
        }
      printf("Continue insert 1/0  ");
      scanf("%d",&k);  
    }while(k==1);
}
void push(struct node *k)
{
  stack[++top]=k;
}
struct node* pop()
{
	return stack[top--];
}
void display()
{
  temp=root;
  push(NULL);
  while(temp!=NULL)
    {
      push(temp);
			temp=temp->l;
			while(temp==NULL)
			  {
			  	temp=pop();
			    printf("%d ",temp->x);	
			    temp=temp->r;
				}	
		}
}
int main()
{
  int k;
  printf("1.Insert 2.Display  ");
  do
    {
      scanf("%d",&k);
      switch(k)
        {
          case 1: insert();break;
          case 2: display();break;
          default: printf("Invalid choice\n");
        }
      printf("Continue main 1/0  ");
      scanf("%d",&k);
    }while(k==1);  
}
