#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x,h;
	struct node *link;
}*first1=NULL,*temp,*nn,*first2=NULL,*nnn,*rs=NULL;
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
void display(struct node*f)
{
	for(temp=f;temp!=NULL;temp=temp->link)
	  printf("%dx^%d+",temp->x,temp->h); 
}
void mul(struct node*a,struct node*b)
{
	struct node*t,*r;
	for(temp=b;temp!=NULL;temp=temp->link)
	  {
	    nnn=(struct node*)malloc(sizeof(struct node));
	    if(rs==NULL)
	      rs=nnn;
	  	for(t=a;t!=NULL;t=t->link)
	  	  {
	  	  	nnn->x=t->x*temp->x;
	    	  nnn->h=t->h+temp->h;
				}
			if(r!=nnn)
			  r->link=nnn;
			r=nnn;		
		}
	r->link=NULL;	
}
int main()
{
	first1=create(first1);
	first2=create(first2);
	mul(first1,first2);
	display(rs);
}
