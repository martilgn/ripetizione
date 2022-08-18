#include <stdio.h> 
#include <stdlib.h> 

void solve(FILE *file) {
    char ch;
    int maiusc_counter = 0;
    int numero_letti = 0;
    int somma_cumulata = 0;

    FILE *f = fopen("output.txt", "w"); 
    if (f == NULL) {
        printf("Non ho potuto aprire il file in scrittura"); 
    }

    while (fread(&ch, 1, 1, file) > 0) {
        int corrente = atoi(&ch);  // assumo che siano caratteri
        numero_letti++; 
        somma_cumulata += corrente; 
        printf("Questo è il %d numero letto, il suo valore è %d e la somma dei numeri letti fino a questo punto è %d\n", numero_letti, corrente, somma_cumulata);

        fprintf(f, "%d", somma_cumulata);
    }
}


int main() {
    
    FILE *f = fopen("text2.txt", "r"); 
    if (f == NULL) {
        printf("Non ho potuto aprire il file in lettura"); 
    }
    solve(f);
}