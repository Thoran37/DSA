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
	top++;
  *(stack+top)=*k;
}
struct node* pop()
{
	struct node *p=(stack+top);
  top--;
  return p;
}
struct node* create_tree(struct node*f)
{
  char ch,s;
  do
    {
      if(root==NULL)
        {
        	well();
          root=nn;
          temp=nn;
          temp->llink=NULL;
          temp->rlink=NULL;
        }
      else
        {
          printf("Enter side  ");
          fflush(stdin);
          ch=getchar();
          well();
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
			fflush(stdin); 
      s=getchar();
    }while(s=='y');
}
void display_inorder(struct node*f)
{
  struct node *ptr;
  ptr=root;
  push(NULL);
  while(ptr!=NULL)
    {
      push(ptr);
      ptr=ptr->llink;
    }   
  if(ptr==NULL)
  {
    ptr=pop();
    printf("%d ",ptr->x);
    ptr=ptr->rlink;
  }   
}
int main()
{
	root=create_tree(root);
	display_inorder(root);
}
