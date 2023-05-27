#include <stdio.h>
#include <stdlib.h>
#define size 300
struct node
{
	struct node *l,*r;
	char c;
	int x;
}*root=NULL,*nn,*ptr,*stack[size];

int top=-1;

void well()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("Enter data  ");
	fflush(stdin);
	scanf("%c",&nn->c);
	nn->x=1;
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
	while(ptr!=NULL || top!=-1)
	  {
			while(ptr!=NULL)
				{
					push(ptr);
					ptr=ptr->l;
				}
			ptr=pop();
			if(ptr!=NULL)
				{
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
void post_non(struct node *t)
{
	push(NULL);
	ptr=t;
	while(ptr!=NULL || top!=-1)
		{
			while(ptr!=NULL)
			{
				push(ptr);
				if(ptr->r!=NULL)
					{
						ptr->r->x=0;
						push(ptr->r);  
					}
				ptr=ptr->l;
			}
			ptr=pop();
			while(top!=-1)
				{
					if(ptr->x)
					  {
					    printf("%c ",ptr->c);
							ptr=pop();
						}
					else	
					  {	
							ptr->x=1;
							break;
						}
				}
		}
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
	int left,right;
	if(t!=NULL)
	  {
	  	left=height(t->l);
	  	right=height(t->r);
	  	if(left>right)
	  	  return left+1;
	  	else
		    return right+1;  
		}
	else
	  return 0;	
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
