#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *link;
}*first=NULL,*temp,*nn,*last;
void create()
{
	int k;
	do
	  {
	  	nn=(struct node*)malloc(sizeof(struct node));
			printf("Enter data  ");
			scanf("%d",&nn->x);
	  	if(first==NULL)
	  	  {
	  	  	first=nn;
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
	last=nn;
}
void reverse()
{
	struct node*t;
	if(first==NULL)
	  printf("SLL is empty");
	else
	  {
	  	t=last;
			while(t!=first)
			  {
			    for(temp=first;temp->link!=t;temp=temp->link);
			    t->link=temp;
			    t=temp;
				}
			t->link=NULL;	
			t=last;
			first=last;
		}  
}
int main()
{
	create();
	reverse();
  for(temp=first;temp!=NULL;temp=temp->link)
    printf("%d  ",temp->x);
}
