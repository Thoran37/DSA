#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x,pow;
	struct node *link;
}*first1=NULL,*temp,*nn,*first2=NULL,*nnn,*rs=NULL;
struct node* create(struct node*f)
{
	int k,i;
	do
	  {
	  	nn=(struct node*)malloc(sizeof(struct node));
			printf("Enter coefficients and power ");
			scanf("%d%d",&nn->x,&nn->pow);
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
      
			printf("Continue coefficients 1/0  ");
			scanf("%d",&k);
		}while(k==1);
	temp->link=NULL;
	return f;
}
void display(struct node*f)
{
	for(temp=f;temp!=NULL;temp=temp->link)
	  printf("%dx^%d+",temp->x,temp->pow); 
}
void add(struct node*a,struct node*b)
{
  struct node*t;
  while(a!=NULL && b!=NULL)
    {
			nnn=(struct node*)malloc(sizeof(struct node));
			if(a->pow>b->pow)
			  {
			  	nnn->pow=a->pow;
			  	nnn->x=a->x;
			  	a=a->link;
				}
      else
			   if(b->pow>a->pow)
				   {nnn->pow=b->pow;
			  	nnn->x=b->x;
			  	b=b->link;
					 }	
				else
				  {
				  	nnn->pow=a->pow;
			  	nnn->x=a->x+b->x;
			  	a=a->link;
			  	b=b->link;
								}		  
			if(rs==NULL)
			  {
				  rs=nnn; 
			    temp=rs;
			  }
			else
			  {
				 temp->link=nnn;
				 temp=nnn;	
		
       }
       temp->link=NULL;
  }
  while(a!=NULL)
    {
      nnn=(struct node*)malloc(sizeof(struct node));
      temp->link=nnn;
      temp=nnn;
      temp->x=a->x;
      temp->pow=a->pow;
      a=a->link;
    }
  while(b!=NULL)
    {
      nnn=(struct node*)malloc(sizeof(struct node));
      temp->link=nnn;
      temp=nnn;
      temp->x=b->x;
      temp->pow=b->pow;
      b=b->link;
    }
	 temp->link=NULL;
}
int main()
{
  first1=create(first1);
   display(first1);
  first2=create(first2);
  display(first2);
  add(first1,first2);
  display(rs);
}
