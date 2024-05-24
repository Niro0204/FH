#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}node;

struct node* createNode(int);
struct node* insertIntoTree(int, node*);
void inOrder(node*);
void preOrder(node*);
void postOrder(node*);
struct node* deleteNode(int, node*);
struct node* findNode(int, node*);
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
           "2. traverse in-order\n"
           "3. traverse pre-order\n"
           "4. traverse post-order\n"
           "5. delete node\n"
           "6. exit\n\n");
    
        scanf("%d",&choice);
        
        //switching based on user input
        switch(choice){

            case 1: 
                printf("value: ");
                check = scanf("%d",&value);

                if(check == 0){
                    fprintf(stderr,"no value inserted");
                }

                tree =insertIntoTree(value,tree); 
                break;
            case 2: 
                inOrder(tree);
                break;
            case 3:
                preOrder(tree);
                break;
            case 4:
                postOrder(tree);
                break;
            case 5:
                printf("value: ");
                check = scanf("%d",&value);

                if (check == 0) {
                    fprintf(stderr, "no value inserted\n");
                    while (getchar() != '\n'); // Clear invalid input
                } 

                tree = deleteNode(value,tree);
                    
                break;
            case 6:
                printf("exiting..\n\n");
                return 0;

        }
    }while(choice!=6);



    exit(0);
}

struct node* createNode(int v){
    node* newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode != NULL){
        newNode->value = v;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    else{
        fprintf(stderr,"allocating new node failed");
        exit(-1);
    }
    return newNode;
}

node* insertIntoTree(int newValue, node* root){

    if(root == NULL){
        node* newNode = createNode(newValue);
        return newNode;
    }
    else{
        if(root->value > newValue){
            if(root->left == NULL){
                root->left = createNode(newValue);
            }
            else{
                insertIntoTree(newValue, root->left);
            }
        }
        else if(root->value < newValue){
            if(root->right == NULL){
                root->right = createNode(newValue);
            }
            else{
                insertIntoTree(newValue, root->right);
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

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root){

    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
} 


node* deleteNode(int value, node* root) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) {
        root->left = deleteNode(value, root->left);
    } else if (value > root->value) {
        root->right = deleteNode(value, root->right);
    } else {
        // Knoten gefunden
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        // Knoten mit zwei Kindern
        node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(temp->value, root->right);
    }
    return root;
}

node* findNode(int value, node* root){

    if(root == NULL){
        fprintf(stderr,"no elements in tree");
        return NULL;
    }
    else if(value > root->value){
        findNode(value,root->right);
    }
    else if(value < root->value){
        findNode(value,root->left);
    }
    else {
        return root;
    }
   
}

node* findMin(node* root){

    if(root == NULL){
        fprintf(stderr,"no elements in tree");
        return NULL;
    }
    
    if(root != NULL && root->left != NULL){
        findMin(root->left);
    }
    
    return root;
}


