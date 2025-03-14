#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "helper.c" // Am modificat: am pus "helper.c" in loc de "helper.h" (nu imi compila cu .h)

// functie care afiseaza meniul principal
void uiMenu()
{
    bool loop = true;
    int numberOfTries = 3; // numarul de incercari pentru a introduce parola
    while (loop)
    {
        printf("### Welcome to the password manager! ###\nSelect an option:\n1. Enter password to log in\n2. Exit\n####################\nChoose an option: ");
        int option;
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            char s[256], parola[256];
            printf("Enter password: ");
            scanf("%256s", s);
            FILE *f = fopen("parola", "r");
            fscanf(f, "%256s", parola);
            fclose(f);
            if (strcmp(s, parola) == 0)
            {
                menu();
                return;
            }
            else
            {
                numberOfTries--;
                if (!numberOfTries)
                {
                    printf("You have exceeded the number of tries! Goodbye!\n");
                    loop = false;
                }
            }
            break;
        }
        case 2:
        {
            printf("Goodbye!\nProgram has exited successfully!\n");
            loop = false;
            break;
        }
        default:
        {
            printf("Invalid option! Please try again!\n");
            break;
        }
        }
        if (option != 2)
        {
            // system("pause"); // asteapta apasarea unei taste random pentru a continua
            clean_console();   // curata consola
        }
    }
}

int main(void)
{
    uiMenu();
    return 0;
}