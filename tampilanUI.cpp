/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */

#include "tampilanUI.h"
#include <cstdio>
#include <cstdlib>

bool mainMenu(address *root)
{
	/* kamus Data Lokal */
	char kata[25];          // variable untuk menampung kata 
	int pilihMenu;          // variable untuk menampung pilihan menu
	
    /* tampilan menu */
	printf("\n\n\t================================\n");
	printf("\n\t\t  MAIN MENU\n\n");
	printf(" \t================================\n\n");
	printf("                 [1] Tambah Data Kata     \n");
	printf("                 [2] Cari Kata     \n");
	printf("                 [3] Hapus Data Kata     \n");
	printf("                 [4] Print Berdasarkan Kelas Kata      \n");
	printf("                 [5] Exit     \n\n");
	printf("                Pilih Menu : ");
		
	/* Memilih Menu */
	scanf("%d", &pilihMenu);
	fflush(stdin);
	switch(pilihMenu)
	{
		case 1:
        {
            root = tambahDataKata(root);
            break;	
        }

		case 2:
        {
            printf("Kata yang ingin dicari : ");
            temukanDataKata(root, inputKata(kata));
            break;	
        }

		case 3:
        {
            printf("Kata yang ingin dihapus : ");
            hapusDataKata(root, inputKata(kata));
            break;	
        }

		case 4:
        {
            printBerdasarkanKelasKata(root);
            system("pause");
            break;
        }

		case 5:
        {
            return false;
            break;
        }

		default:
        {
            printf("Inputan salah\n");
            system("pause");
            break;
        }
	}
	return true;
}

void boxTampilanAwal()
{
	system("cls");
	gotoxy(10,3);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
	gotoxy(10,4);  printf("\xB3"); gotoxy(55,4); printf("K B B I"); gotoxy(110,4);  printf("\xB3");
	gotoxy(10,5);  printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
		
	gotoxy(10,6);  printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,7);  printf("\xB3"); gotoxy(11,7);   printf(" OOO     OOO        OO                                                               *");                 gotoxy(110,7);  printf("\xB3");
	gotoxy(10,8);  printf("\xB3"); gotoxy(11,8);   printf("  O       O   OOO    O    OOOO   OOO   OOO O     OOO                               ****");                gotoxy(110,8);  printf("\xB3");
	gotoxy(10,9);  printf("\xB3"); gotoxy(11,9);   printf("  O       O  O   O   O   O   O  O   O   O O O   O   O                           * ********");             gotoxy(110,9);  printf("\xB3");
	gotoxy(10,10); printf("\xB3"); gotoxy(11,10);  printf("  O   O   O  OOOOO   O   O      O   O   O O O   OOOOO                      *** ***************");         gotoxy(110,10);  printf("\xB3");
	gotoxy(10,11); printf("\xB3"); gotoxy(11,11);  printf("  O   O   O  O       O   O      O   O   O O O   O          * *****     ****************************");    gotoxy(110,11);  printf("\xB3");
	gotoxy(10,12); printf("\xB3"); gotoxy(11,12);  printf("    O   O     OOOO  OOO   OOOO   OOO   OOOOOOO   OOOO     ***********  ****************************");    gotoxy(110,12);  printf("\xB3");
	gotoxy(10,13); printf("\xB3"); gotoxy(11,13);  printf("                                                        ** ************** ***********************");      gotoxy(110,13); printf("\xB3");
	gotoxy(10,14); printf("\xB3"); gotoxy(11,14);  printf("***********************************************************************************************");        gotoxy(110,14); printf("\xB3");
	gotoxy(10,15); printf("\xB3"); gotoxy(11,15);  printf("                                                        ** ************** ***********************");      gotoxy(110,15); printf("\xB3");
	gotoxy(10,16); printf("\xB3"); gotoxy(11,16);  printf("                O  O   OOOO   OOOO   OOO                  ***********  ****************************");    gotoxy(110,16); printf("\xB3");
	gotoxy(10,17); printf("\xB3"); gotoxy(11,17);  printf("                O O    O   O  O   O   O                    * *****     ****************************");    gotoxy(110,17); printf("\xB3");
	gotoxy(10,18); printf("\xB3"); gotoxy(11,18);  printf("                OO     OOOO   OOOO    O                                    *** ***************");         gotoxy(110,18); printf("\xB3");
	gotoxy(10,19); printf("\xB3"); gotoxy(11,19);  printf("                O O    O   O  O   O   O                                         * ********");             gotoxy(110,19); printf("\xB3");
	gotoxy(10,20); printf("\xB3"); gotoxy(11,20);  printf("                O  O   OOOO   OOOO   OOO                                           ****");                gotoxy(110,20); printf("\xB3");
	gotoxy(10,21); printf("\xB3"); gotoxy(11,21);  printf(" 	                                                                                *");                 gotoxy(110,21); printf("\xB3");
	gotoxy(10,22); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	gotoxy(10,23); printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
	gotoxy(10,24); printf("\xB3"); gotoxy(110,24); printf("\xB3");
	gotoxy(10,25); printf("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
		
	pilihanAwal();

}


void pilihanAwal()
{
	/* Kamus Data Global */
	int counter = 2;
	int SetColor[] = {7,7}; //7 Warna default (putih)
	char keyCursor;
	
	/* Algoritma */
	while(1){
		
		gotoxy(51,24); 
		color(SetColor[0]); 
		printf("MULAI"); 
	
		gotoxy(61,24); 
		color(SetColor[1]); 
		printf("KELUAR");
	
		keyCursor = getch();
		
		if(keyCursor == 75 && counter >= 2) //Cursor Left
		{
			counter--;
		}
		if(keyCursor == 77 && counter >= 1 && counter <2) //Cursor Right
		{
			counter++;
		}
		if(keyCursor == '\r') //Enter
		{
			if(counter == 1)
			{
				break;
				
			} else {
				
				exit(1);
			}	
		}
		
		SetColor[0] = 7;
		SetColor[1] = 7;
		
 		if(counter == 1){
			SetColor[0] = 12;
		}
		if(counter == 2){
			SetColor[1] = 12;
		}
	}
}


void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void gotoxy(int x, int y)
{
	/* Kamus Data Lokal */
	COORD coord;            // Tipe data komposit koordinat
	
	/* Proses mengisi untuk menentukan posisi baru kursor */
	coord.X = x;
	coord.Y = y;
	
	/* Proses mengatur posisi kursor */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
