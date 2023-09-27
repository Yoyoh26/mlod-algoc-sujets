#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


typedef struct {
    int year;
    char name[256];
    char research[512];
} TuringWinner ;

/*
// Ouvrir le fichier d'entrée en mode lecture
FILE *inputFile = fopen(filename, "r");
if (inputFile == NULL) {
    perror("Erreur lors de l'ouverture du fichier d'entrée");
    return EXIT_FAILURE;
}

// Ouvrir le fichier de sortie en mode écriture
FILE *outputFile = fopen(outputFilename, "w");
if (outputFile == NULL) {
    perror("Erreur lors de l'ouverture du fichier de sortie");
    return EXIT_FAILURE;
}

fclose(inputFile);
fclose(outputFile);
*/

int numberOfWinners(FILE *file) {
    int count = 0;
    int c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

void readWinners(FILE *file, TuringWinner *winners, int numberOfWinners) {
    char line[1024]; 
    for (int i = 0; i < numberOfWinners; i++) {
        if (fgets(line, sizeof(line), file) != NULL) {
            sscanf(line, "%d;%[^;];%[^\n]", &winners[i].year, winners[i].name, winners[i].research);
        }
    }
}

void printWinners(FILE *file,  TuringWinner *winners, int numberOfWinners) {
    for (int i = 0; i < numberOfWinners; i++) {
        fprintf(file, "%d;%s;%s\n", winners[i].year, winners[i].name, winners[i].research);
    }
}




int main(int argc, char** argv) {
    char inputFilename[] = "turingWinners.csv";
    char outputFilename[] = "sortedWinners222.csv";

    /*
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }
    
    int nombre = numberOfWinners(inputFile);
    fclose(inputFile);
    TuringWinner winners[nombre];
    
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }
    readWinners(inputFile, winners, nombre);
    fclose(inputFile);
    
    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        return 1;
    }
    printWinners(outputFile, winners, nombre);
    fclose(outputFile);
    return 0;*/

    //infosAnnee(1976);
    sortTuringWinnersByYear(inputFilename,outputFilename);
}


void infosAnnee(int year) {
    TuringWinner winners[57];
    FILE *inputFile = fopen("turingWinners.csv", "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }
    readWinners(inputFile, winners, 57);
    fclose(inputFile);

    for (int i = 0; i < 57; i++) {
        if (winners[i].year == year) {
            printf("L'année %d, le(s) gagnant(s) ont été : %s\n", winners[i].year, winners[i].name);
            printf("Nature des travaux : %s\n", winners[i].research);
            return; // Sortir de la boucle dès qu'une correspondance est trouvée
        }
    }
    printf("Aucune information trouvée pour l'année %d\n", year);
}




int compareTuringWinners(const void* a, const void* b) {
    // Compare les années pour trier par ordre croissant
    return ((( TuringWinner*)a)->year - (( TuringWinner*)b)->year);
}

void sortTuringWinnersByYear(const char* inputFilename, const char* outputFilename) {
    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return;
    }

    int nb = numberOfWinners(inputFile);

    rewind(inputFile);

    TuringWinner* winners = ( TuringWinner*)malloc(nb * sizeof(TuringWinner));
    if (winners == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        fclose(inputFile);
        return;
    }

    char ligne[512]; 

    int index = 0;
    while (fgets(ligne, sizeof(ligne), inputFile) != NULL) {
        if (sscanf(ligne, "%d;%[^;];%[^\n]", &winners[index].year, winners[index].name, winners[index].research) == 3) {
            index++;
        }
    }

    fclose(inputFile);

    qsort(winners, nb, sizeof( TuringWinner), compareTuringWinners);

    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        free(winners); 
        return;
    }

    for (int i = 0; i < nb; i++) {
        fprintf(outputFile, "%d;%s;%s\n", winners[i].year, winners[i].name, winners[i].research);
    }

    fclose(outputFile);
    free(winners); 
}




