#include <stdio.h> 
#include <stdlib.h>

// TODO questa funzione è buggata
// funziona solo per int da 0 a 9
char intToChar(int ch) {
    // ragne giusto checks
    // int 1,2,34,... 9
    // 0x32 '0'
    // 0x33 '1'
    // 0x34 '2'
    // 0xXX '9'
    return (char) (ch + '0'); 
}

FILE *solve(FILE *file) {
    // @returns puntatore a file aperto sul momento 
    // printa il numero di caratteri nel file 

    FILE *toWrite = fopen("output.txt", "w");
    if (toWrite == NULL) {
        printf("non ho potuto aprire in scrittura");
        exit(1); 
    }

    int count_chars = 0;
    int count_spaces = 0;
    char ch;
    while (fread(&ch, 1, 1, file) > 0) {
        if (ch == ' ') {
            char ch_count = intToChar(count_chars);
            fwrite(&ch_count, 1, 1, toWrite);
            count_chars = 0;
            count_spaces += 1;
        } else {
            count_chars++;
        }
    }

    if (count_chars != 0) {
        char ch_count = intToChar(count_chars);
        fwrite(&ch_count, 1, 1, toWrite); 
        count_spaces += 1; 
    }

    char word_count = intToChar(count_spaces);
    fwrite(&word_count, 1, 1, toWrite); 
    return toWrite;
}


int main() {
    FILE *f = fopen("text.txt", "r"); 
    if (f == NULL) {
        printf("Non ho potuto aprire il file in lettura"); 
    }
    FILE *opened = solve(f);

    fclose(f);
    fclose(opened); 
    return 0; 
}