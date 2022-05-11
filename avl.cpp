/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */
#include "avl.h"

int max(int a, int b)
{
    /* Algoritma */

    if(a > b)
    {
        return a;
    }
    
    return b;
}

int getHeight(address *root)
{
    /* Algoritma */

    /* Jika belum terbentuk root */
    if(root == NULL)
    {
        return 0;
    }
    
    /* Me-return nilai height dalam node */
    return root->height;
}

int getBalanceFactor(address *root)
{
    /* Algoritma */

    /* Jika belum terbentuk root */
    if(root ==NULL)
	{
        return 0;
    }

    /* Me-return selisih tinggi anak kiri dan anak kanan */
    return (getHeight(root->LeftSon) - getHeight(root->RightSon));
}

address *alokasi(char *dataKata, char *dataPenjelasanKata, char *dataKelasKata)
{
    /* Kamus Data Lokal*/
    address *P;
    
    /* Algoritma */

    /* Memesan memori */
    P = (address *) malloc(sizeof(address));
    if(P == NULL)
	{
        return 0;
    }
    
    /* Mengisi memori yang sudah dipesan sebelumya dengan data */
    strcpy(P->KataIndonesia, dataKata);
    strcpy(P->PenjelasanKata, dataPenjelasanKata); 
    strcpy(P->KelasKata, dataKelasKata); 
    
    /* Inisialisasi penunjuk dan tinggi node */
    P->LeftSon = NULL;
    P->RightSon = NULL;
    P->height = 1;

    return P;
}

address *leftRotate(address *root)
{
    /* Kamus Data Lokal */
    address *newRoot;
    address *temp;

    /* Algoritma */

    newRoot = root->RightSon;
    temp = newRoot->LeftSon;
    newRoot->LeftSon = root;
    root->RightSon = temp;

    /* Memperbaharui nilai height */
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon)) + 1;
    newRoot->height = max(getHeight(newRoot->LeftSon), getHeight(newRoot->RightSon)) + 1;

    return newRoot;
}

address *rightRotate(address *root)
{
    /* Kamus Data Lokal */
    address *newRoot;
    address *temp;

    /* Algoritma */
    newRoot = root->LeftSon;
    temp = newRoot->RightSon;     
    newRoot->RightSon = root;
    root->LeftSon = temp;

    /* Memperbaharui nilai height */
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon)) + 1;
    newRoot->height = max(getHeight(newRoot->LeftSon), getHeight(newRoot->RightSon)) + 1;

    return newRoot;
}

address *rotate(address *root)
{
    /* Kamus Data Lokal */
    int bf;

    /* Algoritma */

    /* Mengambil tinggi tree yang baru dan mengidentifikasi anak yang tidak balance */
    root->height = max(getHeight(root->LeftSon), getHeight(root->RightSon))+1;
    bf = getBalanceFactor(root);

    /* Jika anak kiri menyebabkan tidak balance dan anak kiri memiliki child di kiri */
    if(bf>1 && getBalanceFactor(root->LeftSon)>0)
	{
        root = rightRotate(root);
    }

    /* Jika anak kiri menyebabkan tidak balance dan anak kiri memiliki child di kanan */
    else if(bf > 1 && getBalanceFactor(root->LeftSon) <= 0)
	{
        root->LeftSon = leftRotate(root->LeftSon);
        root = rightRotate(root);
    }

    /* Jika anak kanan menyebabkan tidak balance dan anak kanan memiliki child di kanan */
    else if(bf < -1 && getBalanceFactor(root->RightSon)<=0)
	{
        root = leftRotate(root);
    }

    /* Jika anak kanan menyebabkan tidak balance dan anak kanan memiliki child di kiri */
    else if(bf < -1 && getBalanceFactor(root->RightSon)>0)
	{
        root->RightSon = rightRotate(root->RightSon);
        root = leftRotate(root);
    }

    return root;
}

address *InsertAVL(address *root, char *dataKata, char *dataPenjelasanKata,  char *dataKelasKata)
{
    /* Algoritma */

    /* Insertion jika belum terbentuk */
    if(root == NULL)
	{
        /* Alokasi awal (root) */
        root = alokasi(dataKata, dataPenjelasanKata, dataKelasKata);
        return root;
    }
 
    /* INSERTION (setelah tersebentuk root) */
    /* Jika nilai dataKata lebih kecil disambungkan di anak kiri*/
    if(strcmp(dataKata, root->KataIndonesia) < 0)
	{
        root->LeftSon = InsertAVL(root->LeftSon, dataKata, dataPenjelasanKata, dataKelasKata);
    }

    /* Jika nilai dataKata lebih besar disambungkan di anak kanan */
    else if(strcmp(dataKata, root->KataIndonesia) > 0)
	{
        root->RightSon = InsertAVL(root->RightSon, dataKata, dataPenjelasanKata, dataKelasKata);
    }

    /* Jika nilai dataKata sama penyambungan di batalkan */
    else
    {
        printf(" sudah berada di dalam tree");
        getch();
        return root;
    }

    /* Melakukan rotasi agar setelah ditambah node baru tetap balance */
    root = rotate(root);
    return root;
}


address *Predecessor(address *root)
{
    /* Kamus Data Lokal*/
    address *current;
    
    /* Algoritma */

    current = root;
    while (current->RightSon != NULL)
	{
        current = current->RightSon;
    }
    
    return current;
}

address *Successor(address *root)
{
    /* Kamus Data Lokal*/
    address *current;
    
    /* Algortima */

    current = root;
    while (current->LeftSon != NULL)
	{
        current = current->LeftSon;
    }
    
    return current;
}

address *remove(address *root,  char *dataKata)
{
    /* Kamus Data Lokal */
    address *temp;

    /* Jika belum terbentuk */
    if(root == NULL)
	{
        return root;
    }
	
    /* Deteltion */
    /* Jika dataKata lebih kecil dari node, maka rekursif remove ke anak kiri */
    else if(strcmp(dataKata, root->KataIndonesia) < 0)
	{
        root->LeftSon = remove(root->LeftSon, dataKata);
    }

    /* Jika dataKata lebih besar dari node, maka rekursif remove ke anak kanan */
    else if(strcmp(dataKata, root->KataIndonesia) > 0)
	{
        root->RightSon = remove(root->RightSon, dataKata);
    }

    /* Jika dataKata sama, maka remove node tersebut dengan ketentuan */
    else
	{
        if(root->LeftSon == NULL || root->RightSon==NULL)
		{
            temp = NULL;
            /* Jika memiliki anak di kanan saja */ 
            if(root->LeftSon==NULL)
			{
                temp = root->RightSon;
            }

            /* Jika memiliki anak di kiri saja */
            else
			{
                temp = root->LeftSon;
            }
            
            /* Jika tidak memiliki anak */
            if(temp == NULL)
			{
                temp = root;
                root = NULL;
            }
			
            else
			{
                *root = *temp;
            }
            free(temp);
        }
		
        /* Jika memiliki anak di kanan dan di kiri */
        else
		{
            /* Me-replace root dengan Predecessor dan dealokasi Predecessor tersebut */
            temp = Predecessor(root->LeftSon);
            strcpy(root->KataIndonesia, temp->KataIndonesia);
            root->LeftSon = remove(root->LeftSon, temp->KataIndonesia);
        }
    }
    if (root == NULL)
	{
        return root;
    }

    /* Melakukan rotasi agar tetap balance setelah proses deletion */
    return rotate(root);
}

void InPrint(address *root)
{
    /* Algortima */

    /* Jika belum terbentuk tree */
    if(root != NULL)
	{
        InPrint(root->LeftSon);
        printf("%s ", root->KataIndonesia); 
        InPrint(root->RightSon);
    }
}

void deleteBinaryTree(address *root)
{
    /* Algortima */

    /* Jika belum terbentuk tree */
    if (root == NULL) 
	{
        return;
    }
    deleteBinaryTree(root->LeftSon);
    deleteBinaryTree(root->RightSon);
    
    /* Dealokasi */
    delete root;
    root = NULL;
}

char *input(char karakter[25])
{
    /* Kamus Data Lokal*/
    char ch;
    int i = 0;
    
    /* Algoritma agar insert tidak melebihi batas (25 karakter )*/
    memset(karakter, 0, 1);
    while(1)
	{
        /* Pengaturan agar karakter seragam (huruf kecil) */
        ch = tolower(getch());

        /* Jika menekan enter selesai */
        if(ch == 13 || ch == 10)
		{
            break;
        }

        /* Jika menekan backspace mengahapus karakter */
        else if(ch == 8 || ch == 127)
		{
            /* Jika line berada di line awal pengahpusan tidak bekerja */
            if(i <= 0)
			{
                continue;
            }
			
            else
			{
                printf("\b \b");
                karakter[i-1] = '\0';
                i--;
            }
        }
		
        else
		{
            /* Jika batas karakter yang dinput sama dengan 25 tidak dapat menginput lagi */
        	if(strlen(karakter)>=24)
			{
            	continue;
			}

            /* Mengimput */
            karakter[i] = ch;
            karakter[i+1] = '\0';
            printf("%c", karakter[i]);
            i = i + 1;
        }
    }
    
    /* return NULL di ujung array */
    karakter[i] = '\0';
    return karakter;
}
