#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *link;
}*first=NULL,*temp,*nn,*last;
struct node* createll(struct node*f)
{
	char ch;
	do
	  {
	  	nn=(struct node*)malloc(sizeof(struct node));
	  	printf("Enter data");
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
			printf("Continue y/n  ");
			fflush(stdin);
			ch=getchar();  
		}while(ch=='y');
	temp->link=NULL;
	last=nn;	
	return f;
}
void insbeg()
{
	nn=(struct node*)malloc(sizeof(struct node));
  printf("Enter data");
  scanf("%d",&nn->x);
  if(first==NULL)
	  {
	  	first=nn;
	  	nn->link=NULL;
		}
	else
	  {
	    nn->link=first;
			first=nn;	
	  }	
}
void insend()
{
	nn=(struct node*)malloc(sizeof(struct node));
  printf("Enter data");
  scanf("%d",&nn->x);
	if(first==NULL)
	  {
	  	first=nn;
	  	nn->link=NULL;
		}
	else
	  {
	    last->link=nn;
			nn->link=NULL;
			last=nn;	
	  }	
}
int count()
{
	int cnt=0;
	if(first=NULL)
	  return 0;
	else
	  {
	    for(temp=first;temp!=NULL;temp=temp->link)
			  cnt++;
			return cnt;		
	  }  
}
void inspos()
{
	int pos,c,i;
	c=count();
	printf("Enter position  ");
	scanf("%d",&pos);
	if(pos==1)
	  insbeg();
	else if(pos==c+1)
	  insend();
	else if(pos>c+1)
	  printf("Invalid postion");
	else
	  {
  	  nn=(struct node*)malloc(sizeof(struct node));
      printf("Enter data");
  		scanf("%d",&nn->x);
  		for(temp=first,i=1;i<pos-1;i++,temp=temp->link);
  		nn->link=temp->link;
  		temp->link=nn;
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
			printf("Continue 1/0  ");
			scanf("%d",&k);	
		}while(k==1);
}
void delbeg()
{
	struct node *t;
	if(first==NULL)
	  printf("SLL is empty");
	else
	  {
	    t=first;
			first=first->link;	
	  }  
	t->link=NULL;
	free(t);  
}
void delend()
{
	struct node *t;
	if(first==NULL)
	  printf("SLL is empty");
	else
	  {
 		  for(temp=first;temp->link->link!=NULL;temp=temp->link);
  		t=temp->link;
  		temp->link=NULL;
  		free(t);
	  }  
}
void delpos()
{
	struct node *t;
	int i,c,pos;
	printf("Enter position  ");
	scanf("%d",&pos);
	if(c==0)
	  printf("SLL is empty");
	else if(pos==1)
	  delbeg();
	else if(pos==c)
	  delend();	  
	else if(pos>c)
	  printf("Invalid position");
	else
	  {
	    for(temp=first,i=1;i<pos-1;i++,temp=temp->link);
  		t=temp->link;
  		temp->link=t->link;
			t->link=NULL;
			free(t);	
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
			printf("Continue 1/0  ");
			scanf("%d",&k);	
		}while(k==1);
}
int search()
{
	int ele,flag;
	printf("Element to search");
	scanf("%d",&ele);
	if(first==NULL)
	  return 0;
	else
	  {
	    temp=first;
			flag=1;
			while(temp!=NULL)
			  {
			    if(ele==temp->x)
					  {						
						  flag=2;	
							break;
						}
					temp=temp->link;	
			  }	
			return flag;  
	  }  
}
void display(struct node *f)
{
	if(f==NULL)
	  printf("SLL is empty");
	else
    for(temp=f;temp!=NULL;temp=temp->link)
		  printf("%d  ",temp->x);	  
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
	      	case 1: first=createll(first);break;
	      	case 2: insert();break;
	      	case 3: del();break;
	      	case 4: ele=search();
							 		if(ele==0)
							 		  printf("SLL is empty");
							 		else if(ele==1)
									   printf("Element not found");
									else
									  printf("Element found");   
						      break;
	      	case 5: display(first);break;
				}
      printf("Continue 1/0  ");
      scanf("%d",&k);
    }while(k==1);
}
