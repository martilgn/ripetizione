#include <stdio.h> 
#include <stdlib.h>

int somma(const char *str) {
    int sum = 0;
    while (*str != '\0') {
        sum += *str;
        str++;
    }
    return sum;
}


    // f1 
    // parola1 parola2 
    // f2
    // somma1 somma2 
int fun(FILE *f1, FILE *f2) {
    char buffer[1000];
    char buffer2[1000];

    // se sono in numero differente, ritornare -1 
    // se la somma non corrisponde ritornare 0 
    // se invece tutto apposto ritornare il numero di parole letti 
    
    int primo = fscanf(f1, "%s", buffer);
    int secondo = fscanf(f2, "%s", buffer2);
    int parole_lette = 1; 
    while ((primo != EOF) && (secondo != EOF)) {

        int isecondo = atoi(secondo); 
        if (somma(primo) != isecondo) {
            return 0; 
        }

        primo = fscanf(f1, "%s", buffer);
        secondo = fscanf(f2, "%s", buffer2);
        parole_lette += 1;
    }

    //  segno -> ||
    // 1 || 1 -> 1
    // 1 || 0 -> 1
    // 0 || 1 -> 1
    // 0 || 0 -> 0
    // a | b

    if ((primo != EOF || secondo != EOF)) {
        return -1;
    }
    return parole_lette;
}

int main() {
    const char *str = "hello"; 

    int s = somma(str);
    printf("%d\n", s);

    FILE *f = fopen("./text.txt", "r");
    if (f == NULL) {
        printf("exited");
        exit(1);
    }
    fun(f, f);
    
    fclose(f);
    return 0; 
}