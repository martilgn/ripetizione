#include <stdio.h>
#include <stdlib.h>
// build a binary tree
struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *new_tree(int data) {
    struct tree *new = (struct tree *) malloc(sizeof(struct tree));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct tree *insert_left(struct tree *this, int data) {
    this->left = new_tree(data);
    return this->left;
}

struct tree *insert_right(struct tree *this, int data) {
    this->right = new_tree(data);
    return this->right;
}

void print_prefisso(struct tree *this) {
    if (this == NULL) {
        return;
    }
    printf("%d ", this->data);
    print_prefisso(this->left);
    print_prefisso(this->right);
}

void print_infisso(struct tree *this) {
    if (this == NULL) {
        return;
    }
    print_infisso(this->left);
    printf("%d ", this->data);
    print_infisso(this->right);
}

void print_postfisso(struct tree *this) {
    if (this == NULL) {
        return;
    }
    print_postfisso(this->left);
    print_postfisso(this->right);
    printf("%d ", this->data);
}

// build a perfectly bilanced 7 element tree
struct tree *build_tree() {
    struct tree *root = new_tree(1);
    insert_left(root, 2);
    insert_right(root, 3);
    insert_left(root->left, 4);
    insert_right(root->left, 5);
    insert_left(root->right, 6);
    insert_right(root->right, 7);
    return root;
}
