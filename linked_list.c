#include <stdio.h> 
#include <stdlib.h>

struct list {
    int data; 
    struct list *next; 
};

struct list *newlist() {
    struct list *new = (struct list *) malloc(sizeof(struct list));
    new->data = 0;
    new->next = NULL; 
    return new;
}

struct list *append(struct list *this, int what) {
    struct list *new = (struct list *) malloc(sizeof(struct list));
    new->data = what; 
    new->next = this; 
}

void print(struct list *this) {
    while (this != NULL) {
        printf("%d ", this->data);
        this = this->next; 
    }
}

int main() {
    struct hello *my_linked_list = newlist(); 
    my_linked_list = append(my_linked_list, 4); 
    print(my_linked_list);
}