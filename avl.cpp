/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */

#include "avl.h"


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
    return (getHeight(root->LeftSon) - getHeight(root->RightSon));
}

address *alokasi(char *dataKata, char *dataPenjelasanKata, char *dataKelasKata){
    address *P;
    
    P = (address *) malloc(sizeof(address));
    if(P == NULL){
        return 0;
    }
    
    strcpy(P->KataIndonesia, dataKata);
    strcpy(P->PenjelasanKata, dataPenjelasanKata); 
    strcpy(P->KelasKata, dataKelasKata); 
    
    P->LeftSon = NULL;
    P->RightSon = NULL;
    P->height = 1;

    return P;
}

address *leftRotate(address *root){
    address *newRoot = root->RightSon;
    address *temp = newRoot->LeftSon;

    newRoot->LeftSon = root;
    root->RightSon = temp;

    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon)) + 1;
    newRoot->height = max(getHeight(newRoot->LeftSon), getHeight(newRoot->RightSon)) + 1;

    return newRoot;
}

address *rightRotate(address *root){
    address *newRoot = root->LeftSon;
    address *temp = newRoot->RightSon;

    newRoot->RightSon = root;
    root->LeftSon = temp;

    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon)) + 1;
    newRoot->height = max(getHeight(newRoot->LeftSon), getHeight(newRoot->RightSon)) + 1;

    return newRoot;
}

address *rotate(address *root){
    int bf;
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon))+1;
    bf = getBalanceFactor(root);

    if(bf>1 && getBalanceFactor(root->LeftSon)>0){
        root = rightRotate(root);
    }
    else if(bf > 1 && getBalanceFactor(root->LeftSon) <= 0){
        root->LeftSon = leftRotate(root->LeftSon);
        root = rightRotate(root);
    }
    else if(bf < -1 && getBalanceFactor(root->RightSon)<=0){
        root = leftRotate(root);
    }
    else if(bf < -1 && getBalanceFactor(root->RightSon)>0){
        root->RightSon = rightRotate(root->RightSon);
        root = leftRotate(root);
    }
    return root;
}
address *InsertAVL(address *root, char *dataKata, char *dataPenjelasanKata,  char *dataKelasKata){
    if(root == NULL){
        root = alokasi(dataKata, dataPenjelasanKata, dataKelasKata);
        return root;
    }
    if(strcmp(dataKata, root->KataIndonesia) < 0){
        root->LeftSon = InsertAVL(root->LeftSon, dataKata, dataPenjelasanKata, dataKelasKata);
    }else if (strcmp(dataKata, root->KataIndonesia) > 0){
        root->RightSon = InsertAVL(root->RightSon, dataKata, dataPenjelasanKata, dataKelasKata);
    }else{
        printf(" sudah berada di dalam tree");
        getch();
        return root;
    }
    root = rotate(root);
    return root;
}


address *Predecessor(address *root){
    address *current;
    
    current = root;
    while (current->RightSon != NULL){
        current = current->RightSon;
    }
    return current;
}

address *Successor(address *root){
    address *current;
    
    current = root;
    while (current->LeftSon != NULL){
        current = current->LeftSon;
    }
    return current;
}

address *remove(address *root,  char *dataKata){
    
    if(root == NULL){
        return root;
    }else if(strcmp(dataKata, root->KataIndonesia) < 0){
        root->LeftSon = remove(root->LeftSon, dataKata);
    }else if(strcmp(dataKata, root->KataIndonesia) > 0){
        root->RightSon = remove(root->RightSon, dataKata);
    }else{
        if(root->LeftSon == NULL || root->RightSon==NULL){
            address *temp = NULL;
            if(root->LeftSon==NULL){
                temp = root->RightSon;
            }else{
                temp = root->LeftSon;
            }
            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{
                *root = *temp;
            }
            free(temp);

        }else{
            address *temp;
            temp = Predecessor(root->LeftSon);
            strcpy(root->KataIndonesia, temp->KataIndonesia);
            root->LeftSon = remove(root->LeftSon, temp->KataIndonesia);
        }
    }
    if (root == NULL){
        return root;
    }
    return rotate(root);
}

void postPrint(address *root){
    if(root != NULL){
        postPrint(root->LeftSon);
        printf("%s ", root->KataIndonesia); 
        postPrint(root->RightSon);
    }
}

void deleteBinaryTree(address *root){
    if (root == NULL) {
        return;
    }
    deleteBinaryTree(root->LeftSon);
    deleteBinaryTree(root->RightSon);
    delete root;
    root = NULL;
}

char *input(char karakter[25]){
    char ch;
    int i;
    
    memset(karakter, 0, 1);
	i = 0;
    while(1){
        ch = tolower(getch());
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
