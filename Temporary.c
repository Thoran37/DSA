#include <stdio.h>
#include <stdlib.h>
#define size 300
struct node
{
	struct node *l,*r;
	int x;
	char c;
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
struct node* pop(void)
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
				       ptr=nn;
				}
			else
			 {
			  ptr->l=NULL;
			ptr=pop();
			}
	}
	return t;
}

void post_non(struct node *t)
{
	push(NULL);
	ptr=t;
	do
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
					while(ptr->x==1 && ptr!=NULL)
						{
							printf("%c ",ptr->c);
							ptr=pop();
						 }
					 if(ptr->x==0&&ptr!=NULL)
						 ptr->x=1;
	}while(ptr!=NULL);
}

void inorder(struct node *t)
{
	if(t==NULL)
	  return;
	  else
	  {
	inorder(t->l);
	printf("%c ",t->c);
	inorder(t->r);
	}
}
void preorder(struct node *t)
{
	if(t==NULL)
	  return;
	  else
	  {
	printf("%c ",t->c);
	preorder(t->l);
	preorder(t->r);
	}
}
void postorder(struct node *t)
{
	if(t==NULL)
	  return;
	  else
	  {
	postorder(t->l);
	postorder(t->r);
	printf("%c ",t->c);
	}
}
void main()
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
		     /*	case 5: in_non(root);break;
			case 6: pre_non(root);break; */
			case 7: post_non(root);break;
		     /*	case 8: printf("Height = %d\n",height(root));break;
			case 9: printf("No.of leaf node = %d\n",countln(root));break;
			case 10: printf("No.of non leaf node = %d\n",countnln(root));break;*/
			default: printf("Wrong choice\n");
				}
			printf("Continue main 1/0  ");
			scanf("%d",&k);
		}while(k==1);
}



