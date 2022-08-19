#include <stdio.h> 

void fun() {
    printf("Hello World\n");
}

int main() {
    void (*fun_ptr)() = &fun;
    fun_ptr();
}