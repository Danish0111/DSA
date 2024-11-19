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

int isBST(struct Node *root) {
    static struct Node *prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
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

    if (isBST(n)) {
        
        printf("It is a BST\n");
    }
    else {
        printf("It is not a BST\n");
    }
    
    return 0;
}