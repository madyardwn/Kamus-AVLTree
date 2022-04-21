#include <cstdlib>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> ed13747 (konversi ke dalam string)
#include <stdio.h>
#include <conio.h>

typedef struct node{
    struct node *left;
    struct node *right;
<<<<<<< HEAD
    int info;
=======
    char info[25];
>>>>>>> ed13747 (konversi ke dalam string)
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

<<<<<<< HEAD
address *alokasi(int data){
=======
address *alokasi(char *data){
>>>>>>> ed13747 (konversi ke dalam string)
    address *P;
    
    P = (address *) malloc(sizeof(address));
    if(P == NULL){
        return 0;
    }
<<<<<<< HEAD
    P->info = data;
=======
    strcpy(P->info,data);
>>>>>>> ed13747 (konversi ke dalam string)
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

<<<<<<< HEAD
address *InsertAVL(address *root, int data){

=======
address *InsertAVL(address *root, char *data){
>>>>>>> ed13747 (konversi ke dalam string)
    if(root == NULL){
        root = alokasi(data);
        return root;
    }
<<<<<<< HEAD
    if(data < root->info){
        root->left = InsertAVL(root->left, data);
    }else if (data > root->info){
=======
    if(strcmp(data, root->info) < 0){
        root->left = InsertAVL(root->left, data);
    }else if (strcmp(data, root->info) > 0){
>>>>>>> ed13747 (konversi ke dalam string)
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

<<<<<<< HEAD
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
            
=======
address *remove(address *root, char *data){
    
    if(root == NULL){
        return root;
    }else if(strcmp(data, root->info) < 0){
        root->left = remove(root->left, data);
    }else if(strcmp(data, root->info) > 0){
        root->right = remove(root->right, data);
    }else{
        if(root->left == NULL || root->right==NULL){
            address *temp = NULL;
>>>>>>> ed13747 (konversi ke dalam string)
            if(root->left==NULL){
                temp = root->right;
            }else{
                temp = root->left;
            }
<<<<<<< HEAD


            if(temp == NULL){
                // case 1
                temp = root;
                root = NULL;
            }else{
                //case 2 & 3
=======
            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{
>>>>>>> ed13747 (konversi ke dalam string)
                *root = *temp;
            }
            free(temp);

        }else{
<<<<<<< HEAD
            // case 4
            address *temp;
            temp = Predecessor(root->left);
            root->info = temp->info;
            root->left = Delete(root->left, temp->info);
        }
        
=======
            address *temp;
            temp = Predecessor(root->left);
            strcpy(root->info,temp->info);
            root->left = remove(root->left, temp->info);
        }
>>>>>>> ed13747 (konversi ke dalam string)
    }
    if (root == NULL){
        return root;
    }
    return rotate(root);
}

<<<<<<< HEAD
void print(address *root){

    if(root != NULL){
        print(root->left);
        printf("%d ", root->info);
        print(root->right);
=======
void postPrint(address *root){
    if(root != NULL){
        postPrint(root->left);
        printf("%s ", root->info);
        postPrint(root->right);
>>>>>>> ed13747 (konversi ke dalam string)
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

<<<<<<< HEAD
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
=======
char *input(char karakter[25]){
    system("cls");
    char ch;
    int i;
    
    memset(karakter, 0, 1);
	i = 0;
    while(1){
        ch = getch();
        if(ch == 13 || ch == 10){
            break;
        }else if(ch == 32){
            continue;
        }else if(ch == 8 || ch == 127){
            if(i <= 0){
                continue;
            }else{
                printf("\b \b");
                karakter[i-1] = '\0';
                i--;
            }
        }else{
        	if(strlen(karakter)>=24){
            	continue;
			}
            karakter[i] = ch;
            karakter[i+1] = '\0';
            printf("%c", karakter[i]);
            i++;
        }
    }
    karakter[i] = '\0';
    return karakter;
}

int main ()
{
	system("cls");
    char info[25];
    address *root = NULL;

	// insert tree AVL
    strcpy(info, input(info));
	root = InsertAVL(root, info);
	
	strcpy(info, input(info));
    root = InsertAVL(root, info);
	    
	strcpy(info, input(info));
    root = InsertAVL(root, info);    
    
	system("cls");
    printf("postOrder 			: ");
	postPrint(root);
	
	// ngecek tree
	printf("\n");
	printf("root 				: %s\n", root->info);
	printf("left 				: %s\n", root->left->info);
	printf("right 				: %s\n", root->right->info);
	getch();
	
	// remove 
	strcpy(info, input(info));
    root = remove(root, info);
	printf("\ndeleted			: %s\n", info);
	postPrint(root);    
	
	// dealoc
	deleteBinaryTree(root);
	return 0;
>>>>>>> ed13747 (konversi ke dalam string)
}
