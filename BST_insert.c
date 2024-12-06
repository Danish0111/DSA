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

void insert(struct Node* root, int key){
    struct Node* prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data){
            printf("cannot insert %d, already in the BST\n", key);
            return;
        }
        else if (key < root->data){
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    struct Node* ptr = createrNode(key);
    if (key < prev->data){
        prev->left = ptr;
    }
    else {
        prev->right = ptr;
    }
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
    printf("enter element to insert: ");
    scanf("%d", &key);

    insert(n, key);
    printf("%d", n->right->right->data);
    return 0;
}