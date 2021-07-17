// disini digunakan oleh nasabah untuk withdraw uangnya dan dapat transfer ke akun lainnya

extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int withdrawUang() {
	
    char stringNasabah[256];
    char *stripped, *str1, *str2, *str3, *str4, *str5, *str6;
    int chs, i, line;
    int nasabahCount = 0;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mengetahui berapa jumlah nasabah dalam file

        nasabahCount++;
    
    }

    fclose(fileNasabah);                            // menutup file
    fileNasabah = fopen("data/nasabah.txt", "r");   // membuka kembali file dalam mode read

    if(fileNasabah == NULL) {                       // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    float uangNasabah;

    line = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mencari siapa nasabah yang login

        line++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str5 = strtok(NULL, " ");
        str6 = strtok(NULL, " ");

        // jika nasabah yang login ketemu maka akan diambil data uangnya
        if(strcmp(usernameMasukNasabah, str1) == 0 && strcmp(passMasukNasabah, str3) == 0 && strcmp(rekeningMasukNasabah, str4) == 0) {

            uangNasabah = atoi(str5);

            break;

        }
    }

    fclose(fileNasabah);

    float penarikan;

    printf("||==================================||\n");
    printf("||      Penarikan Saldo Nasabah     ||\n");
    printf("||==================================||\n\n");

    printf("||  Saldo Anda Saat Ini: Rp. %.4f\n", uangNasabah);
    printf("#   1. Tarik Saldo\n");
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

            menuNasabah();      // kembali ke menu nasabah

        }
        default: {

            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);

            withdrawUang();     // kembali ke withdraw uang

        }

    }

    printf("\n#   Jumlah Penarikan: "); // input banyaknya jumlah withdraw
    scanf("%f", &penarikan);

    if(penarikan > uangNasabah) {       // jika jumlah yang ditarik melebihi saldo

        printf("\n||  Saldo Tidak Mencukupi!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        system("cls");

        withdrawUang();

    }

    uangNasabah -= penarikan;

    fileNasabah = fopen("data/nasabah.txt", "a+");          // membuka file nasabah.txt dalam mode append
    FILE *fileTemp = fopen("data/tempNasabah.txt", "a+");   // membuka file tempNasabah dalam mode append

    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // menuliskan data dalam nasabah.txt ke tempNasabah.txt

        i++;
        if(i == line) { // mengupdate data uang nasabah yang login

            stripped = strtok(stringNasabah, "\n");
            str1 = strtok(stripped, " ");
            str2 = strtok(NULL, " ");
            str3 = strtok(NULL, " ");
            str4 = strtok(NULL, " ");
            str5 = strtok(NULL, " ");
            str6 = strtok(NULL, " ");

            fprintf(fileTemp, "%s %s %s %s %.4f %s\n", str1, str2, str3, str4, uangNasabah, str6);
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

    printf("\n||  Uang Berhasil Ditarik!\n");
    printf("||  Saldo Sekarang adalah %.4f\n", uangNasabah);
    printf("||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    withdrawUang(); // kembali ke withdraw uang

}

int transferUang() {

    char stringNasabah[256];
    char *stripped, *str1, *str2, *str3, *str4, *str5, *str6;                                       // data untuk pengirim
    char *str1Penerima, *str2Penerima, *str3Penerima, *str4Penerima, *str5Penerima, *str6Penerima;  // data untuk penerima
    int chs, i, linePengirim, linePenerima, rekeningTujuan;
    int nasabahCount = 0;
    int found = 0;

    // membuka file dan menghitung banyak data yang ada dalam file
    FILE *fileNasabah = fopen("data/nasabah.txt", "r");           // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mencari jumlah nasabah dalam file

        nasabahCount++;
    
    }

    fclose(fileNasabah);                            // menutup file
    fileNasabah = fopen("data/nasabah.txt", "r");   // membuka kembali file untuk diakses

    float uangNasabah, uangPenerima;

    // menghitung dimana letak dari data pengirim dan memisahkannya menjadi beberapa string
    linePengirim = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {

        linePengirim++;

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");
        str4 = strtok(NULL, " ");
        str5 = strtok(NULL, " ");
        str6 = strtok(NULL, " ");

        if(strcmp(usernameMasukNasabah, str1) == 0 && strcmp(passMasukNasabah, str3) == 0 && strcmp(rekeningMasukNasabah, str4) == 0) {

            uangNasabah = atoi(str5);

            break;

        }
    }

    fclose(fileNasabah);    // menutup file setelah selesai di akses

    float jumlahKirim;

    printf("||===================================||\n");
    printf("||      Transfer Uang Dalam Bank     ||\n");
    printf("||===================================||\n\n");

    printf("||  Saldo Anda Saat Ini: Rp. %.4f\n", uangNasabah);
    printf("#   1. Transfer Uang\n");
    printf("#   2. Kembali\n");
    printf("#   Pilihan: ");
    scanf("%d", &chs);          // input pilihan menu

    switch(chs) {
        
        case 1: {

            break;

        }
        case 2: {

            fflush(stdin);
            system("cls");

            menuNasabah();  // kembali ke menu nasabah

        }
        default: {

            printf("\n||  Input Invalid!\n");
            printf("||  ");
            system("pause");
            system("cls");
            fflush(stdin);

            transferUang(); // kembali ke transfer uang

        }

    }

    printf("\n#   Rekening Tujuan: ");  // rekening tujuan transfer
    scanf("%d", &rekeningTujuan);

    if(rekeningTujuan == atoi(str4)) {  // TIDAK BISA MENGIRIM KE REKENING SENDIRI NANTI JADI PENCUCUCIAN UANG

        printf("\n||  Tidak dapat mengirim ke rekening sendiri!\n");
        printf("||  ");
        system("pause");
        system("cls");
        fflush(stdin);

        transferUang();

    }
    fileNasabah = fopen("data/nasabah.txt", "r");                               // membuka file untuk diakses

    if(fileNasabah == NULL) {                                                   // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    linePenerima = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop untuk mengetahui letak penerima dan memisahkannya 
                                                                                // menjadi beberapa string
        linePenerima++;                                                         

        stripped = strtok(stringNasabah, "\n");
        str1Penerima = strtok(stripped, " ");
        str2Penerima = strtok(NULL, " ");
        str3Penerima = strtok(NULL, " ");
        str4Penerima = strtok(NULL, " ");
        str5Penerima = strtok(NULL, " ");
        str6Penerima = strtok(NULL, " ");

        // jika rekening penerima ketemu
        if(rekeningTujuan == atoi(str4Penerima)) {

            uangPenerima = atoi(str5Penerima);      // diambil data uang dari rekening penerima
            found = 1;
            break;

        }
    }
    fclose(fileNasabah);    // menutup file setelah selesai dipakai

    if(found == 0) {        // jika rekening tujuan tidak ditemukan dalam file

        printf("\n||  Nasabah Tidak Ditemukan!\n");
        printf("||  ");
        system("pause");
        system("cls");
        fflush(stdin);
        fclose(fileNasabah);

        transferUang();

    }

    printf("\n#   Jumlah Transfer: Rp. ");  // jumlah uang yang di transfer
    scanf("%f", &jumlahKirim);

    if(jumlahKirim > uangNasabah) {         // jika saldo tidak mencukupi untuk transfer

        printf("\n||  Saldo Tidak Mencukupi!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        system("cls");

        transferUang();

    }

    uangNasabah -= jumlahKirim;
    uangPenerima += jumlahKirim;

    // membuka file untuk diakses
    fileNasabah = fopen("data/nasabah.txt", "a+");          // membuka file nasabah.txt dalam mode append
    FILE *fileTemp = fopen("data/tempNasabah.txt", "a+");   // membuka file tempNasabah dalam mode append

    // Mengedit file dengan data terbaru dari pengirim
    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // menulis data dalam nasabah.txt ke dalam tempNasabah.txt

        i++;
        if(i == linePengirim) { // mengupdate data nasabah pengirm

            stripped = strtok(stringNasabah, "\n");
            str1 = strtok(stripped, " ");
            str2 = strtok(NULL, " ");
            str3 = strtok(NULL, " ");
            str4 = strtok(NULL, " ");
            str5 = strtok(NULL, " ");
            str6 = strtok(NULL, " ");

            fprintf(fileTemp, "%s %s %s %s %.4f %s\n", str1, str2, str3, str4, uangNasabah, str6);

            continue;

        }
        else {

            fprintf(fileTemp, "%s", stringNasabah);

        }
    }

    // menutup file
    fclose(fileNasabah);
    fclose(fileTemp);

    remove("data/nasabah.txt");
    rename("data/tempNasabah.txt", "data/nasabah.txt");

    // membuka kembali file untuk diakses
    fileNasabah = fopen("data/nasabah.txt", "a+");
    fileTemp = fopen("data/tempNasabah.txt", "a+");

    // Mengedit file dengan data terbaru dari penerima
    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {

        i++;
        if(i == linePenerima) { // mengedit data terbaru dari penerima

            stripped = strtok(stringNasabah, "\n");
            str1 = strtok(stripped, " ");
            str2 = strtok(NULL, " ");
            str3 = strtok(NULL, " ");
            str4 = strtok(NULL, " ");
            str5 = strtok(NULL, " ");
            str6 = strtok(NULL, " ");

            fprintf(fileTemp, "%s %s %s %s %.4f %s\n", str1, str2, str3, str4, uangPenerima, str6);

        }
        else {

            fprintf(fileTemp, "%s", stringNasabah);

        }
    }

    // menutup file setelah selesai diakses
    fclose(fileNasabah);
    fclose(fileTemp);

    // merename file temporary menjadi fle aslinya
    remove("data/nasabah.txt");
    rename("data/tempNasabah.txt", "data/nasabah.txt");

    printf("\n|| Transfer Berhasil!\n");
    printf("||  ");
    system("pause");
    system("cls");
    fflush(stdin);

    transferUang(); // kembali ke transfer uang

}