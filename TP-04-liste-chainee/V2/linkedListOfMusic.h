#pragma once
#include <stdbool.h>

// Structure pour représenter une musique
typedef struct {
    char* name;
    char* artist;
    char* album;
    char* genre;
    int discNumber;
    int trackNumber;
    int year;
} Element;

struct cellule_s {
    Element val;
    struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;



void trierParAnnee(Liste l);

bool estVide(Liste l);
Liste creer(Element v);
Liste ajoutTete(Element v, Liste l);
extern void afficheElement(Element e);
void afficheListe_i(Liste l);
void afficheListe_r(Liste l);
extern void detruireElement(Element e);
void detruire_i(Liste l);
void detruire_r(Liste l);
Liste ajoutFin_i(Element v, Liste l);
Liste ajoutFin_r(Element v, Liste l);
extern bool equalsElement(Element e1, Element e2);
Liste cherche_i(Element v, Liste l);
Liste cherche_r(Element v, Liste l);
Liste retirePremier_i(Element v, Liste l);
Liste retirePremier_r(Element v, Liste l);
void afficheEnvers_r(Liste l);
