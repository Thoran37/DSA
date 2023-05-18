#include <stdio.h>
#include <stdlib.h>
#define size 300
struct node
{
	struct node *l,*r;
	char c;
}*root=NULL,*nn,*ptr,*stack[size];

struct traversal
{
	int k;
	struct node *add;
}*temp,*stack1[size];

int top=-1,top1=-1;

void well()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data  ");
	fflush(stdin);
	scanf("%c",&nn->c);
}
void push(struct node *k)
{
  stack[++top]=k;
}
struct node* pop()
{
	return stack[top--];
}
struct node *createbt(struct node *t)
{
	int k;
	push(NULL);
	well();
	t=nn;
	ptr=nn;
	while(ptr!=NULL)
	  {
	  	printf("Right child for %c 1/0  ",ptr->c);
	  	scanf("%d",&k);
	  	if(k==1)
	  	  {
	  	    well();
	  	  	ptr->r=nn;
	  	  	push(ptr->r);
				}
			else
			  ptr->r=NULL;
			printf("Left child for %c 1/0  ",ptr->c);
			scanf("%d",&k);
			if(k==1)
			  {
  			  well();
					ptr->l=nn;  	
					push(ptr->l);
				}		
			else
			  ptr->l=NULL;
			ptr=pop();		
		}
	return t;	
}
void in_non(struct node *f)
{
  ptr=f;
  push(NULL);
  while(ptr!=NULL)
    {
      push(ptr);
			ptr=ptr->l;
			while(ptr==NULL)
			  {
			  	ptr=pop();
			    printf("%c ",ptr->c);	
			    ptr=ptr->r;
				}	
		}
}
void pre_non(struct node *t)
{
	ptr=t;
	push(NULL);
	while(ptr!=NULL)
	  {
	  	printf("%c ",ptr->c);
	  	if(ptr->r!=NULL)
        push(ptr->r);
      ptr=ptr->l;
	  	if(ptr==NULL)
    	  ptr=pop();
		}
}
void push1(int l,struct node *f)
{
	stack1[++top1]->k=l;
	stack1[top1]->add=f;
}
struct traversal* pop1()
{
	return stack1[top1--];
}
void post_non(struct node *t)
{	
	ptr=t;
	push1(1,NULL);
	do
	  {
			while(ptr!=NULL)
			 {
			 	 push1(1,ptr);
			 	 if(ptr->r!=NULL)
			 	   push1(0,ptr->r);
			 	 ptr=ptr->l;
			 }
		  temp=pop1();
		  ptr=temp->add;
			while(temp->k==1)
			  {
			    printf("%c ",ptr->c);
					temp=pop1();
		      ptr=temp->add;	
				}	
			if(temp->k==0)
				push1(1,ptr);	
		}while(stack1[top1]!=NULL);
}
int countln(struct node *t)
{
	int cnt=0;
	ptr=t;
	push(NULL);
	while(ptr!=NULL)
	  {
	  	if((ptr->r==NULL) && (ptr->l==NULL))
				cnt++;
	  	if(ptr->r!=NULL)
        push(ptr->r);
      ptr=ptr->l;
	  	if(ptr==NULL)
    	  ptr=pop();
		}
	return cnt;	
}
int countnln(struct node *t)
{
	int cnt=0;
	ptr=t;
	push(NULL);
	while(ptr!=NULL)
	  {
	  	if((ptr->r==NULL) && (ptr->l==NULL));
			else
				cnt++;
	  	if(ptr->r!=NULL)
        push(ptr->r);
      ptr=ptr->l;
	  	if(ptr==NULL)
    	  ptr=pop();
		}
	return cnt;	
}
int height(struct node *t)
{
	
}
int main()
{
	int k;
	printf("1.create 2.inorder 3.preorder 4.postorder 5.in_non 6.pre_non 7.post_non 8.height 9.leaf 10.non_leaf  ");
	do
	  {
	  	scanf("%d",&k);
	  	switch(k)
	  	  {
	  	  	case 1: root=createbt(root);break;
	  	  	//case 2: inorder(root);break;
	  	  	//case 3: preorder(root);break;
	  	  	//case 4: postorder(root);break;
	  	  	case 5: in_non(root);break;
	  	  	case 6: pre_non(root);break;
	  	  	case 7: post_non(root);break;
	  	  	//case 8: printf("Height = %d\n",height());break;
	  	  	case 9: printf("No.of leaf node = %d\n",countln(root));break;
	  	  	case 10: printf("No.of non leaf node = %d\n",countnln(root));break;
	  	  	default: printf("Wrong choice\n");
				}
			printf("Continue main 1/0  ");
			scanf("%d",&k);
		}while(k==1);
}
