// disini terdapat pembukaan rekening, penutupan rekening, dan pengaturan rekening nasabah misalnya seperti menabung uang
// hanya admin yang dapat menambahkan uang kedalam rekening nasabah

extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int bukaRekening() {

	char namaDepan[20], namaBelakang[20], passNasabah[20], rekening[9];
    char stringNasabah[256];
    char *stripped, *checkNama, *checkRekening;
    float setorUang;
    FILE *fileNasabah;

    printf("||===============================||\n");
    printf("||      Pembukaan Rekening       ||\n");
    printf("||===============================||\n\n");

    fileNasabah = fopen("data/nasabah.txt", "r");           // membuka file dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    printf("#   Nama depan nasabah: ");
    scanf("%s", &namaDepan);
    printf("#   Nama belakang nasabah: ");
    scanf("%s", &namaBelakang);
    printf("#   Password: ");
    scanf("%s", &passNasabah);
    printf("#   Nomor rekening nasabah: ");
    scanf("%s", &rekening);

    if(atoi(rekening) >= 100000000) {     // rekening maksimal 8 digit
        
        printf("\n||  Maksimal nomor rekening adalah 8 digit!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        system("cls");
        fclose(fileNasabah);

        bukaRekening();

    }
    else if(atoi(rekening) <= 1000000) {

        printf("\n||  Minimal nomor rekening adalah 6 digit!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        system("cls");
        fclose(fileNasabah);

        bukaRekening();

    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mengecek apakah nama depan yang dimasukkan ada yang sama

        stripped = strtok(stringNasabah, "\n");
        checkNama = strtok(stripped, " ");
        checkRekening = strtok(NULL, " ");
        checkRekening = strtok(NULL, " ");
        checkRekening = strtok(NULL, " ");

        if(strcmpi(namaDepan, checkNama) == 0 && strcmpi(rekening, checkRekening) == 0) {   // jika nama dan rekening sama seperti yang sudah ada

            printf("\n||  Nama Depan dan Rekning tidak dapat digunakan!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileNasabah);

            menuAdmin();
        
        }
        else if(strcmpi(namaDepan, checkNama) == 0) {     // jika ditemukan ada yang sama maka tidak dapat digunakan

            printf("\n||  Nama tidak dapat digunakan!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileNasabah);

            menuAdmin();

        }
        else if(strcmpi(rekening, checkRekening) == 0) {    // jika ditemukan nomor rekening yang sama

            printf("\n||  Nomor Rekening tidak dapat digunakan!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);
            fclose(fileNasabah);

            menuAdmin();

        }
    }

    fclose(fileNasabah);                // menutup file
    fileNasabah = fopen("data/nasabah.txt", "a+");    // membuka kembali file dalam mode append

    printf("\n#   Jumlah uang setoran nasabah: Rp.");           // jumlah setoran awal
    scanf("%f", &setorUang);

    fprintf(fileNasabah, "%s %s ", namaDepan, namaBelakang);    // nama
    fprintf(fileNasabah, "%s ", passNasabah);                   // pass untuk login nanti
    fprintf(fileNasabah, "%s ", rekening);                      // rekening
    fprintf(fileNasabah, "%.4f ", setorUang);                     // uang yang di setor
    fprintf(fileNasabah, "%d\n", 0);                            // deposito, saat awal di set 0

    fclose(fileNasabah);                                        // menutup file

    printf("\n||  Nasabah Berhasil Ditambahkan!\n");
    printf("||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    menuAdmin(); // kembali ke menuAdmin

}

int tutupRekening() {

    char stringNasabah[256], stringTemp[256], rekening[10];
    char namaDepan[20], namaBelakang[20];
    char *str1, *str2, *str3;
    char *stripped;
    char chs;
    int line, i, found = 0;
    line = i = 0;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    printf("||==============================||\n");
    printf("||      Penutupan Rekening      ||\n");
    printf("||==============================||\n\n");

    // memasukkan data nasabah yang ingin di tutup
    printf("||  !!Data Yang Dicari Harus Sesuai!!   ||\n");
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

        tutupRekening();    

    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mencari nasabah yang ingin ditutup

        line++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");


        if(strcmpi(namaDepan, str1) == 0 && strcmpi(namaBelakang, str2) == 0 && strcmpi(rekening, str3) == 0) { // jika namanya ketemu

            printf("\n||  Nama: %s %s\n", str1, str2);
            printf("||  Nomor Rekening: %s\n", str3);

            printf("||  Hapus Rekening?(Y/N) ");
            scanf("%s", &chs);

            if(chs == 'y' || chs == 'Y') {

                found = 1;

                break;

            }
            else if(chs == 'n' || chs == 'N') {

                printf("\n||  Penghapusan Akun Batal! Kembali ke menu Admin!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");

                menuAdmin();


            }
            else {

                printf("\n|| Input Invalid!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");

                tutupRekening();

            }
        }
    }

    
    if(found == 0) {        // jika nasabah tidak ditemukan

        printf("\n||  Nasabah Tidak Ditemukan!\n");
        printf("||  ");
        system("pause");
        system("cls");
        fflush(stdin);
        fclose(fileNasabah);

        menuAdmin();
         
    }

    fclose(fileNasabah);                                    // menutup file
    fileNasabah = fopen("data/nasabah.txt", "a+");          // membuka kembali file nasabah.txt dalam mode append
    FILE *fileTemp = fopen("data/tempNasabah.txt", "a+");         // membuka file tempNasabah.txt dalam mode append plus

    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk me write data yang ada di dalam nasabah ke tempNasabah

        i++;
        if(i == line) {     // jika sampai di line nasabah yang ingin di hapus maka di skip

            continue;

        }
        else {

            fprintf(fileTemp, "%s", stringNasabah);

        }
    }

    fclose(fileNasabah);    // menutup file
    fclose(fileTemp);       // menutup file

    remove("data/nasabah.txt");                         // menghapus file nasabah.txt
    rename("data/tempNasabah.txt", "data/nasabah.txt"); // merename file tempNasabah.txt menjadi nasabah.txt

    printf("\n||  Nasabah Berhasil Dihapus! Kembali ke menu Admin!\n");
    printf("||  ");
    system("pause");
    fflush(stdin);
    system("cls");

    menuAdmin();    // kembali ke menuAdmin

}

int editRekening() {

    char stringNasabah[256], stringTemp[256], rekening[10];
    char namaDepan[20], namaBelakang[20];
    char strFile[6][20];
    char chs2, *str1, *str2, *str3, *str4, *str5, *str6, *str7;
    char *stripped;
    int chs, line, i, found = 0;
    float setoran, currentUang;
    line = i = 0;
    

    printf("||==================================||\n");
    printf("||      Edit Rekening Nasabah       ||\n");
    printf("||==================================||\n\n");

    printf("#   1. Setor Uang\n");
    printf("#   2. Kembali\n");
    printf("#   Pilihan: ");
    scanf("%d", &chs);      // pilihan menu

    switch(chs) {

        case 1: {

            break;

        }
        case 2: {

            fflush(stdin);
            system("cls");

            menuAdmin();    // kembali ke menu admin

        }
        default: {

            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            fflush(stdin);
            system("cls");

            editRekening(); // kembali ke editRekening

        }
    }

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    // input nasabah yang ingin di edit
    printf("\n||  !!Input Nasabah Yang Ingin Di Edit!!   ||\n");
    printf("\n#   Nama Depan:   ");
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

        editRekening();

    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mencari nasabah yang ingin di edit di file

        line++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");


        if(strcmpi(namaDepan, str1) == 0 && strcmpi(namaBelakang, str2) == 0 && strcmpi(rekening, str3) == 0) { // jika nasabah ketemu dalam file

            printf("\n||  Nama: %s %s\n", str1, str2);
            printf("||  Nomor Rekening: %s\n", str3);

            printf("||  Benar Nasabah Ini?(Y/N) ");
            scanf("%s", &chs2);

            if(chs2 == 'y' || chs2 == 'Y') {

                found = 1;

                break;

            }
            else if(chs2 == 'n' || chs2 == 'N') {

                printf("\n||  Pengeditan Akun Batal!, Kembali ke menu Admin!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");

                menuAdmin();


            }
            else {

                printf("\n|| Input Invalid!\n");
                printf("||  ");
                system("pause");
                fflush(stdin);
                system("cls");

                editRekening();

            }
        }
    }

    if(found == 0) {        // nasabah yang dicari tidak ketemu dalam file

        printf("\n||  Nasabah Tidak Ditemukan!\n");
        printf("\n||  ");
        system("pause");
        system("cls");
        fflush(stdin);
        fclose(fileNasabah);

        editRekening();
         
    }

    printf("\n#   Setor uang: Rp. ");   // input banyaknya uang yang ingin di setor
    scanf("%f", &setoran);

    fclose(fileNasabah);                            // close fileNasabah
    fileNasabah = fopen("data/nasabah.txt", "a+");  // membuka kembali fileNasabah dalam mode append
    FILE *fileTemp = fopen("data/tempNasabah.txt", "a+");   // membuka file tempNasabah.txt dalam mode append

    line = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mencari berapa banyak uang yang dimiliki nasabah

        line++;

        // pengambilan data dipisahkan oleh spasi
        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str5 = strtok(NULL, " ");
        str6 = strtok(NULL, " ");

        if(strcmpi(namaDepan, str1) == 0 && strcmpi(namaBelakang, str2) == 0 && strcmpi(rekening, str4) == 0) {

            currentUang = atoi(str5);
            break;
        
        }
    }

    currentUang += setoran;     // menambahkan uang yang dimiliki nasabah dengan banyak uang yang disetor

    fclose(fileNasabah);                            // menutup file
    fileNasabah = fopen("data/nasabah.txt", "a+");  // membuka file nasabah.txt dalam mode read

    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk menuliskan data terbaru ke dalam file

        i++;
        if(i == line) {

            stripped = strtok(stringNasabah, "\n");
            str1 = strtok(stripped, " ");
            str2 = strtok(NULL, " ");
            str3 = strtok(NULL, " ");
            str4 = strtok(NULL, " ");
            str5 = strtok(NULL, " ");
            str6 = strtok(NULL, " ");

            fprintf(fileTemp, "%s %s %s %s %.4f %s\n", str1, str2, str3, str4, currentUang, str6);
            continue;

        }
        else {

            fprintf(fileTemp, "%s", stringNasabah);

        }
    }

    fclose(fileNasabah);    // menutup file
    fclose(fileTemp);       // menutup file

    remove("data/nasabah.txt");                         // menghapus file nasabah.txt
    rename("data/tempNasabah.txt", "data/nasabah.txt"); // rename tempNasabah menjadi nasabah.txt

    printf("\n||  Uang Berhasil Ditambahkan!\n");
    printf("||  Saldo Sekarang adalah Rp.%.4f\n", currentUang);
    printf("||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    menuAdmin();    // kembali ke menu admin

}