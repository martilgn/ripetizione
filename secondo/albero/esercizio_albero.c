#include <stdio.h>
#include "./albero_source.c"

// L'albero è questo:
//              1
//           /     \
//          2       3
//        /   \   /   \
//       4     5 6     7

// Ti chiedo di provare a predire cosa produce questo programma senza eseguirlo
// con input quell'albero, per la visita di tipo
// 1. prefissa
// 2. infissa
// 3. postfissa
int main() {
    struct tree *root = build_tree();
    print_prefisso(root);
    printf("\n");
    print_infisso(root);
    printf("\n");
    print_postfisso(root);
    printf("\n");
}