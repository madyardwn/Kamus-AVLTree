/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */
#ifndef tampilanUI_H
#define tampilanUI_H

#include "fiturKamus.h"

bool mainMenu(address *root);
void gotoxy(int x, int y);
void pilihanAwal();
void boxTampilanAwal();
void boxFileTidakTersedia(); 
void boxTampilanMenu();
void boxTampilanKelasKata();  
int pilihanMainMenu(); 
void color(int color);
#endif
