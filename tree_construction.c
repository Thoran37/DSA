#include<stdio.h>
#include<stdlib.h>
int top=-1;
struct node
{
  struct node*llink;
  int x;
  struct node* rlink;
}*root=NULL,*temp,*nn,*stack;
void well()
{
  nn=(struct node*)malloc(sizeof(struct node));
  printf("Enter data  ");
  scanf("%d",&nn->x);
}
void push(struct node *k)
{
  stack[++top]=k;
}
struct node* pop()
{
  return stack[top--];
}
struct node* create_tree(struct node*f)
{
  char ch,s;
  do
    {
      well();
      if(root==NULL)
        {
          root=nn;
          temp=nn;
          temp->llink=NULL;
          temp->rlink=NULL;
        }
      else
        {
          printf("Enter side  ");
          scanf("%c",&ch);
          if(ch=='l')
            {
              temp->llink=nn;
              temp->rlink=NULL;
            }
          else if(ch=='r')
            {
              temp->rlink=nn;
              temp->llink=NULL;
            }
          else
            printf("Wrong side\n"); 
        }  
      printf("Continue main y/n  ");
      scanf("%c",&s); 
    }while(s=='y');
}
void display_inorder(struct node*f)
{
  struct node *ptr;
  ptr=root;
  push(NULL);
  while(ptr!=NULL)
    {
      push(ptr->x);
      ptr=ptr->llink;
    }   
  if(ptr==NULL)
  {
    ptr=pop();
    printf("%d ",ptr->x);
    ptr=ptr->rlink;
  }   
}
