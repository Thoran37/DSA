#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int find(int k)
{
  temp=root;
  push(NULL);
  while(temp!=NULL || top!=-1)
    {
	  while(temp!=NULL)
		{
		  push(temp);
		  temp=temp->l;
		}
	  temp=pop();
	  if(temp!=NULL)
		{
		  if(temp->x==k)
		    return 1;
		  temp=temp->r;
		}			
	}
  return 0;	
}
int del(int k)
{
  int flag;
  temp=root;
  push(NULL);
  while(temp!=NULL)
    {
      push(temp);
      ptr=temp;
	  temp=temp->l;
      flag=0;
	  while(temp==NULL)
	    {
	  	  temp=pop();
	      if(temp->x==k)
            {
		      if((temp->l==NULL) && (temp->r==NULL))
		        {
		          if(flag==0)
		            ptr->l=NULL;
		          else
		            ptr->r=NULL;  
		          printf("Deleted element is %d\n",temp->x);    
		        }
		      else if((temp->l==NULL) && (temp->r!=NULL) && (ptr->r==temp))
		        ptr->r=temp->r;
		      else if((temp->l!=NULL) && (temp->r==NULL) && (ptr->r==temp))
		        ptr->r=temp->l;
		      else if((temp->l==NULL) && (temp->r!=NULL) && (ptr->l==temp))  
		        ptr->l=temp->r;  
		      else if((temp->l!=NULL) && (temp->r==NULL) && (ptr->l==temp))  
		        ptr->l=temp->l;    
		      else
			    {
			      ptr->	
				}  
		    }
          ptr=temp;
		  temp=temp->r;
          flag=1;
		}	
	}
}
void inorder(struct node *t)
{
	if(t==NULL)
	  return;
	inorder(t->l);
	printf("%d ",t->x);
	inorder(t->r);	
}
int main()
{
  int k;
  printf("1.Insert 2.Display 3.Find 4.Delete ");
  do
    {
      scanf("%d",&k);
      switch(k)
        {
          case 1: insert();break;
          case 2: inorder(root);break;
          case 3: printf("Enter number to find  ");
		  		  scanf("%d",&k);
		  		  if(find(k))
		  		    printf("The number is available\n");
		  		  else
					printf("The number is not in the tree\n");break;  
          default: printf("Invalid choice\n");
        }
      printf("Continue main 1/0  ");
      scanf("%d",&k);
    }while(k==1);  
}
