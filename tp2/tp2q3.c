#include <stdio.h>

//3a
 typedef enum   {
    JANVIER,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
} Mois;

 typedef struct   {
    unsigned short jour;
    Mois mois;
    unsigned short annee;
}  Date ;

//3b
int main() {
    Date d;
    initialiseDate(&d);
    afficheDate(d);    
    
    /*Date d;
    d=creerDateParCopie();
    afficheDate(&d);*/

}

void initialiseDate(Date *date) {
    printf("Entrez le jour, le mois et l'année (séparés par des espaces) : ");
    scanf("%d %d %d", &(date->jour), (int *)&(date->mois), &(date->annee));
}

void afficheDate( Date date) {
    printf("%d/%d/%d\n", date.jour, date.mois, date.annee);
}

//3c

Date creerDateParCopie() {
    Date d;
    initialiseDate(&d);
    return d;
} 

Date* newDate() {
    Date* d = (Date*)malloc(sizeof(Date));
    initialiseDate(&d);
    return d;
}
