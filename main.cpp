#include <cstdlib>
#include <stdio.h>
#include <conio.h>

typedef struct node{
    struct node *left;
    struct node *right;
    int info;
    int height;
}address;

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int getHeight(address *root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

int getBalanceFactor(address *root){
    if(root ==NULL){
        return 0;
    }
    return (getHeight(root->left) - getHeight(root->right));
}

address *alokasi(int data){
    address *P;
    
    P = (address *) malloc(sizeof(address));
    if(P == NULL){
        return 0;
    }
    P->info = data;
    P->left = NULL;
    P->right = NULL;
    P->height = 1;

    return P;
}

address *leftRotate(address *root){
    address *newRoot = root->right;
    address *temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

address *rightRotate(address *root){
    address *newRoot = root->left;
    address *temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

    return newRoot;
}

address *rotate(address *root){
    int bf;
    root->height = max(getHeight(root->left), getHeight(root->right))+1;
    bf = getBalanceFactor(root);

    if(bf>1 && getBalanceFactor(root->left)>0){
        root = rightRotate(root);
    }
    else if(bf > 1 && getBalanceFactor(root->left) <= 0){
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(bf < -1 && getBalanceFactor(root->right)<=0){
        root = leftRotate(root);
    }
    else if(bf < -1 && getBalanceFactor(root->right)>0){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}

address *InsertAVL(address *root, int data){

    if(root == NULL){
        root = alokasi(data);
        return root;
    }
    if(data < root->info){
        root->left = InsertAVL(root->left, data);
    }else if (data > root->info){
        root->right = InsertAVL(root->right, data);
    }else{
        printf("data sudah berada di dalam tree");
        getch();
        return root;
    }
    root = rotate(root);
    return root;
}

address *Predecessor(address *root){
    address *current;
    
    current = root;
    while (current->right != NULL){
        current = current->right;
    }
    return current;
}

address *Successor(address *root){
    address *current;
    
    current = root;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

address *Delete(address *root, int data){
    
    if(root == NULL){
        return root;
    }else if(data < root->info){
        root->left = Delete(root->left, data);
    }else if(data > root->info){
        root->right = Delete(root->right, data);
    }else{
        //case
        if(root->left == NULL || root->right==NULL){
            
            address *temp = NULL;
            
            if(root->left==NULL){
                temp = root->right;
            }else{
                temp = root->left;
            }


            if(temp == NULL){
                // case 1
                temp = root;
                root = NULL;
            }else{
                //case 2 & 3
                *root = *temp;
            }
            free(temp);

        }else{
            // case 4
            address *temp;
            temp = Predecessor(root->left);
            root->info = temp->info;
            root->left = Delete(root->left, temp->info);
        }
        
    }
    if (root == NULL){
        return root;
    }
    return rotate(root);
}

void print(address *root){

    if(root != NULL){
        print(root->left);
        printf("%d ", root->info);
        print(root->right);
    }
}

void deleteBinaryTree(address *root)
{
    if (root == NULL) {
        return;
    }
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
    root = NULL;
}

int main ()
{
    int info;
    address *root = NULL;

    while (1){
        system("clear");
        printf("angka: ");
        scanf("%d", &info);
        if(info == 0){
            break;
        }else{
            root = InsertAVL(root, info);
        }
        getch();
    }
    system("clear");
    printf("output    : ");
    print(root); 
    
    Delete(root, 7);
    printf("\ndelete 7  : ");
    print(root);
    
    getch();
    deleteBinaryTree(root);
    return 0;
}
