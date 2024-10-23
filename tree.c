#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void createrNode(struct Node* ptr, int value){
    ptr = (struct Node* )malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->left = NULL;
    ptr->right = NULL;
}
int main(){
    struct Node* root;
    struct Node* second;
    struct Node* third;
    root = (struct Node* )malloc(sizeof(struct Node));
    root->data = 12;
    root->left = second;
    root->right = third;

    createrNode(second, 23);
    createrNode(third, 234);

    return 0;
}