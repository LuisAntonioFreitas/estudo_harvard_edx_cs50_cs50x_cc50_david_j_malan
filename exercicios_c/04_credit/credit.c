#include <cs50.h>
#include <stdio.h>
#include <string.h>

long get_numercard_long(void);

int main(void)
{
    long n = get_numercard_long();
    char cc[20];
    sprintf(cc, "%ld", n);

    printf("%s \n", cc);

    size_t len = strlen(cc);
    for(int i = (len - 1); i >= 0; i -= 2)
    {
        if( i != (len - 1) )
        {
            printf("%c \n", cc[i]);
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
