#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};


struct node* createNode(int v) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->value = v;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}


struct node* insertIntoTree(int v, struct node* root) {

    if(root == NULL) {
     
        struct node* newNode = createNode(v);
      
        return newNode;

    } else {
     
        if(root->value > v) {

            if(root->left == NULL) {
           
                root->left = createNode(v);
            } else {
                insertIntoTree(v, root->left);
            }
    
        } else if(root->value < v) {
            if(root->right == NULL) {
                root->right = createNode(v);
            } else {
                insertIntoTree(v, root->right);
            }
        }
    }
   
    return root;
}



void inOrder(struct node* root){

    if(root->left != NULL){
        inOrder(root->left);
    }

    printf("%d ",root->value);

    if(root->right!=NULL){
        inOrder(root->right);
    }

}

void inOrderReverse(struct node* root){

    if(root->right != NULL){
        inOrderReverse(root->right);
    }

    printf("%d ",root->value);

    if(root->left!=NULL){
        inOrderReverse(root->left);
    }

}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postOrder(struct node* root){

    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}


int main() {
    struct node* tree = NULL;
    tree = insertIntoTree(10, tree);
    tree = insertIntoTree(14, tree);
    tree = insertIntoTree(17, tree);
    tree = insertIntoTree(3, tree);
    tree = insertIntoTree(1, tree);
    tree = insertIntoTree(6, tree);
    tree = insertIntoTree(7, tree);
    tree = insertIntoTree(4, tree);

    printf("Inorder: ");
    inOrder(tree);
    printf("\n\nInorder reverse: ");
    inOrderReverse(tree);
    printf("\n\nPreorder: ");
    preorder(tree);
    printf("\n\n");
    printf("Postorder: ");
    postOrder(tree);
    printf("\n\n");
    


    return 0;
}