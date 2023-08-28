#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left,*right;
}*head=NULL,*nn;
struct node* create(int data){
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left=nn->right=NULL;
    return nn;
}
struct node* insert(struct node*root,int data){
    if(root==NULL)
    return create(data);
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}
struct node*min(struct node*root){
if(root==NULL)
return NULL;
while(root->left!=NULL){
    root=root->left;
}
return root;
}
struct node*del(struct node*root,int data){
    if(root==NULL)
    return root;
    if(data<root->data){
        root->left=del(root->left,data);
    }
    else if(data>root->data){
        root->right=del(root->right,data);
    }
    else{
        if(root->left==NULL){
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node*temp=root->left;
            free(root);
            return temp;
           
            
        }
        struct node*temp=min(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }
    return root;
}
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    
    head=insert(head,10);
    head=insert(head,1);
   
    head=insert(head,0);
    head=insert(head,100);
     
        inorder(head);
       
       head= del(head,0);
        inorder(head);
}
