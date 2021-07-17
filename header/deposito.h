// disini berfungsi untuk mendepositkan uang dan juga melihat nasabah mana saja yang mendepositkan uang
// mendepositkan uang hanya dapat dilakukan oleh admin
// nasabah hanya dapat melihat deposit yang ia lakukan

extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int depositAdmin() {

    int chs;

    printf("||==============================||\n");
    printf("||      Menu Deposit Admin      ||\n");
    printf("||==============================||\n\n");

    printf("#   1. Edit Deposito Nasabah\n");
    printf("#   2. Kembali\n");
    printf("#   Pilihan: ");
    scanf("%d", &chs);      // memasukkan pilihan menu

    switch(chs) {

        case 1: {

            system("cls");
            fflush(stdin);

            editDeposit();
            
        }
        case 2: {

            system("cls");
            fflush(stdin);

            menuAdmin();    // kembali ke menuAdmin

        }
        default: {

            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            fflush(stdin);
            system("cls");

            depositAdmin(); // kembali ke depositAdmin

        }
    }
}

int editDeposit() {

    char stringNasabah[256], stringTemp[256];
    char namaDepan[20], namaBelakang[20], rekening[20];
    char chs2, *str1, *str2, *str3, *str4, *str5, *str6, *str7;
    char *stripped;
    int chs, line, i, found;
    float setoran, currentDeposit, currentUang;
    line = i = found = 0;

    printf("||======================================||\n");
    printf("||      Pengeditan Deposito Nasabah     ||\n");
    printf("||======================================||\n\n");

    printf("||  Deposito Hanya Dapat Ditambahkan Dari Saldo Dalam Rekening!\n");
    printf("#   1. Tambah Deposit\n");
    printf("#   2. Kurangi Deposito\n");
    printf("#   Pilihan: ");
    scanf("%d", &chs);                      // pilihan jenis deposit

    if(chs > 2 || chs < 1) {

        printf("\n||  Input Invalid!\n");   // jika yang di input salah
        printf("||  ");
        system("pause");
        system("cls");
        fflush(stdin);

        depositAdmin();

    }

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    // input data nasabah yang ingin di edit deposito
    printf("\n||  !!Input Data Nasabah Yang Ingin Di Edit!!   ||\n");
    printf("#   Nama Depan:   ");
    scanf("%s", &namaDepan);
    printf("#   Nama Belakang: ");
    scanf("%s", &namaBelakang);
    printf("#   Nomor Rekening: ");
    scanf("%s", &rekening);

    if(atoi(rekening) >= 100000000) {     // rekening maksimal 8 digit

        printf("\n||  Maksimal nomor rekening adalah 8 digit!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        system("cls");
        fclose(fileNasabah);

        editDeposit();

    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mencari data nasabah yang di input dalam file nasabah.txt

        line++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");


        if(strcmpi(namaDepan, str1) == 0 && strcmpi(namaBelakang, str2) == 0 && strcmpi(rekening, str3) == 0) { // jika data nasabah yang dicari ketemu

            printf("\n||  Nama: %s %s\n", str1, str2);
            printf("||  Nomor Rekening: %s\n", str3);

            printf("||  Benar Nasabah Ini?(Y/N) ");
            scanf(" %c", &chs2);

            if(chs2 == 'y' || chs2 == 'Y') {

                found = 1;
                break;

            }
            else if(chs2 == 'n' || chs2 == 'N') {

                printf("\n||  Pengeditan Deposit Batal!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");
                fclose(fileNasabah);

                depositAdmin(); // kembali ke edit deposit

            }
            else {

                printf("\n|| Input Invalid!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");
                fclose(fileNasabah);

                editDeposit();  // kembali ke edit deposit

            }
        }
    }

    if(found == 0) {     // jika nasabah yang dicari tidak ketemu dalam file

        printf("\n||  Nasabah Tidak Ditemukan!\n");
        printf("||  ");
        system("pause");
        system("cls");
        fflush(stdin);
        fclose(fileNasabah);

        editDeposit();  // kembali ke edit deposit

    }

    printf("\n#   Jumlah: Rp. ");       // input banyaknya jumlah deposit
    scanf("%f", &setoran);

    fclose(fileNasabah);                                    // menutup file
    fileNasabah = fopen("data/nasabah.txt", "a+");          // membuka file nasabah.txt
    FILE *fileTemp = fopen("data/tempNasabah.txt", "a+");   // membuka file tempNasabah.txt dalam mode append

    line = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mengambil data deposito nasabah

        line++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str5 = strtok(NULL, " ");
        str6 = strtok(NULL, " ");
        str7 = strtok(NULL, " ");

        if(strcmpi(namaDepan, str1) == 0 && strcmpi(namaBelakang, str2) == 0 && strcmpi(rekening, str4) == 0) {

            currentDeposit = atoi(str6);
            currentUang = atoi(str5);
            break;
        
        }
    }

    if(chs==1) {        // jika nasabah ingin menambahkan deposito

        if(currentUang < setoran) {

            printf("\n|| Saldo dalam rekening kurang untuk melakukan Deposito!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileNasabah);

            editDeposit();

        }

        currentDeposit += setoran;
        currentUang -= setoran;

    }
    else if(chs == 2) { // jika nasabah ingin mengurangi deposito

        if(currentDeposit < setoran) {

            printf("\n||    Saldo Deposit terlalu sedikit untuk dikurangkan!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileNasabah);

            editDeposit();

        }

        currentDeposit -= setoran;
        currentUang += setoran;

    }
    

    fclose(fileNasabah);                            // menutup file
    fileNasabah = fopen("data/nasabah.txt", "a+");  // membuka kembali file nasbah.txt

    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk write data dalam nasabah.txt ke tempNasabah.txt

        i++;
        if(i == line) { // mengganti data nasabah yang baru mengedit deposito

            stripped = strtok(stringNasabah, "\n");
            str1 = strtok(stripped, " ");
            str2 = strtok(NULL, " ");
            str3 = strtok(NULL, " ");
            str4 = strtok(NULL, " ");

            fprintf(fileTemp, "%s %s %s %s %.4f %.4f\n", str1, str2, str3, str4, currentUang, currentDeposit);
            continue;

        }
        else {

            fprintf(fileTemp, "%s", stringNasabah); // menuliskan satu line string

        }
    }

    fclose(fileNasabah);    // menutup file
    fclose(fileTemp);       // menutup file

    remove("data/nasabah.txt");                         // menghapus file nasabah.txt
    rename("data/tempNasabah.txt", "data/nasabah.txt"); // me rename tempNasabah.txt menjadi nasabah.txt

    printf("\n||  Deposit Berhasil Diedit!\n");
    printf("||  Deposit Sekarang adalah %.4f\n", currentDeposit);
    printf("||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    depositAdmin(); // kembali ke deposit admin

}

int lihatDeposit() {

    char stringNasabah[256];
    char *stripped, *str1, *str2, *str3, *str4;
    int chs, i, line;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    float depositNasabah;

    line = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {       // loop untuk mengambil data deposito nasabah yang login

        line++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");

        if(strcmpi(usernameMasukNasabah, str1) == 0 && strcmpi(passMasukNasabah, str2) == 0 && strcmpi(rekeningMasukNasabah, str3) == 0) {

            depositNasabah = atoi(str4);

            break;

        }
    }

    fclose(fileNasabah);    // menutup file

    printf("||========================================\n");
    printf("||  Uang Anda Dalam Deposito Ada Sebesar\n");
    printf("||  Rp. %.4f,00\n", depositNasabah);
    printf("||  \n");
    printf("||  ");
    system("pause");
    system("cls");

    menuNasabah();  // kembali ke menuNasabah

}