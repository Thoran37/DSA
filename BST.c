#include <stdio.h>
#include <stdlib.h>
#define size 100
struct node
  {
    int x;
    struct node *l;
    struct node *r;
  }*root=NULL,*temp,*nn,*stack[size],*ptr;
struct pointer
  {
    struct node *main;
    struct node *bef;
  }well;  
int top=-1;
void del(int);
void insert(int k)
{
  int flag;
  nn=(struct node*)malloc(sizeof(struct node));
  nn->l=NULL;
  nn->r=NULL;
  nn->x=k;
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
  if(k==1)
    {
      printf("Enter number to insert  ");
      scanf("%d",&k);
      insert(k);
    }
}
void push(struct node *k)
{
  stack[++top]=k;
}
struct node* pop()
{
	return stack[top--];
}
struct pointer find(int k)
{
  temp=root;
  well.main=NULL;
  well.bef=NULL;
  push(NULL);
  while(temp!=NULL || top!=-1)
    {
      while(temp!=NULL)
        {
          push(temp);
          if(temp->x==k)
            well.bef=ptr;
          ptr=temp;
          temp=temp->l;
        }
      temp=pop();
      if(temp!=NULL)
        {
          if(temp->x==k)
            {
              well.main=temp;
              return well;
            }
          ptr=temp;  
          temp=temp->r;
        }			
	  }
  return well;  
}
void delleaf(struct node*temp,struct node*ptr)
{
  if(ptr->r==temp)
    ptr->r=NULL;
  else if(ptr->l==temp)
    ptr->l=NULL;
  free(temp);    
}
void delonechild(struct node *temp,struct node *ptr)
{
  if((temp->l==NULL) && (temp->r!=NULL) && (ptr->r==temp))
    {
      ptr->r=temp->r;
      temp->r=NULL;
    }
  else if((temp->l!=NULL) && (temp->r==NULL) && (ptr->r==temp))
    {
      ptr->r=temp->l;
      temp->l=NULL;
    }
  else if((temp->l==NULL) && (temp->r!=NULL) && (ptr->l==temp))  
    {
      ptr->l=temp->r;  
      temp->r=NULL;
    }
  else if((temp->l!=NULL) && (temp->r==NULL) && (ptr->l==temp))  
    {  
      ptr->l=temp->l;    
      temp->l=NULL;
    }
  free(temp);  
}
void deltwochild(struct node *temp)
{
  int k,flag,j;
  ptr=root;
  push(NULL);
	while(ptr!=NULL || top!=-1)
	  {
			while(ptr!=NULL)
				{
					push(ptr);
					ptr=ptr->l;
				}
			ptr=pop();
			if(ptr!=NULL)
				{
          if(k==1)
            {
              j=ptr->x;
              del(ptr->x);
              flag=1;
              break;
            }
					if(ptr->x==temp->x)
            k=1;
					ptr=ptr->r;
				}			
		}
  if(flag==1)
    temp->x=j;  
}
void del(int k)
{
  struct pointer t=find(k);
  temp=t.main;
  ptr=t.bef;
  if(temp!=NULL)
    {
      if(temp->r==NULL && temp->l==NULL)
        delleaf(temp,ptr);
      else if(temp->r!=NULL && temp->l!=NULL)
        deltwochild(temp);
      else
        delonechild(temp,ptr);    
    }
  else
    printf("The element is not present in the tree\n");  
}
int height(struct node *t)
{
	int left,right;
	if(t!=NULL)
	  {
	  	left=height(t->l);
	  	right=height(t->r);
	  	if(left>right)
	  	  return left+1;
	  	else
		    return right+1;  
		}
	else
	  return 0;	
}
void inorder(struct node *t)
{
	if(t==NULL)
	  return;
	inorder(t->l);
	printf("%d ",t->x);
	inorder(t->r);	
}
void preorder(struct node *t)
{
	if(t==NULL)
	  return;
	printf("%d ",t->x);
	preorder(t->l);	
	preorder(t->r);	
}
void postorder(struct node *t)
{
	if(t==NULL)
	  return;
	postorder(t->l);	
	postorder(t->r);
	printf("%d ",t->x);	
}
int main()
{
  int k;
  printf("1.Insert 2.Inorder 3.preorder 4.postorder 5.Height 6.Delete ");
  do
    {
      scanf("%d",&k);
      switch(k)
        {
          case 1: printf("Enter number to insert  ");
                  scanf("%d",&k);
                  insert(k);break;
          case 2: inorder(root);break;
          case 3: preorder(root);break;
          case 4: postorder(root);break;
          case 5: printf("Height = %d\n",height(root)); break;
          case 6: printf("Enter number to delete  ");
                  scanf("%d",&k);
                  del(k);break;
          default: printf("Invalid choice\n");
        }
      printf("Continue main 1/0  ");
      scanf("%d",&k);
    }while(k==1);  
}
