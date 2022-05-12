/*
    POLITEKNIK NEGERI BANDUNG
    D3 Teknik Informatika - 1A
    Developer : 
        - Achmadya Ridwan I 	(211511001)
        - Wildan Setya Nugraha 	(211511032)
    Program     : Kamus Bahasa Indonesia menggunakan AVL Tree
------------------------------------------------------------- */

#pragma GCC diagnostic ignored "-Wwrite-strings" //Mengabaikan 
#include "fiturKamus.h"

/*---------------------------------*/
address *bukaFile (address *root)
{
	/* Kamus Data Lokal */
	FILE *bukaFile;             // variable untuk menampung file
	char kata[25];              // variable untuk menampung kata
	char penjelasan[100];       // variable untuk menampung penjelasan
	char kelasKata[4];          // variable untuk menampung kelas kata
	
    /* Algortima */

	/* Proses buka file database kamus bahasa Indonesia */
	bukaFile = (fopen("fileDataKamus.txt", "r"));
	
	/* Cek Apakah file database tersebut ada atau tidak */
	if(!bukaFile)
	{
		printf("FILE TIDAK ADA, TENANG FILE DATA KAMUS AKAN DIBUATKAN OTOMATIS\n");
		system("pause"); 
		return NULL; 
	}

	else 
	{  
        /* Jika ada maka baca isinya lalu insert ke dalam AVL Tree */
		while(!feof(bukaFile))
		{   
			fscanf(bukaFile, "%[^;];%[^;];%s\n", kata, penjelasan, kelasKata); 
			
			/* Proses insert ke dalam AVL Tree sesuai dengan kelas katanya */
			if(strcmp(kelasKata, "adj") == 0)
			{
				root = InsertAVL(root, kata, penjelasan, "adj");
			}

			else if(strcmp(kelasKata, "adv") == 0)
			{
				root = InsertAVL(root, kata, penjelasan, "adv");
			}

			else if(strcmp(kelasKata, "n") == 0)
			{
				root = InsertAVL(root, kata, penjelasan, "n");	
			}
            
			else if(strcmp(kelasKata, "v") == 0)
			{
				root = InsertAVL(root, kata, penjelasan, "v");
			}
		}
	}
	fclose(bukaFile);
	return root;
}

/*---------------------------------*/
address *tambahDataKata(address *root)
{
	/* Kamus Data Lokal */
	char kata[25];                  // variable untuk menampung kata
	char *kelasKata;                // variable untuk menampung kelas kata
    char penjelasan[100];           // variable untuk menampung penjelasan
	char dataOk;                    // variable untuk konfirmasi
	bool kelasKataValid;            // variable untuk memvalidasi kata yang diinput
	int pilihKelasKata;             // variable untuk memilih kelas kata
		
    /* Algortima */

	/* Proses Inputan Data Kata */
	do
	{
		system("cls");
		
		/* Input Kata Indonesia */
		printf("Kata       : ");
		input(kata);
		fflush(stdin);
		
		/* Input Penjelasan dari katanya */
		printf("\nPenjelasan : ");
		gets(penjelasan);
		fflush(stdin);
		
		/* Inputan untuk menentukan kata tersebut masuk ke dalam kelas kata apa */
		kelasKataValid = false;
		while(kelasKataValid == false)
		{
			printf("1. Adjektiva (Adj)\n");
			printf("2. Adverbia (Adv)\n");
			printf("3. Nomina (N)\n");
			printf("4. Verba (V)\n");
			printf("Pilih Kelas Kata : ");
			scanf("%d", &pilihKelasKata);
			
			switch(pilihKelasKata)
			{
				case 1 :
                {
                    kelasKata = "adj";
                    kelasKataValid = true;
                    break;
                }

				case 2 :
                {
                    kelasKata = "adv";
                    kelasKataValid = true;
                    break;
                }	

				case 3 :
                {
                    kelasKata = "n";
                    kelasKataValid = true;
                    break;
                }

                case 4 :
                {
                    kelasKata = "v";
                    kelasKataValid = true;
                    break;
                }	

				default :
                {
                    break;
                }
			}
		}
		
		/* Print Data hasil Inputan sementara apakah sudah ok */
		system("cls");
		printf("KATA         : %s\n", kata);
		printf("PENJELASAN   : %s\n", penjelasan);
		printf("KELAS KATA   : %s\n", kelasKata); 
		
		/* Input apakah data sudah benar */
		printf("DATA OK ? (y/n) ");
		dataOk = getch();
		
	}while(dataOk == 'T' || dataOk == 't');
	
	/* Proses Insert ke dalam AVL Tree */
	root = InsertAVL(root, kata, penjelasan, kelasKata); 
	simpanKeFile(root);
	return root;
}

void temukanDataKata(address *root, char *dataKata)
{
	/* Kamus Data Lokal */
	bool kataKetemu;
	
    /* Algortima */

	/* Proses pencarian kata */
	kataKetemu = false;
	while(kataKetemu == false)
	{
        /* Jika Tree belum terbentuk */
		if(root == NULL)
		{ 
			break;	
		}

		/* Jika kata yang dicari dan kata yang ada di AVL Tree sama	*/
		else if(strcmp(dataKata, root->KataIndonesia) == 0)
		{
			printf("\nKata         : %s\n", root->KataIndonesia);
			printf("Penjelasan   : %s\n", root->PenjelasanKata);
			printf("Kelas Kata   : %s\n", root->KelasKata);
			kataKetemu = true;
		} 
		
        /*Jika kata yang dicari dengan kata yang ada di AVL Tree lebih kecil jumlah ASCII-nya */
		else if (strcmp(dataKata, root->KataIndonesia) < 0)
		{
			root = root->LeftSon;
		
		}
		
        /* Jika kata yang dicari dengan kata yang ada di AVL Tree lebih besar jumlah ASCII-nya */
		else if (strcmp(dataKata, root->KataIndonesia) > 0)
		{
			root = root->RightSon;
		}
	}
	
	if(kataKetemu == false)
	{
		printf("\nKata %s Tidak Tersedia Di DataBase\n", dataKata);
	}
	
	system("pause");
}

/*---------------------------------*/
bool isKataTersedia(address *root, char *dataKata)
{
	/* Kamus Data Lokal */
	bool kataKetemu;
	
    /* Algortima */

	/* Proses pencarian kata */
	kataKetemu = false;
	while(kataKetemu == false)
	{
		if(root == NULL)
		{ 
			break;
		}
		
        /* Jika kata yang dicari dan kata yang ada di AVL Tree sama	*/
		else if(strcmp(dataKata, root->KataIndonesia) == 0)
		{
			kataKetemu = true;
		}

		/* Jika kata yang dicari dengan kata yang ada di AVL Tree lebih kecil jumlah ASCII-nya */
		else if (strcmp(dataKata, root->KataIndonesia) < 0)
		{
			root = root->LeftSon;
		}

		/* Jika kata yang dicari dengan kata yang ada di AVL Tree lebih besar jumlah ASCII-nya */
		else if (strcmp(dataKata, root->KataIndonesia) > 0)
		{
			root = root->RightSon;
		}
	}
	return kataKetemu; 
}
/*---------------------------------*/


/*---------------------------------*/
void hapusDataKata(address *root, char *dataKata)
{
    /* Algortima */

	if(isKataTersedia(root, dataKata) && root!=NULL)
	{
		root = remove(root, dataKata);
	}
	else
	{
		printf("\nKata %s Tidak Tersedia\n", dataKata);
		system("pause");
	}
	simpanKeFile(root);
}

/*---------------------------------*/
void cariBerdasarkanKelasKata(address *root, char *dataKelasKata, bool *cek)
{
    /* Algortima */

	if(root!=NULL)
	{
		cariBerdasarkanKelasKata(root->LeftSon, dataKelasKata, &(*cek));
		if(strcmp(dataKelasKata, root->KelasKata) == 0)
		{
			printf("%s \n", root->KataIndonesia);
            *cek = true;
		} 
		cariBerdasarkanKelasKata(root->RightSon, dataKelasKata, &(*cek));
	}
}

void printBerdasarkanKelasKata(address *root)
{
	/* Kamus Data Lokal */
	int pilihKelasKata;                 // variable untuk menampung pilihan kelas kata
	char *kelasKata;                    
	bool kelasKataValid;
	bool cek = false;
    /* Algortima */

	/* Memilih Kelas Kata yang ingin dicari */
	kelasKataValid = false;
	while(kelasKataValid == false)
	{
		printf("1. Adjektiva (Adj)\n");
		printf("2. Adverbia (Adv)\n");
		printf("3. Nomina (N)\n");
		printf("4. Verba (V)\n");
		printf("Pilih Kelas Kata : ");
		scanf("%d", &pilihKelasKata);
		
		switch(pilihKelasKata)
		{
			case 1:
            {
                kelasKata = "adj"; 
				kelasKataValid = true;
				break;
            }
				
			case 2:
            {
				kelasKata = "adv";
				kelasKataValid = true;
				break;
            }

			case 3:
            {
				kelasKata = "n";
				kelasKataValid = true;
				break;
            }

			case 4:
            {
				kelasKata = "v";
				kelasKataValid = true;
				break;
            }

			default:
            {
                break;
            }
		}
	}
	
	/* Proses pencarian kata lalu print kata ke layar sesuai dengan kelas katanya */
	cariBerdasarkanKelasKata(root, kelasKata, &cek);
    if(cek == false)
    {
        printf("Data kelas kata %s tidak tersedia\n", kelasKata);
    }
}

/*--------------------------------------------------------------------------------------SAVE DATA KE DALAM FILE-----------------------------------------------------------------------------------*/
void tulisKeFile(FILE *file, address *root)
{
    /* Algortima */

	/* Proses menulis data kata ke dalam File berdasarkan postOrder */
	if(root!=NULL)
	{
		tulisKeFile(file, root->LeftSon);
		fprintf(file, "%s;%s;%s\n", root->KataIndonesia, root->PenjelasanKata, root->KelasKata);
		tulisKeFile(file, root->RightSon);	 
	}
}

void simpanKeFile(address *root)
{
	/* Kamus Data Lokal */
	FILE *filePenyimpanan;
	
    /* Algortima */

	/* Proses membuka dan menulis data ke dalam file penyimpanan */
	filePenyimpanan = fopen("fileDataKamus.txt", "w");
	tulisKeFile(filePenyimpanan, root); 
	
	/* Menutup file penyimpanan */
	fclose(filePenyimpanan);
}
