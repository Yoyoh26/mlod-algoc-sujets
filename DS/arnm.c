#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

// =============
// = Fonctions =
// =============

typedef struct {
	int index;
	int distance;
} Difference;

int* statistics(const char* chaine ) {
	int longueur = strlen(chaine);
    int a = 0, t = 0, c = 0, g = 0;

    for (int i = 0; i < longueur; i++) {
        char lettre = chaine[i];
        if (lettre == 'A') {
            a++;
        } else if (lettre == 'T') {
            t++;
        } else if (lettre == 'C') {
            c++;
        } else if (lettre == 'G') {
            g++;
        }
    }
    int* proportion = (int*)malloc(4 * sizeof(int));
    proportion[0] = (int)((a*100)/longueur);
    proportion[1] = (int)((t*100)/longueur);
    proportion[2] = (int)((c*100)/longueur);
    proportion[3] = (int)((g*100)/longueur);

    return proportion;
}



bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}


int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}


// ========
// = Main =
// ========

Difference* computeDifferenceBeetween(const char* s1, const char* s2) {
	int longueur = strlen(s1);
    Difference* tableau = (Difference*)malloc(longueur * sizeof(Difference));
    for (int i = 0; i < longueur; i++) {
        tableau[i].index = i;
        tableau[i].distance = distanceBetweenNucleotides(s1[i], s2[i]);
    }
    return tableau;

}

void printDifferences(const Difference* tableau, int longueur) {
    if (tableau == NULL) {
        printf("tableau vide \n");
        return;
    }
    for (int i = 0; i < longueur; i++) {
        printf("<%d,%d> ", tableau[i].index, tableau[i].distance);
    }
    printf("\n");
}

int main(void){
	//code_proteine_spike_pfizer
	//char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

    //printf("%s\n",code_proteine_spike_moderna);
	Difference* tableau=computeDifferenceBeetween(code_proteine_spike_pfizer,code_proteine_spike_moderna );
	 printDifferences(tableau, 359);

	 int* stat= statistics("AAGCTTTACA");
	 printf("%d %d %d %d",stat[0], stat[1],stat[2],stat[3] );

	 /*on pourrait definir un marqueur de fin de tableau comme <-1,0> 
	 afin de mettre une boucle while dans la fonction printDifference et de ne plus avoir besoin 
	 de la taille du tableau en paramètre 
	 
	 ou alors renvoyer en plus du tableau, sa taille dans la fonction computeDifferenceBeetween*/

	return EXIT_SUCCESS;
}

