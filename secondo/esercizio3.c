#include <stdio.h> 
#include <stdlib.h>

struct lista {
    int data; 
    struct lista *next;
}; 

typedef struct lista Node;

int conta_nodi_pari(Node *node) {
    if (node == NULL) {
        return 0;
    }

    if (node->data % 2 == 0) {
        return 1 + conta_nodi_pari(node->next);
    } else {
        return conta_nodi_pari(node->next);
    }
}

// ritorna la testa del nuovo elemento
Node *elimina_elemento(Node *node, int elemento) {
    if (node == NULL) {
        return NULL;
    }

    if (node->data == elemento) {
        Node *node_next = node->next;
        free(node); 
        return elimina_elemento(node_next, elemento); 
    } else {
        // node->next = 
        // punta a un nodo eliminato?
        node->next = elimina_elemento(node->next, elemento);
        return node; 
    }
}
// stack 

// printa la lista
void print_lista(Node *node) {
    if (node == NULL) {
        printf("\n");
        return;
    }
    print_lista(node->next);
    printf("%d ", node->data);
}

// visita infissa
// visita prefissa
// visita postfissa
// print(Albero *a) {
//     print(a->left); 
//     printf("%d ", a->data);
//     print(a->right);
// }

// crea lista
Node *crea_lista(int n) {
    if (n == 0) {
        return NULL;
    }
    Node *node = malloc(sizeof(Node));
    node->data = n;
    node->next = crea_lista(n-1);
    return node;
}

// delete lista 
void delete_lista(Node *node) {
    if (node == NULL) {
        return;
    }
    delete_lista(node->next);
    free(node);
}

int main() {
    Node * prova = crea_lista(10); 
    print_lista(prova); 

    prova = elimina_elemento(prova, 5); 
    print_lista(prova); 
    delete_lista(prova);
}