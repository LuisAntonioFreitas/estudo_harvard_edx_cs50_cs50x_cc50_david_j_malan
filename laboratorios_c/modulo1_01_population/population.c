#include <cs50.h>
#include <stdio.h>

int get_valid_number(string message, int min);

int main(void)
{
    // TODO: Solicite o valor inicial ao usuário
    int initial = get_valid_number("Start size: ", 9);

    // TODO: Solicite o valor final ao usuário
    int finaly = get_valid_number("End size: ", initial);

    // TODO: Calcule o número de anos até o limite
    int calc = 0;
        if ( initial != finaly ) {
        do {
            initial = initial + ( initial / 3 ) - ( initial / 4 );
            calc++;
        }
        while( initial < finaly );
    }

    // TODO: Imprima o número de anos
    printf("Years: %i \n", calc);
}

int get_valid_number(string message, int min) {
    int n;
    do {
         n = get_int("%s", message);
	}
    while( n < min );
    return n;
}
