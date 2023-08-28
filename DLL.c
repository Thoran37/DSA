#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *llink;
	int x;
	struct node *rlink;
}*first=NULL,*temp,*nn,*last;
void well()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data  ");
	scanf("%d",&nn->x);
}
struct node* createdll(struct node*f)
{
	int k;
	do
	  {
	  	well();
	  	if(f==NULL)
	  	  {
	  	  	f=nn;
	  	  	temp=nn;
	  	  	f->llink=NULL;
	  	  	f->rlink=NULL;
				}
			else
			  {
			    temp->rlink=nn;
					nn->llink=temp;
					temp=nn;
			  }	
			printf("Continue create 1/0  ");
			scanf("%d",&k)
		}while(k==1);
	temp->rlink=NULL;
	last=nn;	
	return f;
}
void display(struct node*f)
{
	if(f==NULL)
	  printf("DLL is empty");
	else
		for(temp=first;temp!=NULL;temp=temp->rlink)  
		  printf("%d ",temp->x);  
}
void search()
{
	int ele,flag=0;
	printf("Enter element to search  ");
	scanf("%d",&ele);
	if(first==NULL)
	  printf("DLL is empty");
	else
	  for(temp=first;temp!=NULL;temp=temp->rlink)
	    if(temp->x==ele)
	      {
				  printf("Element found");
					flag=1;
					break;
				}
	if(flag==0)
	  printf("Element not found");			
			  	
}
int count()
{
	int i;
	if(first==NULL)
	  return 0;
	else
		for(i=0,temp=first;temp!=NULL;i++,temp=temp->rlink);
		  return i; 
}
void insend()
{
	well();
	if(first==NULL)
	  {
	  	first=nn;
	  	first->llink=NULL;
	  	first->rlink=NULL;
		}
	else
	  {
	    last->rlink=nn;
			nn->llink=last;
			last=nn;
			last->rlink=NULL;	
		}	
}
void insbeg()
{
	well();
	if(first==NULL)
	  {
	  	first=nn;
	  	first->llink=NULL;
	  	first->rlink=NULL;
		}
	else
	  {
	  	nn->rlink=first;
	  	first->llink=nn;
	  	first=nn;
	  	first->llink=NULL;
		}
}
void inspos()
{
	int i,c,pos;
	c=count();
	printf("Enter position  ");
	scanf("%d",&pos);
	if(pos==1)
	  insbeg();
	else if(pos==c+1)
	  insend();
	else if( pos>c+1)
	  printf("Invalid position");
	else
	  {
	    well();
			for(temp=first,i=1;i<pos-1;i++,temp=temp->rlink);	
			temp->rlink->llink=nn;
			nn->rlink=temp->rlink;
			temp->rlink=nn;
			nn->llink=temp;
		}		  
}
void insert()
{
	int choice,k;
	do
	 {
		 	printf("1.Beg 2.End 3.Pos  ");
		 	scanf("%d",&choice);
		 	switch(choice)
		 	 {
		 	 	 case 1: insbeg();break;
		 	 	 case 2: insend();break;
		 	 	 case 3: inspos();break;
		 	 	 default: printf("Wrong choice");
			 }
			printf("Continue insert 1/0  ");
			scanf("%d",&k);	
		}while(k==1);
}
void delend()
{
	struct node *t;
	last->llink->rlink=NULL;
	t=last;
	last=last->llink;
	t->llink=NULL;
	free(t);
}
void delbeg()
{
	struct node*t;
	first->rlink->llink=NULL;
	t=first;
	first=first->rlink;
	t->rlink=NULL;
	free(t);
}
void delpos()
{
	int i,c,pos;
	c=count();
	printf("Enter position  ");
	scanf("%d",&pos);
	if(pos==1)
	  delbeg();
	else if(pos==c)
	  delend();
	else if(pos>c)
	  printf("Invalid position");
	else
	  {
			for(temp=first,i=0;i<pos;i++,temp=temp->rlink);
			temp->llink->rlink=temp->rlink;
			temp->rlink->llink=temp->llink;
			temp->rlink=NULL;
			temp->llink=NULL;
			free(temp);
    } 	  
}
void del()
{
	int choice,k;
	do
	 {
		 	printf("1.Beg 2.End 3.Pos  ");
		 	scanf("%d",&choice);
		 	switch(choice)
		 	 {
		 	 	 case 1: delbeg();break;
		 	 	 case 2: delend();break;
		 	 	 case 3: delpos();break;
		 	 	 default: printf("Wrong choice");
			 }
			printf("Continue delete 1/0  ");
			scanf("%d",&k);	
		}while(k==1);
}
int main()
{
	int choice,k,f,ele;
	printf("1.create 2.insert 3.delete 4.search 5.dislpay  ");
	do
	 {
		 scanf("%d",&choice);
		 switch(choice)
			 {
			   case 1: first=createdll(first);break;
			   case 2: insert();break;
			   case 3: del();break;
			 	 case 4: search();break;
			   case 5: display(first);break;
			 }
	   printf("Continue main 1/0  ");
	   scanf("%d",&k);
	 }while(k==1);
}
