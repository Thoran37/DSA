#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x,h;
	struct node *link;
}*first1=NULL,*temp,*nn,*first2=NULL;
struct node* create(struct node*f)
{
	int k,i=0;
	do
	  {
	  	nn=(struct node*)malloc(sizeof(struct node));
			printf("Enter coefficients  ");
			scanf("%d",&nn->x);
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
      nn->h=i;
      i++;  
			printf("Continue coefficients 1/0  ");
			scanf("%d",&k);
		}while(k==1);
	temp->link=NULL;
	return f;
}
void add(struct node*a,struct node*b)
{
  struct node*t;
  int flag=0;
  while(1)
    {
      if(a->h==b->h)
        a->x=a->x+b->x;
      if(a->link==NULL)
        t=a;  
      a=a->link;
      b=b->link;  
      if(a==NULL || b==NULL)
        break;
    }
  while(b!=NULL)
    {
      nn=(struct node*)malloc(sizeof(struct node));
      t->link=nn;
      nn->x=b->x;
      nn->h=b->h;
      b=b->link;
      flag=1;
    }
  if(flag==1)  
    t->link->link=NULL;  
}
int main()
{
  first1=create(first1);
  first2=create(first2);
  add(first1,first2);
  printf("%d",first1->x);
  for(temp=first1->link;temp!=NULL;temp=temp->link)
    printf("+%dx^%d",temp->x,temp->h);
}
