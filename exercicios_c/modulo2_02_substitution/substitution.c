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
            printf("Key must contain 26 characters\n");
            return 1;
        }

        string key = argv[1];
        string plaintext = get_text();
        string ciphertext = plaintext;
        for(int i = 0, n = strlen(plaintext); i < n; i++)
        {
            if (isalpha(plaintext[i])) {
                char base = isupper(plaintext[i]) ? 'A' : 'a';
                ciphertext[i] = isupper(ciphertext[i])
                                ? toupper(key[ciphertext[i] - base])
                                : tolower(key[ciphertext[i] - base]);
            }
        }

        printf("ciphertext: %s\n", ciphertext);
        return 0;

    } else {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}

bool verify_argv(string s)
{
    bool result = true;
    int frequency[26] = {0};
    if( strlen(s) == 26 ) {
        for(int i = 0, n = strlen(s); i < n; i++) {
            if( (s[i] < 65 || s[i] > 90) &&
                (s[i] < 97 || s[i] > 122) ) {
                result = false;
            } else {
                if (frequency[s[i] - (isupper(s[i]) ? 'A' : 'a')] == 1) {
                    return false;
                } else {
                    frequency[s[i] - (isupper(s[i]) ? 'A' : 'a')] = 1;
                }
            }
        }
    } else {
        result = false;
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
