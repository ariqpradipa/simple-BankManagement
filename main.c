/*
#
#	Proyek 1 Pemrograman Lanjut
#
#	Management Database Bank BMB(Bank Milik Bersama)
#
#
#	Anggota:
#		1. Ariq Pradipa Santoso
#		2. Mochammad Shaffa Prawiranegara
#
#	2021
#
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


#include "header/cari_nasabah.h"
#include "header/deposito.h"
#include "header/login.h"
#include "header/menu.h"
#include "header/rekening_man.h"
#include "header/sort_nasabah.h"
#include "header/total_uang.h"
#include "header/transaksi.h"

// login
void loginAdmin();
void loginNasabah();

// menu
int menuAdmin();
int menuNasabah();

// rekening
int bukaRekening();
int tutupRekening();
int editRekening();

// sort dan search
int listNasabah();
int cariNasabah();

// deposito
int depositAdmin();
int editDeposit();
int lihatDeposit();

// etc
int totalPinjaman();
int totalUang();

// Sorting
int sortNama(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count, int chs);
int sortRekening(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count, int chs);
int sortSaldo(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count, int chs);
int displaySort(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count);

// Searching
int cariNama(char namaDepan[][20], char namaBelakang[][20], char rekening[][10], char uang[][50], char deposit[][50], int count);
int cariRekening(char namaDepan[][20], char namaBelakang[][20], char rekening[][10], char uang[][50], char deposit[][50], int count);
int displaySearch(char namaDepan[][20], char namaBelakang[][20], char rekening[][10], char uang[][50], char deposit[][50], int count);

// Total uang
int totalSum(float uang[], int count);

// global variable untuk menentukan siapa nasabah yang login
char usernameMasukNasabah[20];
char passMasukNasabah[20];
char rekeningMasukNasabah[20];

int main() {
    
    int chs;

    printf("||==========================||\n");
    printf("||    Management Bank BMB   ||\n");
    printf("||         ver 1.97         ||\n");
    printf("||==========================||\n\n");

    printf("#   1. Login Admin\n");
    printf("#   2. Login Nasabah\n");
    printf("#   Pilihan: ");
    scanf("%d", &chs);

    switch(chs) {

        case 1: {

            fflush(stdin);
            system("cls");

            loginAdmin();   // berada pada login.h

        }
        case 2: {

            fflush(stdin);
            system("cls");

            loginNasabah(); // berada pada login.h

        }
        default: {

            printf("\nInput Invalid!\n");
            system("pause");
            fflush(stdin);

            main();

        }
    }
}
