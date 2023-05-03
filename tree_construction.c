#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node*llink;
  int x;
  struct node* rlink;
}*root=NULL,*temp,*nn;
void well()
{
  nn=(struct node*)malloc(sizeof(struct node));
  printf("Enter data  ");
  scanf("%d",&nn->x);
}
struct node* createtree(struct node*f)
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
void display(struct node*f)
{
  
}
