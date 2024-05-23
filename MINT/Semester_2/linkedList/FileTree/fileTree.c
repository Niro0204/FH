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

/*void loadFromFile(char *filename, struct node** tree) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "failed to open source file.\n");
        exit(EXIT_FAILURE);
    }

    int data = 0;
    while (fscanf(file, "%d,", &data) == 1) {
        *tree = insertIntoTree(data, *tree);
    }

    fclose(file); 
}*/

struct node* loadFromFile(char *filename, struct node* tree) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "failed to open source file.\n");
        exit(EXIT_FAILURE);
    }


    int data = 0;
    while (fscanf(file, "%d,", &data) == 1) {
        tree = insertIntoTree(data, tree);
    }

    fclose(file); 
    return tree;
}

/*void saveToFile(char* filename, struct node* root){
   
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei zum Schreiben.\n");
        return;
    }

  


    fclose(file);
}*/

void preorderFile(char* filename,struct node* root) {

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Fehler beim Öffnen der Datei zum Schreiben.\n");
        return;
    }

    if (root != NULL) {
        fprintf(file,"%d, ", root->value);
        preorderFile(filename,root->left);
        preorderFile(filename,root->right);
    }

    fclose(file);
}




int main(int argc, char* argv[]) {

    if(argc != 3){
        fprintf(stderr,"usage: ./fileTree <source_file> <destination_file>");
        exit(EXIT_FAILURE);
    }

    struct node* tree = NULL;

    tree = loadFromFile(argv[1],tree);
    preorderFile(argv[2], tree);

    
    /*tree = insertIntoTree(10, tree);
    tree = insertIntoTree(14, tree);
    tree = insertIntoTree(17, tree);
    tree = insertIntoTree(3, tree);
    tree = insertIntoTree(1, tree);
    tree = insertIntoTree(6, tree);
    tree = insertIntoTree(7, tree);
    tree = insertIntoTree(4, tree);
    */

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