#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *l, *r;
};

struct node* create(struct node* f) {
    int n;
    printf("Enter data (or -1 to stop): ");
    scanf("%d", &n);
    
    if (n == -1)
        return NULL;
    
    f = (struct node*)malloc(sizeof(struct node));
    f->data = n;
    
    printf("Enter data for insertion in the left of %d: ", n);
    f->l = create(f->l);
    
    printf("Enter data for insertion in the right of %d: ", n);
    f->r = create(f->r);
    
    return f;
}

void inorder(struct node* f) {
    if (f != NULL) {
        inorder(f->l);
        printf("%d ", f->data);
        inorder(f->r);
    }
}

int main() {
    struct node* root = NULL;
    root = create(root);
    
    printf("Inorder traversal:\n");
    inorder(root);
    
    return 0;
}
