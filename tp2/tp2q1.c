
void echangeContenu(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    printf("Avant l'echange : x = %d, y = %d\n", x, y);

    echangeContenu(&x, &y);

    printf("Apres l'echange : x = %d, y = %d\n", x, y);

    return 0;
}
