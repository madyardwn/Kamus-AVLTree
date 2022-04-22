#include "avl.h"

int main ()
{
    char info[25];
    char ch;
    address *root = NULL;

    while(1){
    	system("cls");
        printf("\npostOrder	: ");
        postPrint(root);
        printf("\nInsert ga(Y/T)?");
        ch = getch();
        if(ch == 't' || ch == 'T'){
            break;
        }
        printf("\nkata 		: ");
	    root = InsertAVL(root, input(info));
    }

	system("cls");    
	printf("\n");
    printf("postOrder	: ");
	postPrint(root);
	
	// ngecek tree
	printf("\n");
	printf("root 	 	: %s\n", root->info);
	printf("left 	 	: %s\n", root->left->info);
	printf("right 	 	: %s\n", root->right->info);
//    printf("right-left 	: %s\n", root->right->left->info);
//    printf("right-right : %s\n", root->right->right->info);
	printf("\npress key to continue...");
	getch();
	
	// remove
	printf("\nremove 	:");
    root = remove(root, input(info));
	printf("\n");
    postPrint(root);    
	
	// dealoc
	deleteBinaryTree(root);

	return 0;
}
