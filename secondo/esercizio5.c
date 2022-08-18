#include <stdio.h> 

#define bool int 

bool isMaiusc(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

int solve(FILE *file) {
    char ch;
    int maiusc_counter = 0;
    while (fread(&ch, 1, 1, file) > 0) {
        if (isMaiusc(ch)) {
            maiusc_counter++;
        }
    }
    return maiusc_counter;
}


int main() {
    FILE *f = fopen("text.txt", "r"); 
    if (f == NULL) {
        printf("Non ho potuto aprire il file in lettura"); 
    }
    int solution = solve(f);

    printf("%d\n", solution);

    fclose(f);
    return 0; 
}