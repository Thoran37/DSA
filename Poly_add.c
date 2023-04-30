#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x,h;
  struct node*link;
}*first1=NULL,*first2=NULL,*result=NULL,*temp,*nn;
struct node* create(struct node*f)
{
  printf("Enter -1 to stop\n");
  while(1)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      printf("Enter coeff and power  ");
      scanf("%d",&nn->x);
      if(nn->x==-1)
        break;
      scanf("%d",&nn->h);  
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
    }
  return f;  
}
void display(struct node*f)
{
  for(temp=f;temp->link!=NULL;temp=temp->link)
    printf("%dx^%d+",temp->x,temp->h);
  printf("%d",temp->x);
}
void poly_add(struct node*a,struct node*b)
{
  while(a!=NULL && b!=NULL)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      if(result==NULL)
        {
          result=nn;
          temp=nn;
        }
      else
        {
          temp->link=nn;
          temp=nn;
        }  
      if(a->h>b->h)
        {
          nn->x=a->x;
          nn->h=a->h;
          a=a->link;
        }  
      else if(a->h<b->h)
        {
          nn->x=b->x;
          nn->h=b->h;
          b=b->link;
        }    
      else
        {
          nn->x=a->x+b->x;
          nn->h=a->h;
          a=a->link;
          b=b->link;
        }  
    }
  while(a!=NULL)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      nn->x=a->x;
      nn->h=a->h;
      a=a->link;
      temp->link=nn;
      temp=nn;
    }  
  while(b!=NULL)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      nn->x=b->x;
      nn->h=b->h;
      b=b->link;
      temp->link=nn;
      temp=nn;
    }    
  temp->link=NULL;  
}
int main()
{
  first1=create(first1);
  first2=create(first2);
  poly_add(first1,first2);
  display(result);
}
