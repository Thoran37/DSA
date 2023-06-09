#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 100
struct node
  {
    int x;
    struct node *l;
    struct node *r;
  }*root=NULL,*temp,*nn,*stack[size],*ptr,*nnn;
int top=-1;
void insert(int,int);
void del(int);
struct pointer
  {
    struct node *main;
    struct node *bef;
  }well;  
void push(struct node *k)
{
  stack[++top]=k;
}
struct node* pop()
{
	return stack[top--];
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
int bf(struct node *t)
{
  int r=height(t->l)-height(t->r);
  if(r>-2 && r<2)
    return 1;
  else 
    return 0;
}
void LL(struct node *node)
{
  struct node *k=node->l->r;
  nn=(struct node*)malloc(sizeof(struct node));
  if(node->r!=NULL)
    {
      nn->r=node->r;
      node->r=nn;
      nn->x=node->x;
      node->x=node->l->x;
      node->l=node->l->l;
      nn->l=NULL;
    }
  else  
    {
      nn->l=NULL;
      nn->r=NULL;
      node->r=nn;
      nn->x=node->x;
      node->x=node->l->x;
      node->l=node->l->l;
    }
  if(k!=NULL)  
    insert(k->x,0);  
} 
void RR(struct node *node)
{
  struct node *k=node->r->l;
  nn=(struct node*)malloc(sizeof(struct node));
  if(node->l!=NULL)
    {
      nn->l=node->l;
      node->l=nn;
      nn->r=NULL;
      nn->x=node->x;
      node->x=node->r->x;
      node->r=node->r->r;
    }
  else
    {
      nn->l=NULL;
      nn->r=NULL;
      node->l=nn;
      nn->x=node->x;
      node->x=node->r->x;
      node->r=node->r->r;
    }  
  if(k!=NULL)  
    insert(k->x,0);  
}
void LR(struct node *node)
{
  RR(node->l);
  LL(node);
}
void RL(struct node *node)
{
  LL(node->r);
  RR(node);
}
void insert(int k,int r)
{
  int flag,h,min=5;
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
              flag=0;
            }  
        }
      if(flag==1)
        ptr->r=nn;
      else
        ptr->l=nn;  
    }
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
					if(!bf(ptr))
            {
              h=height(ptr);
              if(h<min)
                {
                  min=h;
                  temp=ptr;
                } 
            }
					ptr=ptr->r;
				}			
		}    
  if(min!=5)
    {
      if(nn->x<temp->x && flag==0)
        LL(temp);
      else if(nn->x>temp->x && flag==1)
        RR(temp);
      else if(nn->x<temp->x && flag==1)  
        LR(temp);
      else if(nn->x>temp->x && flag==0)
        RL(temp);  
    }  
  if(r)
    {
      printf("Enter number to insert  ");
      scanf("%d",&k);
      if(k!=-1)
        insert(k,1); 
    }
}
void display(struct node *t)
{
	if(t==NULL)
	  return;
	display(t->l);
	display(t->r);	
	printf("%d ",t->x);
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
int delonechild(struct node *temp,struct node *ptr)
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
void delleaf(struct node*temp,struct node*ptr)
{
  if(ptr->r==temp)
    ptr->r=NULL;
  else if(ptr->l==temp)
    ptr->l=NULL;
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
void R_rotation(struct node *node)
{
  if(bf(node->l)==0)
    LL(node);
  else if(bf(node->l)==1)
    LL(node);
  else if(bf(node->l)==-1)
    LR(node);    
}
void L_rotation(struct node *node)
{
  if(bf(node->r)==0)
    RR(node);
  else if(bf(node->r)==-1)
    RR(node);
  else if(bf(node->r)==1)
    RL(node);    
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
              if(!bf(ptr))
                {
                  if(k>ptr->x)
                    R_rotation(ptr);
                  else
                    L_rotation(ptr);  
                }
              ptr=ptr->r;
            }			
        }
    }
  else
    printf("The element is not present in the tree\n");  
}
int main()
{
  int k;
  printf("1.Insert 2.Delete 3.Display 4.Height  ");
  do
    {
      scanf("%d",&k);
      switch(k)
        {
          case 1: printf("Enter -1 to stop inserting\n");
                  printf("Enter number to insert  ");
                  scanf("%d",&k);
                  insert(k,1);break;
          case 2: printf("Enter number to delete  ");
                  scanf("%d",&k);
                  del(k);break;
          case 3: display(root);break;
          case 4: printf("Height of tree is %d",height(root));break;
          default: printf("Invalid Choice\n");
        }
      printf("Continue main 1/0  ");
      scanf("%d",&k);  
    }while(k==1);
}
