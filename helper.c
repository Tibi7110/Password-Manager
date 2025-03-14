#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"
#include <stdbool.h> // Am adaugat pentru a folosi bool

void clean_buffer()
{
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

#ifdef _WIN32
void clean_console()
{
    system("cls");
}
#endif
#ifdef __linux__
void clean_console()
{
    system("clear");
}
#endif

void add_password()
{
    // system("cls"); // curata consola
    clean_console();
    char password[256], site[50];
    printf("Enter the password: ");
    scanf("%256s", password);
    encrypt(password);
    printf("What is the password for? - ");
    scanf("%50s", site);
    FILE *f = fopen("baza_date", "a");
    fprintf(f, " - %s ", site);
    fclose(f);
    printf("Password added successfully!\n");
}

void encrypt(char password[])
{
    char encrypt[] = "&*jnkl(!.,)", output[280] = "";
    FILE *f = fopen("baza_date", "a");
    strcat(password, "!njdsj");
    int length_encrypt = strlen(encrypt), length_output = strlen(password), j = 0, temp;
    for (int i = 0; i < length_output; i++)
    {
        if (j == length_encrypt)
            j = 0;
        temp = (password[i] - '0') ^ (encrypt[j++] - '0');
        output[i] = temp + '0';
    }
    fprintf(f, "%d %s ", length_output - 6, output);
    fclose(f);
}

void erase()
{
    // system("cls"); // curata consola
    void clean_console();
    FILE *f = fopen("baza_date", "w");
    fclose(f);
    printf("Data has been erased successfully!\n");
}

void decrypt()
{
    // system("cls"); // curata consola
    void clean_console();
    printf("Here are your passwords (password - site): \n");
    char password[280] = "", encrypt[] = "&*jnkl(!.,)", output[280] = "", site[50], t[2];
    FILE *f = fopen("baza_date", "r");
    int length_encrypt = strlen(encrypt), length_output, j = 0, temp, passwordIndex = 1;
    while (fscanf(f, "%d %s", &length_output, password) == 2)
    {
        j = 0;
        for (int i = 0; i < length_output; i++)
        {
            if (j == length_encrypt)
                j = 0;
            temp = (password[i] - '0') ^ (encrypt[j++] - '0');
            output[i] = temp + '0';
        }
        printf("%d. ", passwordIndex++);
        for (int i = 0; i < length_output; i++)
            printf("%c", output[i]);
        fscanf(f, "%s %s", t, site);
        printf(" - %s\n", site);
    }
    fclose(f);
}

void gen_password()
{
    // system("cls"); // curata consola
    void clean_console();
    srand(time(NULL));
    int min = 8, max = 16, length;
    length = rand() % (max - min + 1) + min;
    char password[20], site[50];
    for (int i = 0; i < length; i++)
        password[i] = '0' + rand() % 74;
    encrypt(password);
    printf("What is the password for? - ");
    scanf("%50s", site);
    FILE *f = fopen("baza_date", "r");
    fprintf(f, " - %s ", site);
    fclose(f);
    printf("Password added successfully!\n");
}

// functie care afiseaza meniul dupa ce te-ai autentificat
void menu()
{
    // system("cls");
    void clean_console();
    int option;
    bool loop = true;
    while (loop)
    {
        printf("### You have successfully authenticated ###\n1. Add a new password\n2. View passwords\n3. Erase data\n4. Generate password\n5. Exit\n####################\nChoose an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            add_password();
            break;
        case 2:
            decrypt();
            break;
        case 3:
            erase();
            break;
        case 4:
            gen_password();
            break;
        case 5:
            printf("Goodbye!\nProgram has exited successfully!\n");
            loop = false;
            return;
        default:
            printf("Invalid option! Please try again!\n");
            break;
        }
        if (option != 5)
        {
            // system("pause"); // asteapta apasarea unei taste random pentru a continua
            // system("cls");   // curata consola
            void clean_console();
        }
    }
}