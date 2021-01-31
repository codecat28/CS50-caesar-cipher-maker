#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    //declare variables
    int k = 0;
    int i;
    int n;
    int j;
    int p;
    string cipher_text = NULL;
    string plain_text;


    //checking if 2 arguments were passed, ./caesar and a key
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    //putting string length of key into n
    n = strlen(argv[1]);


    //confirm if argv[1] is a digit, i = start at first element, continue until last element, iterate one by one
    for (i = 0; i < n; i++)
    {
        if (! isdigit(argv[1][i])) //! means false, specify looking at argv[1], argv[i] means looking at current one
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //convert argv[1] from string to int
    k = atoi(argv[1]);

    //get some plain text
    plain_text = get_string("plaintext: ");


    //putting strlength of plain text into variable
    p = strlen(plain_text);


    //convert ascii to alphabetical index
    for (i = 0; i < p; i++)
    {
        if (isalpha(plain_text[i]))
        {
            if (islower(plain_text[i]))
            {
                plain_text[i] = ((((plain_text[i] - 'a') + k) % 26) + 'a');
            }
            else if (isupper(plain_text[i]))
            {
                plain_text[i] = ((((plain_text[i] - 'A') + k) % 26) + 'A');
            }
        }

        else
        {
            plain_text[i] = plain_text[i];
        }


    }


    cipher_text = plain_text;

    //print cipher text
    printf("ciphertext: %s\n", cipher_text);




}