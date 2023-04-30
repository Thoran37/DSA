#include<stdio.h>
#include<stdlib.h>
struct node
{
  int x,h;
  struct node*link;
}*first=NULL,*second=NULL,*result=NULL,*temp,*nn;
struct node* create(struct node*f)
{
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
  printf("%dx^%d",temp->x,temp->h);
}
void poly_mul(struct node*a,struct node*b)
{
  struct node*p,*q,*t;
  for(p=b;p!=NULL;p=p->link)
    {
      for(q=a;q!=NULL;q=q->link)
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
          temp->x=p->x*q->x;
          temp->h=p->h+q->h;
        }
      temp->link=NULL;  
    }
  for(p=result;p!=NULL;p=p->link)
    for(q=p->link;q!=NULL;) 
      { 
        if(p->h==q->h)
          {
            p->x+=q->x;
            p->link=q->link;
            t=q;
            q=q->link;
            t->link=NULL;
            free(t);
          }
        else
          q=q->link;
      }  
}
int main()
{
  printf("Enter -1 to stop\n");
  first=create(first);
  second=create(second);
  poly_mul(first,second);
  display(result);
}
