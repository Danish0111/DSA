#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void preOrder(struct Node *root){
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

void postOrder(struct Node *root){
    if (root == NULL) {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    printf("%d ", root->data);
}

void inOrder(struct Node *root){
    if (root == NULL) {
        return;
    }
    preOrder(root->left);
    printf("%d ", root->data);
    preOrder(root->right);
}
struct Node* createrNode(struct Node* ptr, int value){
    ptr = (struct Node* )malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
int main(){
    struct Node* root = (struct Node* )malloc(sizeof(struct Node));
    struct Node* second = createrNode(second, 23);
    struct Node* third = createrNode(third, 234);
    
    root->data = 12;
    root->left = second;
    root->right = third;

    printf("pre order\n");
    preOrder(root);

    printf("\npost order\n");
    postOrder(root);

    printf("\nin order\n");
    inOrder(root);

    return 0;
}