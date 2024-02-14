#include <cs50.h>
#include <stdio.h>

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
          for(int j = 1; j <= i; j++)
          {
               printf("#");
          }
          printf("\n");
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
