#include <stdio.h>
#include <stdlib.h>
#define order 4
struct node
{
  int keys[order];
  int cnt;
  int leaf;
  struct node *cp[order];
  struct node *parent;
  struct node *next;
}*temp,*nn,*root;
struct node *createnode()
{
  nn=(struct node*)malloc(sizeof(struct node));
  for(int i = 0;i<order;i++)
    nn->cp[i] = NULL;
  for(int i = 0;i<order;i++)
    nn->keys[i] = 0;
  nn->parent = NULL;
  nn->next = NULL;  
  nn->cnt = 0;
  nn->leaf = 1;
  return nn;
}
void split_node(struct node *node)
{
  int mid = ceil((order-1)/2),i,j;
  nn=createnode();
  if(node->leaf)
    {
      if(node->parent == NULL)
        {
          node->parent = createnode();
          temp = node->parent;
          if(node == root)
            root = temp;
          temp->keys[0] = node->keys[mid];
          temp->cp[0] = node;
          temp->cp[1] = nn;
          temp->leaf = 0;  
        }
      else 
        {
          temp = node->parent;
          for(i = 0;i<order-1;i++)
            {
              if(node->keys[mid]>temp->keys[i] && node->keys[mid]<temp->keys[i+1])
                {
                  for(j = order-3;j>i;j--)
                    temp->keys[j+1] = temp->keys[j];            
                  temp->keys[j+1] = node->keys[mid];
                  break;
                }  
              else if(node->keys[mid]<temp->keys[i])  
                {
                  for(j = order-3;j>=i;j--)
                    temp->keys[j+1] = temp->keys[j];            
                  temp->keys[j] = node->keys[mid];
                  break;
                } 
              else if(node->keys[mid]>temp->keys[i] && temp->keys[i+1] == 0) 
                { 
                  temp->keys[i+1] = node->keys[mid];
                  break;
                }
              temp->cp[i+1] = nn;  
            }
        }
      temp->cnt++;
      node->next = nn;
      nn->parent = temp;
      for(i=mid,j=0;i<order-1;i++,j++)
        {
          nn->keys[j] = node->keys[i];
          nn->cnt++;
        }
      for(i = mid;i<order;i++)
        node->keys[i] = 0;
      if(temp->cnt == order)
        split_node(temp);  
    }
  else
    {
      if(node->parent == NULL)
        {
          node->parent = createnode();
          temp = node->parent;
          if(node == root)
            root = temp;
          temp->keys[0] = node->keys[mid];
          temp->cp[0] = node;
          temp->cp[1] = nn;
          temp->leaf = 0;    
        }
      else
        {
          for(i = 0;i<order;i++)
            {
              if(node->keys[mid]>node->keys[i] && node->keys[mid]<node->keys[i+1])
                {
                  for(j = order-3;j>i;j--)
                    {
                      node->keys[j+1]=node->keys[j];            
                      node->cp[j+1]=node->cp[j];
                    }
                  node->keys[j+1]=node->keys[mid];
                  break;
                }  
              else if(node->keys[mid]<node->keys[i])  
                {
                  for(j = order-3;j>=i;j--)
                    {
                      node->keys[j+1]=node->keys[j];            
                      node->cp[j+1]=node->cp[j];
                    }
                  node->keys[j]=node->keys[mid];
                  break;
                }
              else if(node->keys[mid]>node->keys[i] && node->keys[i+1] == 0)  
                {
                  node->keys[i+1]=node->keys[mid];
                  break;
                }
            } 
        }  
      for(i=mid+1,j=0;i<order;i++,j++)
        {  
          nn->keys[j]=node->keys[i];
          nn->cp[j]=node->cp[i];
          node->keys[i]=0;
        }
      nn->cp[j]=node->cp[j];  
      
    }  
}
void insert(int k)
{
  int i,j;
  struct node *node;
  if(root == NULL)
    {
      root = createnode();
      node = root;
    }
  else 
    while(!node->leaf)
      for(i = 0;i<order-1;i++)
        {
          if(k>node->keys[i] && k<node->keys[i+1])
            node = node->cp[i+1];
          else if(k<node->keys[0])
            node = node->cp[0];
          else if(k>node->keys[i])
            node = node->cp[i+1];
        }
  for(i = 0;i<order;i++)
    {
      if(k>node->keys[i] && k<node->keys[i+1])
        {
          for(j = order-3;j>i;j--)
            node->keys[j+1]=node->keys[j];            
          node->keys[j+1]=k;
          break;
        }  
      else if(k<node->keys[i])  
        {
          for(j = order-3;j>=i;j--)
            node->keys[j+1]=node->keys[j];            
          node->keys[j]=k;
          break;
        }  
      else if(node->keys[i] == 0)
        {
          node->keys[i]=k;
          break;
        }
      else if(k>node->keys[i] && node->keys[i+1] == 0)  
        {
          node->keys[i+1]=k;
          break;
        }
    } 
  node->cnt++;  
  if(node->cnt == order)
    split_node(node);  
}
int main()
{
  
}
