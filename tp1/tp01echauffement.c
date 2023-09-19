int estNombreParfait(int nombre) {
    int sommeDiviseurs = 0;
    
    // Parcourir les diviseurs de 1 à nombre - 1
    for (int i = 1; i < nombre; i++) {
        if (nombre % i == 0) {
            sommeDiviseurs += i;
        }
    }
    
    // Vérifier si la somme des diviseurs est égale au nombre
    if (sommeDiviseurs == nombre) {
        return 1; // Le nombre est parfait
    } else {
        return 0; // Le nombre n'est pas parfait
    }
}

int question2() {
    int N;

    printf("Entrez un entier positif N : ");
    scanf("%d", &N);

    printf("Nombres parfaits entre 0 et %d : \n", N);

    for (int i = 1; i <= N; i++) {
        if (estNombreParfait(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

typedef unsigned long long int ulli;

// Fonction récursive pour calculer la factorielle
ulli calculerFactorielle(ulli n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * calculerFactorielle(n - 1);
    }
}

int question3() {
    ulli nombre;
    printf("Entrez un nombre positif : ");
    scanf("%llu", &nombre);

    if (nombre < 0) {
        printf("La factorielle n'est pas définie pour les nombres négatifs.\n");
    } else {
        ulli resultat = calculerFactorielle(nombre);
        printf("%llu! = %llu\n", nombre, resultat);
    }

    return 0;
}

int question3_2() {
    int i;
    for (i = 1; i <= 15; i++) {
        ulli resultat = calculerFactorielle(i);
        printf("%d! = %llu\n", i, resultat);
    }

    return 0;
}


int main() {
   question2();
}



