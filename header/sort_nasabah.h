// disini berfungsi untuk sort nasabah berdasarkan nama, rekening, jumlah uang

extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int listNasabah() {

    char stringNasabah[256];
    char *stripped, *str1, *str2, *str3, *str4, *str5, *str6;
    int sort, i, x;
    int nasabahCount = 0;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // menghitung jumlah nasabah dalam file

        nasabahCount++;
    
    }

    fclose(fileNasabah); // menutup file

    char namaDepan[nasabahCount+1][20], namaBelakang[nasabahCount+1][20], rekeningNasabah[nasabahCount+1][10]; 
    char uangNasabah[nasabahCount+1][50], depositNasabah[nasabahCount+1][50];

    fileNasabah = fopen("data/nasabah.txt", "r");           // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    // mengambil data dari file dan diubah menjad array
    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str5 = strtok(NULL, " ");

        strcpy(namaDepan[i], str1);
        strcpy(namaBelakang[i], str2);
        strcpy(rekeningNasabah[i], str3);
        strcpy(uangNasabah[i], str4);
        strcpy(depositNasabah[i], str5);

        i++;

    }

    fclose(fileNasabah);    // menutup file

    printf("||==================================||\n");
    printf("||      List Sorting Nasabah        ||\n");
    printf("||==================================||\n\n");

    while(x != -1) {

        printf("||  Sorting berdasarkan:\n");
        printf("#   1. Nama Nasabah (Ascending)\n");
        printf("#   2. Nama Nasabah (Descending)\n");
        printf("#   3. Nomor Rekening (Ascending)\n");
        printf("#   4. Nomor Rekening (Descending)\n");
        printf("#   5. Jumlah Saldo Nasabah (Ascending)\n");
        printf("#   6. Jumlah Saldo Nasabah (Descending)\n");
        printf("#   7. Exit\n");
        printf("#   Pilihan: ");
        scanf("%d", &sort);     // pilihan menu

        switch(sort) {

            case 1: {

                sortNama(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);
                displaySort(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);

                fflush(stdin);

                continue;

            }
            case 2: {

                sortNama(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);
                displaySort(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);

                fflush(stdin);

                continue;

            }
            case 3: {
            
                sortRekening(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);
                displaySort(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);

                fflush(stdin);

                continue;

            }
            case 4: {
            
                sortRekening(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);
                displaySort(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);

                fflush(stdin);

                continue;

            }
            case 5: {

                sortSaldo(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);
                displaySort(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);

                fflush(stdin);

                continue;

            }
            case 6: {

                sortSaldo(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);
                displaySort(namaDepan, namaBelakang, rekeningNasabah, uangNasabah, depositNasabah, nasabahCount, sort);

                fflush(stdin);

                continue;

            }
            case 7: {

                fflush(stdin);
                system("cls");

                menuAdmin();

            }
            default: {
            
                printf("\n||  Input Invalid!\n");
                system("pause");
                fflush(stdin);

                continue;

            }
        }
    }
}

int displaySort(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count) {

    int i;
    char nama[count][30];

    printf("\n");

    for(i=0; i<count; i++) {

        sprintf(nama[i], "%s %s", namaFront[i], namaBack[i]);

    }
    

    printf(" %-8s %-16s %-17s %-23s %s", "No", "Nama", "Rekening", "Saldo", "Deposit\n\n");
    for(i=0; i<count; i++) {

        printf(" %d.  %-20s  %-15s  Rp. %-18s   Rp. %s\n", i+1, nama[i], rekening[i], uang[i], deposit[i]);

    }

    printf("\n");

}

int sortNama(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count, int chs) {

    int temp, i, j;
    char tempChar[30];

    for(i=0; i<count - 1; i++) {
        for(j=0; j<count - i - 1; j++) { 

            if(chs == 1) {      // data di sort berdasarkan nama secara ascending

                if(strcmp(namaFront[j], namaFront[j+1]) > 0) {

                    strcpy(tempChar, namaFront[j]);
                    strcpy(namaFront[j], namaFront[j+1]);
                    strcpy(namaFront[j+1], tempChar);

                    strcpy(tempChar, namaBack[j]);
                    strcpy(namaBack[j], namaBack[j+1]);
                    strcpy(namaBack[j+1], tempChar);

                    strcpy(tempChar, rekening[j]);
                    strcpy(rekening[j], rekening[j+1]);
                    strcpy(rekening[j+1], tempChar);

                    strcpy(tempChar, uang[j]);
                    strcpy(uang[j], uang[j+1]);
                    strcpy(uang[j+1], tempChar);

                    strcpy(tempChar, deposit[j]);
                    strcpy(deposit[j], deposit[j+1]);
                    strcpy(deposit[j+1], tempChar);

                }
            }
            else if(chs == 2) {     // data di sort berdasarkan nama secarad descending

                if(strcmp(namaFront[j], namaFront[j+1]) < 0) {

                    strcpy(tempChar, namaFront[j]);
                    strcpy(namaFront[j], namaFront[j+1]);
                    strcpy(namaFront[j+1], tempChar);

                    strcpy(tempChar, namaBack[j]);
                    strcpy(namaBack[j], namaBack[j+1]);
                    strcpy(namaBack[j+1], tempChar);

                    strcpy(tempChar, rekening[j]);
                    strcpy(rekening[j], rekening[j+1]);
                    strcpy(rekening[j+1], tempChar);

                    strcpy(tempChar, uang[j]);
                    strcpy(uang[j], uang[j+1]);
                    strcpy(uang[j+1], tempChar);

                    strcpy(tempChar, deposit[j]);
                    strcpy(deposit[j], deposit[j+1]);
                    strcpy(deposit[j+1], tempChar);

                }
            }
        }
    }
}

int sortRekening(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count, int chs) {

    int temp, i, j;
    char tempChar[30];

    for(i=0; i<count - 1; i++) {
        for(j=0; j<count - i - 1; j++) { 

            if(chs == 3) {      // data di sort berdasarkan nomor rekening secara ascending

                if(strcmp(rekening[j], rekening[j+1]) > 0) {

                    strcpy(tempChar, rekening[j]);
                    strcpy(rekening[j], rekening[j+1]);
                    strcpy(rekening[j+1], tempChar);

                    strcpy(tempChar, namaFront[j]);
                    strcpy(namaFront[j], namaFront[j+1]);
                    strcpy(namaFront[j+1], tempChar);

                    strcpy(tempChar, namaBack[j]);
                    strcpy(namaBack[j], namaBack[j+1]);
                    strcpy(namaBack[j+1], tempChar);

                    strcpy(tempChar, uang[j]);
                    strcpy(uang[j], uang[j+1]);
                    strcpy(uang[j+1], tempChar);

                    strcpy(tempChar, deposit[j]);
                    strcpy(deposit[j], deposit[j+1]);
                    strcpy(deposit[j+1], tempChar);

                }
            }
            else if(chs == 4) {     // data di sort berdasarkan nomor rekening secara descending

                if(strcmp(rekening[j], rekening[j+1]) < 0) {

                    strcpy(tempChar, rekening[j]);
                    strcpy(rekening[j], rekening[j+1]);
                    strcpy(rekening[j+1], tempChar);

                    strcpy(tempChar, namaFront[j]);
                    strcpy(namaFront[j], namaFront[j+1]);
                    strcpy(namaFront[j+1], tempChar);

                    strcpy(tempChar, namaBack[j]);
                    strcpy(namaBack[j], namaBack[j+1]);
                    strcpy(namaBack[j+1], tempChar);

                    strcpy(tempChar, uang[j]);
                    strcpy(uang[j], uang[j+1]);
                    strcpy(uang[j+1], tempChar);

                    strcpy(tempChar, deposit[j]);
                    strcpy(deposit[j], deposit[j+1]);
                    strcpy(deposit[j+1], tempChar);

                }
            }
        }
    }
}

int sortSaldo(char namaFront[][20], char namaBack[][20], char rekening[][10], char uang[][50], char deposit[][50], int count, int chs) {

    int temp, i, j;
    char tempChar[30];

    for(i=0; i<count - 1; i++) {
        for(j=0; j<count - i - 1; j++) { 

            if(chs == 5) {      // data di sort berdasarkan jumlah saldo secara ascending

                if(atoi(uang[j]) > atoi(uang[j+1])) {

                    strcpy(tempChar, uang[j]);
                    strcpy(uang[j], uang[j+1]);
                    strcpy(uang[j+1], tempChar);

                    strcpy(tempChar, namaFront[j]);
                    strcpy(namaFront[j], namaFront[j+1]);
                    strcpy(namaFront[j+1], tempChar);

                    strcpy(tempChar, namaBack[j]);
                    strcpy(namaBack[j], namaBack[j+1]);
                    strcpy(namaBack[j+1], tempChar);

                    strcpy(tempChar, rekening[j]);
                    strcpy(rekening[j], rekening[j+1]);
                    strcpy(rekening[j+1], tempChar);

                    strcpy(tempChar, deposit[j]);
                    strcpy(deposit[j], deposit[j+1]);
                    strcpy(deposit[j+1], tempChar);

                }
            }
            else if(chs == 6) { // data di sort berdasarkan saldo secara descending

                if(atoi(uang[j]) < atoi(uang[j+1])) {

                    strcpy(tempChar, uang[j]);
                    strcpy(uang[j], uang[j+1]);
                    strcpy(uang[j+1], tempChar);

                    strcpy(tempChar, namaFront[j]);
                    strcpy(namaFront[j], namaFront[j+1]);
                    strcpy(namaFront[j+1], tempChar);

                    strcpy(tempChar, namaBack[j]);
                    strcpy(namaBack[j], namaBack[j+1]);
                    strcpy(namaBack[j+1], tempChar);

                    strcpy(tempChar, rekening[j]);
                    strcpy(rekening[j], rekening[j+1]);
                    strcpy(rekening[j+1], tempChar);

                    strcpy(tempChar, deposit[j]);
                    strcpy(deposit[j], deposit[j+1]);
                    strcpy(deposit[j+1], tempChar);

                }
            }
        }
    }
}