/*****************************************************************************************************************

 Name: myBinarySearchTree.c

 Author: Nicolai Rothenhöfer

 Description: A C program that illustrates how a binary search tree works 
              and implemented some of the basic functions.
              

 Datum: 24.05.2024

******************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//template for tree nodes
typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}node;

//deklaration of needed functions
struct node* createNode(int);
struct node* insertIntoTree(int, node*);
void inOrder(node*);
void preOrder(node*);
void postOrder(node*);
struct node* deleteNode(int, node*);
struct node* findMin(node*);

int main(){

    node* tree = NULL;

    int choice = 0;
    int check = 0;
    
    
     do{
        choice = 0;
        int value = 0;
        //little menu for user
        printf("1. insert new node\n"
           "2. insert test tree\n"
           "3. traverse in-order\n"
           "4. traverse pre-order\n"
           "5. traverse post-order\n"
           "6. delete node\n"
           "7. exit\n\n");
    
        scanf("%d",&choice);
        
        //switching based on user input
        switch(choice){

            case 1: 
                printf("value: ");
                check = scanf("%d",&value);

                if(check == 0){ //checking if the user gave input
                    fprintf(stderr,"no value inserted");
                }
                while (getchar() != '\n'); // Clear invalid input

                tree =insertIntoTree(value,tree); 
                break;
            case 2: //already prepared tree for quick test
                    tree = insertIntoTree(8,tree);
                    tree = insertIntoTree(3,tree);
                    tree = insertIntoTree(15,tree);
                    tree = insertIntoTree(7,tree);
                    tree = insertIntoTree(2,tree);
                    tree = insertIntoTree(16,tree);
                    tree = insertIntoTree(9,tree);
                    fprintf(stdout,"prepared tree inserted\n");
                    break;
            case 3: 
                inOrder(tree);
                fprintf(stdout,"\n\n");
                break;
            case 4:
                preOrder(tree);
                fprintf(stdout,"\n\n");
                break;
            case 5:
                postOrder(tree);
                fprintf(stdout,"\n\n");
                break;
            case 6:
                //getting value for node deletion
                printf("value: ");
                check = scanf("%d",&value);

                if (check == 0) { // checking if the user gave input
                    fprintf(stderr, "no value inserted\n");
                    while (getchar() != '\n'); // Clear invalid input
                } 

                tree = deleteNode(value,tree);
                    
                break;
            case 7:
                printf("exiting..\n\n");
                exit(EXIT_SUCCESS);

        }
    }while(choice!=7);



    exit(EXIT_SUCCESS);
}

//function to create a new tree node
struct node* createNode(int v){
    //allocating needed memory for tree node
    node* newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->value = v; //assigning given value to node
        newNode->left = NULL; //both pointer point to NULL until they are inserted 
        newNode->right = NULL;
    }
    else{
        fprintf(stderr,"allocating new node failed");
        exit(EXIT_FAILURE);
    }
    
    return newNode;
}

node* insertIntoTree(int newValue, node* root){

    //checking if root is NULL, if yes it is the first element
    if(root == NULL){
        node* newNode = createNode(newValue);
        return newNode;
    }
    else{
        if(root->value > newValue){ //if tree value is bigger than newValue, newValue has to be left
            if(root->left == NULL){ //checking if the left side is empty
                root->left = createNode(newValue); //creating new Node on the left
            }
            else{
                insertIntoTree(newValue, root->left); //recursive function calling to traverse left part of the tree
            }
        }
        else if(root->value < newValue){ //if tree value is smaller than newValue, newValue has to be right
            if(root->right == NULL){  //checking if the right side is empty
                root->right = createNode(newValue); //creating new Node on the right
            }
            else{
                insertIntoTree(newValue, root->right); //recursive function calling to traverse right part of the tree
            }
        }
    }

    return root;
}

void inOrder(struct node* root){
    //recursive function calling to keep the algorithm going

    //traversing to the left until there is no node 
    if(root->left != NULL){
        inOrder(root->left);
    }

    //printing found node
    printf("%d ",root->value);

    //traversing to the right until there is no node
    if(root->right!=NULL){
        inOrder(root->right);
    }

}

void preOrder(struct node* root) {
    if (root != NULL) { //checking if current node is NULL
        printf("%d ", root->value); //printing value of current node
        preOrder(root->left); //recursive calling to traverse left 
        preOrder(root->right); //recursice calling to traverse to the right
    }

}

void postOrder(struct node* root){

    if(root!=NULL){ //checking if current node is NULL
        postOrder(root->left); //recursive function calling to traverse tree
        postOrder(root->right);
        printf("%d ", root->value); //printing current node
    }

} 


node* deleteNode(int value, node* root) {
    if (root == NULL) {
        return NULL;
    }

    //searching for node with given value
    if (value < root->value) {
        root->left = deleteNode(value, root->left); //recursive function calling to traverse left
    } else if (value > root->value) {
        root->right = deleteNode(value, root->right); //recursive function calling to traverse right
    } else { //found node
        //checking if the node has one child, if there are no childs the first statement will handle the deletion
        if (root->left == NULL) { //is there a child on the right?
            node* temp = root->right; //creating temp node to save the right child
            free(root); //delete current node
            return temp; //returning child
        } else if (root->right == NULL) { //same with the left child
            node* temp = root->left;
            free(root);
            return temp;
        }

        //node with two children
        node* temp = findMin(root->right);  //finding smallest value in right part of tree 
        root->value = temp->value; //replace the value of the node to be deleted with the smallest value
        root->right = deleteNode(temp->value, root->right); //deleting node with smallest value
    }
    return root;
}

node* findMin(node* root){

    //checking if tree is empty
    if(root == NULL){
        fprintf(stderr,"no elements in tree");
        return NULL;
    }
    
    //traverse to smallest value
    if(root != NULL && root->left != NULL){
        findMin(root->left);
    }
    
    return root;
}


