// disini berfungsi untuk mencari nasabah yang terdaftar
extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int cariNasabah() {

    char stringNasabah[256];
    char *stripped, *str1, *str2, *str3, *str4, *str5, *str6;
    int chs, i, x;
    int nasabahCount = 0;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // menghitung jumlah nasabah yang ada dalam file

        nasabahCount++;
    
    }

    fclose(fileNasabah);                                    // menutup file
    fileNasabah = fopen("data/nasabah.txt", "r");           // membuka kembali file dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    char namaDepanNasabah[nasabahCount+1][20], namaBelakangNasabah[nasabahCount][20], rekeningNasabah[nasabahCount][10];
    char depositNasabah[nasabahCount][50], uangNasabah[nasabahCount][50];

    // mengambil data dalam file dan memasukkan pada array
    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str5 = strtok(NULL, " ");
        str6 = strtok(NULL, " ");

        strcpy(namaDepanNasabah[i], str1);
        strcpy(namaBelakangNasabah[i], str2);
        strcpy(rekeningNasabah[i], str3);
        strcpy(uangNasabah[i], str4);
        strcpy(depositNasabah[i], str5);

        i++;

    }
    fclose(fileNasabah);    // menutup file

    while(x != -1) {

        printf("||==============================||\n");
        printf("||      Pencarian Nasabah       ||\n");
        printf("||==============================||\n\n");

        printf("||  Cari nasabah berdasarkan:\n");
        printf("#   1. Nama\n");
        printf("#   2. Rekening\n");
        printf("#   3. Kembali\n");
        printf("#   pilihan: ");
        scanf("%d", &chs);          // pilihan menu

        switch(chs) {

            case 1: {

                cariNama(namaDepanNasabah, namaBelakangNasabah, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount);
                displaySearch(namaDepanNasabah, namaBelakangNasabah, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount);

                fflush(stdin);
                system("pause");
                system("cls");

                continue;

            }
            case 2: {

                cariRekening(namaDepanNasabah, namaBelakangNasabah, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount);
                displaySearch(namaDepanNasabah, namaBelakangNasabah, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount);

                fflush(stdin);
                system("pause");
                system("cls");

                continue;

            }
            case 3: {

                fflush(stdin);
                system("cls");

                menuAdmin();

            }
            default: {

                printf("\n||  Input Invalid!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");

                continue;
            }
        }
    }
}

int displaySearch(char namaDepan[][20], char namaBelakang[][20], char rekening[][10], char uang[][50], char deposit[][50], int count) {

    int i, n;
    n = atoi(namaDepan[count]);
    char nama[n][20];

    printf("\n");

    printf("Hasil Pencarian Terbaik:\n");
    printf("    Nama            Rekening            Saldo           Deposit\n\n");
    for(i=0; i<n; i++) {

        printf("    %s %s      %s      Rp. %s      Rp. %s\n", namaDepan[i], namaBelakang[i], rekening[i], uang[i], deposit[i]);

    }

    printf("\n");
}

int cariNama(char namaDepan[][20], char namaBelakang[][20], char rekening[][10], char uang[][50], char deposit[][50], int count) {

    char nDepan[20], nBelakang[20], tempChar[20];
    char sName[20], tempName[20];
    int arrLocation[count];
    int n, i, times;
    times = 0;

    // mencari nasabah berdasarkan nama
    printf("\n|| Pencarian Nasabah dari Nama\n");
    printf("#   Nama Depan: ");
    scanf("%s", &nDepan);
    printf("#   Nama Belakang: ");
    scanf("%s", &nBelakang);

    for(i=0; i<count; i++) {    // mencari nasabah dalam array

        if(strcmpi(namaDepan[i], nDepan) == 0 && strcmpi(namaBelakang[i], nBelakang) == 0) {

            arrLocation[i] = -5;    // jika lokasi dalam array ditemukan maka akan diberi tanda -5
            times++;                // banyaknya jumlah data yang mirip

            continue;

        }
    }

    char stringTimes[50];
    itoa(times, stringTimes, 10);           // mengubah integer menjadi string
    strcpy(namaDepan[count], stringTimes); 
    if(times == 0) {                        // data nasabah tidak ditemukan


        printf("\n||  Nama Tidak Ditemukan!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        printf("\n");

        cariNasabah();

    }

    n = 0;
    for(i=0; i<count; i++) {

        if(arrLocation[i] != -5) {  // jika tidak ada tanda -5 pada array berarti bukan data tersebut

            continue;

        }
        else {

            strcpy(tempChar, namaDepan[n]);
            strcpy(namaDepan[n], namaDepan[i]);
            strcpy(namaDepan[i], tempChar);

            strcpy(tempChar, namaBelakang[n]);
            strcpy(namaBelakang[n], namaBelakang[i]);
            strcpy(namaBelakang[i], tempChar);

            strcpy(tempChar, rekening[n]);
            strcpy(rekening[n], rekening[i]);
            strcpy(rekening[i], tempChar);

            strcpy(tempChar, uang[n]);
            strcpy(uang[n], uang[i]);
            strcpy(uang[i], tempChar);

            strcpy(tempChar, deposit[n]);
            strcpy(deposit[n], deposit[i]);
            strcpy(deposit[i], tempChar);

            n++;
        }
    }
}

int cariRekening(char namaDepan[][20], char namaBelakang[][20], char rekening[][10], char uang[][50], char deposit[][50], int count) {

    char tempChar[20], tempName[20];
    char sRekening[10];
    int arrLocation[count];
    int n, i, times;
    times = 0;

    // pencarian data berdasarkan nomor rekening
    printf("|| Pencarian Nasabah dari nomor Rekening\n");
    printf("#   Nomor Rekening: ");
    scanf("%s", &sRekening);

    for(i=0; i<count; i++) {            // mencari nomor rekening dalam array

        if(strcmp(rekening[i], sRekening) == 0) {

            arrLocation[i] = -5;        // jika lokasi rekening ditemukan maka akan ditandai dengan -5
            times++;

            continue;

        }
    }

    char stringTimes[50];
    itoa(times, stringTimes, 10);           // mengubah integer menjadi string
    strcpy(namaDepan[count], stringTimes);
    if(times == 0) {                        // jika rekening tidak ditemukan


        printf("\n||  Nomor Tidak Ditemukan!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);

        cariNasabah();

    }

    n = 0;
    for(i=0; i<count; i++) {

        if(arrLocation[i] != -5) {      // jika tidak ada -5 dalam array berarti bukan data tersebut

            continue;

        }
        else {

            strcpy(tempChar, namaDepan[n]);
            strcpy(namaDepan[n], namaDepan[i]);
            strcpy(namaDepan[i], tempChar);

            strcpy(tempChar, namaBelakang[n]);
            strcpy(namaBelakang[n], namaBelakang[i]);
            strcpy(namaBelakang[i], tempChar);

            strcpy(tempChar, rekening[n]);
            strcpy(rekening[n], rekening[i]);
            strcpy(rekening[i], tempChar);

            strcpy(tempChar, uang[n]);
            strcpy(uang[n], uang[i]);
            strcpy(uang[i], tempChar);

            strcpy(tempChar, deposit[n]);
            strcpy(deposit[n], deposit[i]);
            strcpy(deposit[i], tempChar);
            
            n++;

        }
    }
}