#include <cs50.h>
#include <stdio.h>

void print_block(int qtd);
int get_beetwen_int(int initial, int finaly);

int main(void)
{
     int h = get_beetwen_int(1, 8);

     for(int i = 1; i <= h; i++)
     {
          for(int e = 1; e <= (h - i); e++)
          {
               printf(" ");
          }
          print_block(i);
          printf("  ");
          print_block(i);
          printf("\n");
     }
}

void print_block(int qtd)
{
    for(int j = 1; j <= qtd; j++)
    {
        printf("#");
    }
}

int get_beetwen_int(int initial, int finaly)
{
     int n;
     do
     {
          n = get_int("Heigth (%i-%i): ", initial, finaly);
	}
     while( n < initial || n > finaly );
     return n;
}
