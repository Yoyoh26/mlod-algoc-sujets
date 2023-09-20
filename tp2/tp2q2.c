#include <stdint.h>
#include <stdlib.h>

#define SIZE 5

int main(void) {
    int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];

    matrix_mult(matriceResultat,matrice1,matrice2);
    matrix_print(matriceResultat);

    return EXIT_SUCCESS;
}

void matrix_mult(int64_t result[][SIZE], int64_t mat1[][SIZE], int64_t mat2[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;  // Initialise l'élément de résultat à 0
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrix_print(int64_t mat[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%lld ", mat[i][j]);
        }
        printf("\n");
    }
}


//5b fonction matrix_mult utilisable seulement pour matrice taille 5, 
//on pourrait prendre la taille comme parametre

//5c
void matrix_mult2(int64_t result[][SIZE], int64_t mat1[][SIZE], int64_t mat2[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;  
            for (int k = 0; k < size; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}