#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool verify_argv(string s);
string get_text(void);

int main(int argc, string argv[])
{
    if (argc == 2) {

        if( !verify_argv(argv[1]) ) {
            printf("Use: ./caesar key\n");
            return 1;
        }

        int key = atoi(argv[1]);
        string plaintext = get_text();
        string ciphertext = plaintext;
        for(int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i])) {
                char base = isupper(plaintext[i]) ? 'A' : 'a';
                ciphertext[i] = (ciphertext[i] - base + key) % 26 + base;
            }
        }

        printf("ciphertext: %s\n", ciphertext);
        return 0;

    } else {
        printf("Invalid\n");
        return 1;
    }
}

bool verify_argv(string s)
{
    bool result = true;
    for(int i = 0, n = strlen(s); i < n; i++) {
        if( (s[i] < 48 || s[i] > 57) ) {
            result = false;
        }
    }
    return result;
}

string get_text(void)
{
    string t;
    do
    {
         t = get_string("plaintext: ");
	}
    while( strlen(t) <= 0 );
    return t;
}
