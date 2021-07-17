// disini terdapat menu utama dalam menavigasi program
extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int menuAdmin() {

    int admin;

    printf("||====================||\n");
    printf("||      Menu Admin    ||\n");
    printf("||====================||\n\n");

    printf("#   1. Pembukaan rekening\n");
    printf("#   2. Penutupan rekening\n");
    printf("#   3. Edit rekening nasabah\n");
    printf("#   4. List nasabah\n");
    printf("#   5. Cari nasabah\n");
    printf("#   6. Deposito nasabah\n");
    printf("#   7. Total uang dalam bank\n");
    printf("#   8. Exit\n\n");
    printf("#   Pilihan: ");
    scanf("%d", &admin);        // input plihan menu
     
    switch(admin) {
        
        case 1: {

            fflush(stdin);
            system("cls");

            bukaRekening();     // terdapat pada rekening_man.h

        }
        case 2: {

            fflush(stdin);
            system("cls");

            tutupRekening();    // terdapat pada rekening_man.h
        
        }
        case 3: {

            fflush(stdin);
            system("cls");

            editRekening();     // terdapat pada rekening_man.h

        }
        case 4: {
        
            fflush(stdin);
            system("cls");
        
            listNasabah();      // terdapat sort_nasabah.h
        
        }
        case 5: {
        
            fflush(stdin);
            system("cls");
        
            cariNasabah();      // terdapat pada cari_nasabah.h
        
        }
        case 6: {
        
            fflush(stdin);
            system("cls");
        
            depositAdmin();     // terdapat pada deposito.h
        
        }
        case 7: {
        
            fflush(stdin);
            system("cls");
        
            totalUang();        // terdapat pada total_uang.h
        
        }
        case 8: {

            system("cls");
            fflush(stdin);

            main();             // kembal ke awal

        }
        default: {
        
            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
        
            menuAdmin();        // kembal ke menuAdmin
        
        }
    }
}  

int menuNasabah() {

    int chs;

    printf("||==========================||\n");
    printf("||      Menu Nasabah        ||\n");
    printf("||==========================||\n\n");

    printf("||  Selamat Datang %s!\n", usernameMasukNasabah);   // menampilkan username nasabah yang login
    printf("#   1. Withdraw Uang\n");
    printf("#   2. Transfer Uang\n");
    printf("#   3. Lihat Deposit\n");
    printf("#   4. Exit\n");
    printf("#   Pilihan: ");
    scanf("%d", &chs);          // input pilihan menu

    switch(chs) {

        case 1: {

            fflush(stdin);
            system("cls");

            withdrawUang();     // terdapat pada transaksi.h

        }
        case 2: {

            fflush(stdin);
            system("cls");

            transferUang();     // terdapat pada transaksi.h

        }
        case 3: {

            fflush(stdin);
            system("cls");

            lihatDeposit();     // terdapat pada deposito.h

        }
        case 4: {

            fflush(stdin);
            system("cls");
            
            main();             // kembali ke awal

        }
        default: {

            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            fflush(stdin);
            system("cls");

            menuNasabah();      // terdapat ke atas

        }
    }
}