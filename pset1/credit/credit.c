#include <cs50.h>
#include <stdio.h>
#include <string.h>

long get_numercard_long(void);
int verify_numbers(long n);
int verify_visa(long n);
int verify_mastercard(long n);
int verify_amex(long n);

int main(void)
{
    long n = get_numercard_long();
    if(verify_numbers(n) == 0) {
        printf("INVALID\n");
    } else {
        if(verify_visa(n) == 1) {
            printf("VISA\n");
        } else if(verify_mastercard(n) == 1) {
            printf("MASTERCARD\n");
        } else if(verify_amex(n) == 1) {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    }
}

long get_numercard_long(void)
{
    long n;
    do
    {
         n = get_long("Number: ");
	}
    while( n <= 0 );
    return n;
}

int verify_numbers(long n)
{
    char cc[20];
    char result[20] = "";
    char finaly[20];
    int stage1 = 0;
    int stage2 = 0;
    int verify = 0;
    sprintf(cc, "%ld", n);
    //printf("%s \n", cc);

    // identifica os numeros que devem ser
    // multiplicados por 2
    for(int i = ( strlen(cc) ); i >= 0; i -= 2)
    {
        if(cc[i] != '\0' && (cc[i] - '0' >= 0 && cc[i] - '0' <= 9))
        {
            int digit = cc[i] - '0';
            digit = digit * 2;
            sprintf(result + strlen(result), "%d", digit);
            //printf("%c | %i \n", cc[i], digit);
        }
    }
    //printf(": %s : \n", result);

    // soma os numeros individualmente
    // resultado do multiplicacao
    for(int i = 0; result[i] != '\0'; i++)
    {
        int digit = result[i] - '0';
        stage1 = stage1 + digit;
    }
    //printf("= %i \n", stage1);

    // identifica os numeros que não foram
    // multiplicados por 2
    for(int i = ( strlen(cc) + 1 ); i >= 0; i -= 2)
    {
        if(cc[i] != '\0' && (cc[i] - '0' >= 0 && cc[i] - '0' <= 9))
        {
            int digit = cc[i] - '0';
            stage2 = stage2 + digit;
            //printf("%c | %i \n", cc[i], digit);
        }
    }
    //printf("= %i \n", stage2);

    verify = stage1 + stage2;
    //printf("= %i + %i = %i \n", stage1, stage2, verify);

    sprintf(finaly, "%d", verify);
    if( finaly[ strlen(finaly) -1 ] - '0' == 0) {
        return 1;
    } else {
        return 0;
    }
}

int verify_visa(long n)
{
    // Visa de 13 e 16 digitos
    // Inicia com 4
    char cc[20];
    int verify = 0;
    sprintf(cc, "%ld", n);
    if(strlen(cc) >= 13 && strlen(cc) <= 16) {
        if(cc[0] - '0' == 4) {
            verify = 1;
        }
    }
    return verify;
}

int verify_mastercard(long n)
{
    // Mastercard 16 digitos
    // Inicia com 51, 52, 53, 54 ou 55
    char cc[20];
    int verify = 0;
    sprintf(cc, "%ld", n);
    if(strlen(cc) == 16) {
        if(cc[0] - '0' == 5 && (cc[1] - '0' >= 1 || cc[1] - '0' <= 5)) {
            verify = 1;
        }
    }
    return verify;
}

int verify_amex(long n)
{
    // Amex 15 digitos
    // Inicia com 34 ou 37
    char cc[20];
    int verify = 0;
    sprintf(cc, "%ld", n);
    if(strlen(cc) == 15) {
        if(cc[0] - '0' == 3 && (cc[1] - '0' == 4 || cc[1] - '0' == 7)) {
            verify = 1;
        }
    }
    return verify;
}
