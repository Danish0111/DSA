#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* search(struct Node* root, int key){
    if (root == NULL){
        return NULL;
    }
    if (root->data == key){
        return root;
    }
    else if (root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}
struct Node* createrNode(int value){
    struct Node *ptr = (struct Node* )malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
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
    printf("enter element to search: ");
    scanf("%d", &key);

    struct Node* s = search(n, key);
    if(s != NULL){
        printf("found: %d", s->data);
    }
    else{
        printf("element not found\n");
    }
    return 0;
}