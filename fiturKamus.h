/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */

#ifndef fiturKamus_H
#define fiturKamus_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <string>
#include <unistd.h>

#include "avl.h"

address *bukaFile(address *root);
address *tambahDataKata(address *root);
void temukanDataKata(address *root, char *dataKata);

bool isKataTersedia(address *root, char *dataKata); 

void hapusDataKata(address *root, char *dataKata); 
void printBerdasarkanKelasKata(address *root);
void cariBerdasarkanKelasKata(address *root, char *dataKelasKata, bool *cek); 
void tulisKeFile(address *root); 
void simpanKeFile(address *root); 

#endif 
