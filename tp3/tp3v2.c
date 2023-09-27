#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>


typedef struct {
    int year;
    char *name;
    char *research;
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
    for (int i = 0; i < numberOfWinners; i++) {
        int year;
        char nameBuffer[512];    
        char researchBuffer[512]; 
        char temp[512];          

        if (fgets(temp, sizeof(temp), file) != NULL &&
            sscanf(temp, "%d;%[^;];%[^\n]", &year, nameBuffer, researchBuffer) == 3) {

            winners[i].name = (char *)malloc((strlen(nameBuffer) + 1) * sizeof(char));
            if (winners[i].name == NULL) {
                perror("Erreur lors de l'allocation de mémoire");
                exit(EXIT_FAILURE);
            }

            winners[i].research = (char *)malloc((strlen(researchBuffer) + 1) * sizeof(char));
            if (winners[i].research == NULL) {
                perror("Erreur lors de l'allocation de mémoire");
                exit(EXIT_FAILURE);
            }

            strcpy(winners[i].name, nameBuffer);
            strcpy(winners[i].research, researchBuffer);

            winners[i].year = year;
        } else {
            perror("Erreur lors de la lecture du fichier");
            exit(EXIT_FAILURE);
        }
    }
}

void printWinners(FILE *file,  TuringWinner *winners, int numberOfWinners) {
    for (int i = 0; i < numberOfWinners; i++) {
        fprintf(file, "%d;%s;%s\n", winners[i].year, winners[i].name, winners[i].research);
    }
}

void infosAnnee(int year) {
    TuringWinner winners[57];
    FILE *inputFile = fopen("turingWinners.csv", "r");
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return;
    }
    readWinners(inputFile, winners, 57);
    fclose(inputFile);

    for (int i = 0; i < 57; i++) {
        if (winners[i].year == year) {
            printf("L'année %d, le(s) gagnant(s) ont été : %s\n", winners[i].year, winners[i].name);
            printf("Nature des travaux : %s\n", winners[i].research);
            return ; // Sortir de la boucle dès qu'une correspondance est trouvée
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

    TuringWinner* winners = (TuringWinner*)malloc(nb * sizeof(TuringWinner));
    if (winners == NULL) {
        perror("Erreur lors de l'allocation de mémoire");
        fclose(inputFile);
        return;
    }

    char ligne[1024]; 

    int index = 0;
    while (fgets(ligne, sizeof(ligne), inputFile) != NULL) {
        char nameBuffer[256];
        char researchBuffer[512];
        if (sscanf(ligne, "%d;%255[^;];%511[^\n]", &winners[index].year, nameBuffer, researchBuffer) == 3) {
            winners[index].name = strdup(nameBuffer);
            winners[index].research = strdup(researchBuffer);

            if (winners[index].name == NULL || winners[index].research == NULL) {
                perror("Erreur lors de l'allocation de mémoire");
                fclose(inputFile);
                free(winners);
                return;
            }

            index++;
        }
    }

    fclose(inputFile);

    qsort(winners, nb, sizeof(TuringWinner), compareTuringWinners);

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

    for (int i = 0; i < nb; i++) {
        free(winners[i].name);
        free(winners[i].research);
    }
    free(winners);
}

int main(int argc, char** argv) {
    char inputFilename[] = "turingWinners.csv";
    char outputFilename[] = "sortedWinners2473.csv";
    int infoYear = 0;
    int shouldSort = 0;

    for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
        strcpy(outputFilename, argv[i + 1]);

        if (i + 2 < argc) {
            strcpy(inputFilename, argv[i + 2]);
        }

        i += 2;
    }
}
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            strcpy(outputFilename, argv[i + 1]);
            if (i + 2 < argc) {
                strcpy(inputFilename, argv[i + 2]);
            }

            i += 2; 
        } else if (strcmp(argv[i], "--info") == 0 && i + 1 < argc) {
            infoYear = atoi(argv[i + 1]);
            i++; 
        } else if (strcmp(argv[i], "--sort") == 0) {
            shouldSort = 1;
            strcpy(outputFilename, argv[i + 1]);

        if (i + 2 < argc) {
            strcpy(inputFilename, argv[i + 2]);
        }

        i += 2;
        }
    }

    if (infoYear > 0) {
        infosAnnee(infoYear);
        return EXIT_SUCCESS;
    }

    if (shouldSort) {
        sortTuringWinnersByYear(inputFilename, outputFilename);
        return EXIT_SUCCESS;
    }
    
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
    return 0;
    */

    //infosAnnee(1976);
    //sortTuringWinnersByYear(inputFilename,outputFilename);
    return EXIT_SUCCESS;
}