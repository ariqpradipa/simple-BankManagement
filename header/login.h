// disini terdapat function login admin dan login nasabah

extern char usernameMasukNasabah[20];
extern char passMasukNasabah[20];
extern char rekeningMasukNasabah[20];

void loginAdmin() {

    char username[20], validUser[20];
    int pass, validPass, admin;

    printf("||======================||\n");
    printf("||      Login Admin     ||\n");
    printf("||======================||\n\n");

    strcpy(validUser, "admin");     // username yang benar
    validPass = 12345;              // password yang benar

    printf("#   username: ");
    scanf("%s", &username);
    printf("#   password: ");
    scanf("%d", &pass);

    if(strcmp(username, validUser) == 0 && pass == validPass) { // jika username dan password yang di iinput benar

        printf("\n||  Login Berhasil!\n");
        printf("||  ");
        system("pause");

        system("cls");
        fflush(stdin);

        menuAdmin();    // terdapat pada menu.h

    }
    else {  // jika username dan password yang di input salah

        printf("\n||  Username / Password anda salah!\n");
        printf("||  ");
        system("pause");
        fflush(stdin);
        system("cls");

        main(); // kembali ke awal

    }
}

void loginNasabah() {

    char stringNasabah[256];
    char username[20], pass[20];
    char *stripped, *str1, *str2, *str3;
    int login = 0;

    FILE *fileNasabah = fopen("data/nasabah.txt", "r");     // membuka file nasabah.txt dalam mode read

    printf("||==========================||\n");
    printf("||      Login Nasabah       ||\n");
    printf("||==========================||\n\n");

    printf("||  Username adalah nama depan\n");
    printf("#   username: ");
    scanf("%s", &username);
    printf("#   password: ");
    scanf("%s", &pass);

    while(fgets(stringNasabah, sizeof(stringNasabah), fileNasabah) != NULL) {   // loop text file line per line

        stripped = strtok(stringNasabah, "\n");
        str1 = strtok(stripped, " ");
        str2 = strtok(NULL, " ");
        str2 = strtok(NULL, " ");
        str3 = strtok(NULL, " ");

        if(strcmp(username, str1) == 0 && strcmp(pass, str2) == 0) {    // jika username dan pass yang di input sama dengan yang ada di file

            printf("\n||  Login Berhasil!\n");
            printf("||  ");
            system("pause");
            fflush(stdin);

            // set global variiable untuk mengetahui siapa nasabah yang login
            strcpy(usernameMasukNasabah, str1);
            strcpy(passMasukNasabah, str2);
            strcpy(rekeningMasukNasabah, str3);

            login = 1;
            break;

        }
    }

    fclose(fileNasabah);

    if(login == 1) {

        system("cls");

        menuNasabah();  // terdapat pada menu.h

    }
    else {

        printf("\n||  Username / Password yang dimasukkan salah!\n");
        printf("||  ");
        system("pause");
        system("cls");

        main();

    }
}