#include <stdio.h>
#include <stdlib.h>
#define size 300
struct node
{
	struct node *l,*r;
	char c;
}*root=NULL,*nn,*ptr;

struct node *stack[size];

int top=-1;

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
/*void post_non(struct node *t)
{
	ptr=t;
	push(NULL);
	while(stack[top]!=NULL)
	  {
			while(ptr!=NULL)
				{
					push(ptr);
					if(ptr->r!=NULL)
						push(-(ptr->r));
					ptr=ptr->l;
				}
			ptr=pop();
			while(ptr>0)
				{
					printf("%c ",ptr->c);
					ptr=pop();
				}	
			if(ptr<0)
				ptr=-ptr;	
		}
}*/
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
	  	  	//case 7: post_non(root);break;
	  	  	//case 8: printf("Height = %d\n",height());break;
	  	  	case 9: printf("No.of leaf node = %d\n",countln(root));break;
	  	  	case 10: printf("No.of non leaf node = %d\n",countnln(root));break;
	  	  	default: printf("Wrong choice\n");
				}
			printf("Continue main 1/0  ");
			scanf("%d",&k);
		}while(k==1);
}
