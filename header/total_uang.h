// disini untuk menghitung total uang dalam bank secara recrusive

extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

int totalUang() {

    char stringNasabah[256];
    char *stripped, *str1, *str2;
    int chs, i;
    int nasabahCount = 0;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    if(fileNasabah == NULL) {                               // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // menghitung berapa banyak jumlah nasabah dalam file

        nasabahCount++;
    
    }

    fclose(fileNasabah);                            // menutup file
    fileNasabah = fopen("data/nasabah.txt", "r");   // membuka kembali file

    if(fileNasabah == NULL) {                       // jika file nasabah.txt tidak ditemukan akan terjadi error

        printf("||  ERROR File Not Found\n");
        printf("||  ");
        system("pause");
        system("cls");

        exit(0);
        
    }

    char uangNasabah[nasabahCount][50], depositNasabah[nasabahCount][50];
    float saldo[nasabahCount], deposit[nasabahCount];

    // mengambl data nasabah namun hanya uang dan depositonya saja
    i = 0;
    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str1 = strtok(NULL, " ");
        str1 = strtok(NULL, " ");
        str1 = strtok(NULL, " ");
        str1 = strtok(NULL, " ");
        str2 = strtok(NULL, " ");

        strcpy(uangNasabah[i], str1);
        strcpy(depositNasabah[i], str2);
        saldo[i] = atoi(uangNasabah[i]);
        deposit[i] = atoi(depositNasabah[i]);

        i++;

    }

    fclose(fileNasabah);    // menutup file

    printf("||==================================||\n");
    printf("||      Total Uang Dalam Bank       ||\n");
    printf("||==================================||\n\n");

    // menjumlahkan keseluruhan data ke dalam function recursive
    printf("||  Total Uang Dalam Bank Adalah Sebesar: Rp. %lld,00\n", totalSum(saldo, nasabahCount) + totalSum(deposit, nasabahCount));
    printf("||  ");
    system("pause");
    system("cls");

    menuAdmin();

}

int totalSum(float uang[], int count) {     // total uang dihitung secara recursive

    if (count <= 0 ) {

        return 0;

    }

    return (totalSum(uang, count-1) + uang[count-1]);

}