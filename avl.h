#ifndef AVL_H
#define AVL_H

#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

typedef struct node{
    struct node *left;
    struct node *right;
    char info[25];
    int height;
}address;


int max(int a, int b);
int getHeight(address *root);
int getBalanceFactor(address *root);
address *alokasi(char *data);
address *leftRotate(address *root);
address *rightRotate(address *root);
address *rotate(address *root);
address *InsertAVL(address *root, char *data);
address *Predecessor(address *root);
address *Successor(address *root);
address *remove(address *root, char *data);
void postPrint(address *root);
void deleteBinaryTree(address *root);
char *input(char karakter[25]);

#endif 
