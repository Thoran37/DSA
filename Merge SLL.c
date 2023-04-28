#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *link;
}*first1=NULL,*temp,*nn,*first2=NULL;
struct node* create(struct node*f)
{
	int k;
	do
	  {
	  	nn=(struct node*)malloc(sizeof(struct node));
			printf("Enter data  ");
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
			printf("Continue create 1/0  ");
			scanf("%d",&k);
		}while(k==1);
	temp->link=NULL;
	return f;
}
void merge()
{
	struct node*t;
	temp=first1;
	while(temp!=NULL)
	  {
	  	t=first2;
	  	first2=first2->link;
	  	t->link=temp->link;
	  	temp->link=t;
	  	temp=temp->link->link;
		}
	if(first2!=NULL)
	  t->link=first2;	
}
int main()
{
	first1=create(first1);
	first2=create(first2);
	merge();
  for(temp=first1;temp!=NULL;temp=temp->link)
    printf("%d  ",temp->x);
}
