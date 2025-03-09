#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "helper.h"

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