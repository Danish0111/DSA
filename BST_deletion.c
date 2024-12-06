#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createrNode(int value){
    struct Node *ptr = (struct Node* )malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct Node* inOrderPredecessor(struct Node* root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

void inOrder(struct Node *root){
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

struct Node* delete(struct Node* root, int key){
    struct Node* ipre;

    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    
    if (key < root->data)
    {
        root->left = delete(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete(root->right, key);
    }
    else {
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = delete(root->left, ipre->data);
    }
    return root;
}

int main(){
    struct Node* n = createrNode(5);
    struct Node* n1 = createrNode(3);
    struct Node* n2 = createrNode(6);
    struct Node* n3 = createrNode(1);
    struct Node* n4 = createrNode(4);
    
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    
    int key;
    printf("enter element to delete: ");
    scanf("%d", &key);

    inOrder(n);
    delete(n, key);
    printf("\n");
    inOrder(n);
    return 0;
}