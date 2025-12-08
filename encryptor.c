#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// ANSI color escape codes
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

char encrypt_char(char c, char key[26])
{
    if (isupper(c))
        return toupper(key[c - 'A']);
    if (islower(c))
        return key[c - 'a'];
    return c;
}

char decrypt_char(char c, char key[26])
{
    int index = -1;
    for (int i = 0; i < 26; i++)
        if (tolower(c) == key[i])
            index = i;

    if (index == -1)
        return c;

    if (isupper(c))
        return 'A' + index;
    return 'a' + index;
}

void generate_key(char key[26])
{
    char alphabet[26];
    for (int i = 0; i < 26; i++)
        alphabet[i] = 'a' + i;

    for (int i = 25; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char tmp = alphabet[i];
        alphabet[i] = alphabet[j];
        alphabet[j] = tmp;
    }

    for (int i = 0; i < 26; i++)
        key[i] = alphabet[i];
}

void print_key(char key[26])
{
    printf(CYAN "\nCurrent key:\n" RESET);
    for (int i = 0; i < 26; i++)
        printf("%c ", key[i]);
    printf("\n");
}

int get_int_input(const char *prompt)
{
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    getchar(); // remove leftover newline
    return value;
}

void get_string_input(char *buffer, int size, const char *prompt)
{
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main(void)
{
    srand(time(NULL));
    char key[26];
    generate_key(key);

    while (1)
    {
        printf(BLUE "\n=========================\n" RESET);
        printf(GREEN "   Encryption Program\n" RESET);
        printf(BLUE "=========================\n\n" RESET);

        printf(YELLOW "1." RESET " Encrypt text\n");
        printf(YELLOW "2." RESET " Decrypt text\n");
        printf(YELLOW "3." RESET " Show key\n");
        printf(YELLOW "4." RESET " Generate NEW key\n");
        printf(YELLOW "5." RESET " Exit\n\n");

        int choice = get_int_input("Select option: ");

        if (choice == 1)
        {
            char text[1024];
            get_string_input(text, sizeof(text), GREEN "\nPlaintext: " RESET);

            printf(MAGENTA "Encrypted: " RESET);
            for (int i = 0; i < strlen(text); i++)
                printf("%c", encrypt_char(text[i], key));
            printf("\n");
        }
        else if (choice == 2)
        {
            char text[1024];
            get_string_input(text, sizeof(text), RED "\nCiphertext: " RESET);

            printf(MAGENTA "Decrypted: " RESET);
            for (int i = 0; i < strlen(text); i++)
                printf("%c", decrypt_char(text[i], key));
            printf("\n");
        }
        else if (choice == 3)
        {
            print_key(key);
        }
        else if (choice == 4)
        {
            generate_key(key);
            printf(GREEN "\nNew key generated!\n" RESET);
            print_key(key);
        }
        else if (choice == 5)
        {
            printf(CYAN "\nGoodbye.\n" RESET);
            return 0;
        }
        else
        {
            printf(RED "Invalid choice.\n" RESET);
        }
    }
}
