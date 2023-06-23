// B+ Tree
#include <stdio.h>
#include <stdlib.h>
#define order 3
struct node
{
	int value[order-1];
	struct node *link;
	struct node *key[order];
	struct node *parent;
}*root=NULL,*temp,*nn,*last;
struct node* insert(int k)
{
	nn=(struct node*)malloc(sizeof(struct node));
  if(root==NULL)
	  {
			root=nn;
			last=nn;
			nn->value[0]=k;
		}
}
int main()
{
	// printf("Enter order of the tree  ");
	// scanf("%d",&k);
}
