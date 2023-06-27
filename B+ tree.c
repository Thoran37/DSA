#include <stdio.h>
#include <stdlib.h>
#define order 3
struct node
{
  int keys[order-1];
  int cnt;
  struct node *cp[order];
  struct node *parent;
  struct node *next;
}*temp,*nn;
struct node *createnode()
{
  nn=(struct node*)malloc(sizeof(struct node));
  for(int i = 0;i<order;i++)
    nn->cp[i] = NULL;
  for(int i = 0;i<order-1;i++)
    nn->keys[i] = 0;
  nn->parent = NULL;
  nn->next = NULL;  
  nn->cnt = 0;
  return nn;
}
void insert(int k)
{
  int i,j;
  struct node *node = createnode();
  if(node->cnt != order-1)
    for(i = 0;i<order-1;i++)
      {
        if(k>node->keys[i] && k<node->keys[i+1])
          {
            for(j = order-3;j>i;j--)
              node->keys[j+1]=node->keys[j];            
            node->keys[j+1]=k;
          }  
        else if(k<node->keys[i])  
          {
            for(j = order-3;j>=i;j--)
              node->keys[j+1]=node->keys[j];            
            node->keys[j]=k;
          }  
        else if(k>node->keys[i] && node->keys[i+1] == 0)  
          node->keys[i+1]=k;
        node->cnt++;  
      }
  else
    split_node();
}
int main()
{

}
