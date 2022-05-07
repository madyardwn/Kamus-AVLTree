/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */

#include "tampilanUI.h"

void mainMenu(address *root){
	//kamus Data Lokal
	char kata[25]; 
	int pilihMenu; 
	
	printf("\n\n\t================================\n");
	printf("\n\t\t  MAIN MENU\n\n");
	printf(" \t================================\n\n");
	printf("                 [1] Tambah Data Kata     \n");
	printf("                 [2] Cari Kata     \n");
	printf("                 [3] Hapus Data Kata     \n");
	printf("                 [4] Print Berdasarkan Kelas Kata      \n");
	printf("                 [5] Exit     \n\n");
	printf("                Pilih Menu : ");
		
	//Memilih Main Menu
	scanf("%d", &pilihMenu); 
	switch(pilihMenu){
		case 1:
			root = tambahDataKata(root);
			break;
		case 2:
			temukanDataKata(root, input(kata));
			break;
		case 3:
			hapusDataKata(root, input(kata));
			break;
		case 4:
			printBerdasarkanKelasKata(root);
			system("pause");
			break;
		case 5:
			exit(0); 
			break;
		default:
			break;
	} 
}


void gotoxy(int x, int y){
	//Kamus Data Lokal
	//Tipe data komposit koordinat
	COORD coord;
	
	//Proses mengisi untuk menentukan posisi baru kursor 
	coord.X = x;
	coord.Y = y;
	
	//Proses mengatur posisi kursor
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





