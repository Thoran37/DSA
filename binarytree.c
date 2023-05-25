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
	push1(1,NULL);
	ptr=t;
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
			while(temp->k==1 && ptr!=NULL)
			  {
					printf("%c ",ptr->c);
					temp=pop1();
					ptr=temp->add;
				}
		}while(ptr!=NULL);
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
	ptr=pop();
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
	ptr=pop();	
	return cnt;	
}
int height(struct node *t)
{
	int cnt=0,max=0;
	ptr=t;
	push(NULL);
	while(ptr!=NULL)
	  {
			push(ptr);
			cnt++;
			ptr=ptr->l;
			while(ptr==NULL)
			  {
					ptr=pop();
					if(ptr==root)
					  cnt=0;
					else if(ptr->r!=NULL)
					  cnt--;
					ptr=ptr->r;
					if(cnt>max)
					  max=cnt;
				}
		}	
	return max-1;	
}
void inorder(struct node *t)
{
	if(t==NULL)
	  return;
	inorder(t->l);
	printf("%c ",t->c);
	inorder(t->r);	
}
void preorder(struct node *t)
{
	if(t==NULL)
	  return;
	printf("%c ",t->c);
	preorder(t->l);	
	preorder(t->r);	
}
void postorder(struct node *t)
{
	if(t==NULL)
	  return;
	postorder(t->l);	
	postorder(t->r);
	printf("%c ",t->c);	
}
int main()
{
	int k,choice;
	printf("1.create 2.inorder 3.preorder 4.postorder 5.in_non 6.pre_non 7.post_non 8.height 9.leaf 10.non_leaf  ");
	do
	  {
	  	scanf("%d",&choice);
	  	switch(choice)
	  	  {
	  	  	case 1: root=createbt(root);break;
	  	  	case 2: inorder(root);break;
	  	  	case 3: preorder(root);break;
	  	  	case 4: postorder(root);break;
	  	  	case 5: in_non(root);break;
	  	  	case 6: pre_non(root);break;
	  	  	case 7: post_non(root);break;
	  	  	case 8: printf("Height = %d\n",height(root));break;
	  	  	case 9: printf("No.of leaf node = %d\n",countln(root));break;
	  	  	case 10: printf("No.of non leaf node = %d\n",countnln(root));break;
	  	  	default: printf("Wrong choice\n");
				}
			printf("Continue main 1/0  ");
			scanf("%d",&k);
		}while(k==1);
}
