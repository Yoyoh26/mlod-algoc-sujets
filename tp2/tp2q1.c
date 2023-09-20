#include <stdio.h>

void echangeContenu(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 20;

    printf("Avant l'echange : a = %d, b = %d\n", a, b);

    echangeContenu(&a, &b);

    printf("Apres l'echange : a = %d, b = %d\n", a, b);

    return 0;
}
