#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void erase()
{
    FILE *f = fopen("baza_date", "w");
    fclose(f);
}

void encrypt(char password[])
{
    char encrypt[] = "&*jnkl(!.,)", output[280] = "";
    FILE *f = fopen("baza_date", "a");
    strcat(password, "!njdsj");
    int length_encrypt = strlen(encrypt), length_output = strlen(password), j = 0, temp;
    for(int i = 0; i < length_output; i++) {
        if(j == length_encrypt)
            j = 0;
        temp = (password[i] - '0') ^ (encrypt[j++] - '0');
        output[i] = temp + '0';
    }
    fprintf(f,"%d %s ",length_output - 6, output);
    fclose(f);
}

void add_password()
{
    char password[256], site[50];
    printf("Add password: ");
    scanf("%256s", password);
    encrypt(password);
    printf("What is the password for? ");
    scanf("%50s", site);
    FILE *f = fopen("baza_date", "r");
    fprintf(f, " - %s ", site);
    fclose(f);
}

void decrypt()
{
    char password[280] = "", encrypt[] = "&*jnkl(!.,)", output[280] = "", site[50], t[5];
    FILE *f = fopen("baza_date", "r");
    int length_encrypt = strlen(encrypt), length_output, j = 0, temp;
    while(fscanf(f,"%d %s %s %s", &length_output, password, t, site) == 2) {
        j = 0;
        for(int i = 0; i < length_output; i++) {
            if(j == length_encrypt)
            j = 0;
            temp = (password[i] - '0') ^ (encrypt[j++] - '0');
            output[i] = temp + '0';
        }
        for(int i = 0; i < length_output; i++)
        printf("%c", output[i]);
        printf(" - %s", site);
    }
    fclose(f);
}

void gen_password()
{
    srand(time(NULL));
    int min = 8, max = 16, length;
    length = rand() % (max - min + 1) + min;
    char password[20], site[50];
    for(int i = 0; i < length; i++)
        password[i] = '0' + rand() % 74;
    encrypt(password);
    printf("What is the password for? ");
    scanf("%50s", site);
    FILE *f = fopen("baza_date", "r");
    fprintf(f, " - %s ", site);
    fclose(f);
}

void menu()
{
    int s;
    printf("Choices :\n1.Enter password\n2.View passwords\n3.Erase data\n4.Generate password\n");
    scanf("%d", &s);
    switch(s)
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
    }
}

int main(void)
{
    char s[256], parola[256];
    printf("Enter password :");
    scanf("%256s", s);
    FILE *f = fopen("parola", "r");
    fscanf(f,"%256s", parola);
    fclose(f);
    if(strcmp(s,parola) == 0)
        menu();

    return 0;
}