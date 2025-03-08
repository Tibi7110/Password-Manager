#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add_password()
{
    unsigned char password[256] = "", encrypt[] = "&*jnkl(!.,)", output[280] = "";
    printf("\nAdd password:");
    scanf("%256s", password);
    //printf("\nWhat is the password for?:");
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

void decrypt()
{
    char password[280] = "", encrypt[] = "&*jnkl(!.,)", output[280] = "";
    FILE *f = fopen("baza_date", "r");
    int length_encrypt = strlen(encrypt), length_output, j = 0, temp;
    while(fscanf(f,"%d %s", &length_output, password) == 2) {
        j = 0;
        for(int i = 0; i < length_output; i++) {
            if(j == length_encrypt)
            j = 0;
            temp = (password[i] - '0') ^ (encrypt[j++] - '0');
            output[i] = temp + '0';
        }
        for(int i = 0; i < length_output; i++)
        printf("%c", output[i]);
        printf("\n");
    }
    fclose(f);
}

void menu()
{
    int s;
    printf("\nChoice :\n1.Enter password\n2.View passwords\n");
    scanf("%d", &s);
    if(s == 1)
        add_password();
    else if (s == 2)
    {
        decrypt();
    }
}


int main(void)
{
    char s[256], parola[256];
   // printf("Enter password :");
   // scanf("%256s", s);
   // FILE *f = fopen("parola", "r");
   // fscanf(f,"%256s", parola);
   // fclose(f);
   // if(strcmp(s,parola) == 0)
        menu();

    return 0;
}