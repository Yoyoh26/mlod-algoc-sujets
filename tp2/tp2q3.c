#include <stdio.h>

//3a
enum Mois {
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
};

struct Date {
    int jour;
    enum Mois mois;
    int annee;
};

//3b
int main1() {
    struct Date d;
    initialiseDate(&d);
    afficheDate(&d);
}

void initialiseDate(struct Date *date) {
    printf("Entrez le jour, le mois et l'année (séparés par des espaces) : ");
    scanf("%d %d %d", &date->jour, &date->mois, &date->annee);
}

void afficheDate(struct Date date) {
    printf("%d/%d/%d\n", date.jour, date.mois, date.annee);
}

//3c

int main() {
    struct Date d;
    d=creerDateParCopie();
    afficheDate(&d);
}
void creerDateParCopie() {
    printf("Entrez le jour, le mois et l'année (séparés par des espaces) : ");
    struct Date date;
    scanf("%d %d %d", &date->jour, (int)&date->mois, &date->annee);
    return date;
}