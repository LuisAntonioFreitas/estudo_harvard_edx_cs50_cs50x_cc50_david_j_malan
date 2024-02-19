#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string get_text(void);

int main(void)
{
    string text = get_text();

    float letter = 0;
    float word = 0;
    float phrase = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if( (text[i] >= 65 && text[i] <= 90) ||
            (text[i] >= 97 && text[i] <= 122) ) {
            letter++;
        } else if( text[i] == ' ' ) {
            word++;
        } else if( text[i] == '.' || text[i] == '!' || text[i] == '?' ) {
            phrase++;
        }
    }
    word++;
    //printf("letter: %f | word: %f | phrase: %f\n", letter, word, phrase);

    // indice Coleman-Liau
    float letter100 = (100 / word) * letter;
    float word100 = (100 / word) * phrase;
    float index = 0.0588 * letter100 - 0.296 * word100 - 15.8;
    int indexRound = round(index);
    //printf("letter100: %f | word100: %f | index: %f | indexfinaly: %i\n", letter100, word100, index, indexRound);

    if( indexRound < 1 ) {
        printf("Before Grade 1\n");
    } else if( indexRound >= 16 ) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", indexRound);
    }
}

string get_text(void)
{
    string t;
    do
    {
         t = get_string("Text: ");
	}
    while( strlen(t) <= 0 );
    return t;
}
